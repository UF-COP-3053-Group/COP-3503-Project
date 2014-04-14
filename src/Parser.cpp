//
//  Parser.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#include "Parser.h"

/**
 * Adds a completed node to the expression stack with the given operator
 */
void addNode(stack<Expression*> &stack, Operator op)
{
	Expression* rightNode = stack.top();
	stack.pop();
	Expression* leftNode = stack.top();
	stack.pop();
	stack.push(new Expression(op, leftNode, rightNode));
}

Expression* Parser::createAST(vector<Token> tokens)
{
	// Create the needed stacks
	stack<Operator> operatorStack;
	stack<Expression*> expressionStack;
	
	// Loop through the whole vector of tokens
	// For simplicity, we use a GOTO label, since breaking or refactoring nested loops isn't so simple in C++
	Label_MainLoop:
	for (int i = 0; i < tokens.size(); i++)
	{
		// Assign the current token
		Token token = tokens[i];
		
		// If the token is a left parenthesis
		if ( token.isLeftParen() )
		{
			// Push it onto the stack as an operator
			operatorStack.push( Operator('(', 5, false) );
		}
		// Else if it's a right parenthesis
		else if ( token.isRightParen() )
		{
			// Loop backwards through the stack
			Operator popOp;
			while ( !operatorStack.empty() )
			{
				// Pop off the top operator
				popOp = operatorStack.top();
				operatorStack.pop();
				
				// Check if it's the matching paren
				if( popOp.getSymbol() == '(' )
				{
					// Continue the outer for loop if it is
					goto Label_MainLoop;
				}
				// Otherwise, add a node from the inner expression and loop again
				else
				{
					addNode(expressionStack, popOp);
				}
			}
			
			// If we get here, the stack has emptied before we found the matching paren, which is bad.
			throw runtime_error("Missing a \')\' in the expression");
		}
		// Default case
		else
		{
			// If the token is an operator, decide what to do with it
			if ( token.isOperator() )
			{
				Operator o1 = token.op;
				Operator o2;
				while( !operatorStack.empty() ) // Not needed?? -> && operatorStack.top() != null
				{
					// Define o2 as the top of the stack
					o2 = operatorStack.top();
					
					// If o1 is right assoc and has the same precedence as the last op, or o1 has lower precedence
					if ((!o1.isRightAssoc() && o1.comparePrecedence(o2) == 0) || o1.comparePrecedence(o2) < 0)
					{
						operatorStack.pop();
						addNode(expressionStack, o2);
					}
					else
					{
						break;
					}
				}
				// Push this operator onto the stack
				operatorStack.push( token.op );
			}
			// Otherwise, if it's a number
			else if ( token.isNumber() )
			{
				expressionStack.push( new Expression( token.number ) );
			}
			// The token should have been an operator or a number. How'd we get here? Throw an error
			else
			{
				throw runtime_error("Error in building the AST. Invalid Token.");
			}
		}
	// End for loop
	}
	
	// Finish adding nodes
	while(!operatorStack.empty())
	{
		addNode(expressionStack, operatorStack.top());
		operatorStack.pop();
	}
	
	// Will this work? Only testing will tell
	return expressionStack.top();
}


/**
 * Takes in an input string and turns it into a vector of tokens readable
 * by the createAST() function.
 */
vector<Token> Parser::tokenize(string input)
{
    string buf; // Have a buffer string
    stringstream ss(input); // Insert the string into a stream
    
    vector<string> fragments; // Create vector to hold our words
    
    while (ss >> buf)
        fragments.push_back(buf);
    
    vector<Token> tokens;
    char first;
    bool negate;
    while (!fragments.empty()) {
        if (fragments.at(0).find_last_not_of("0123456789./-+* ^epilog_sqrt:") != -1) {
            throw "Invalid input detected";
        }
        negate = false;
        first = fragments.at(0).front();
        if (first=='(') {
            Token result = Token('(');
            tokens.push_back(result);
        }
        else if (first==')'){
            Token result = Token(')');
            tokens.push_back(result);
        }
        else if (first=='^'){
            Token result = Token(Operator('^', 4, true));
            tokens.push_back(result);
        }
        else if (first=='*'){
            Token result = Token(Operator('*', 3, false));
            tokens.push_back(result);
        }
        else if (first=='/'){
            Token result = Token(Operator('/', 3, false));
            tokens.push_back(result);
        }
        else if (first=='+'){
            Token result = Token(Operator('+', 2, false));
            tokens.push_back(result);
        }
        else if (first=='-' && fragments.at(0).length() < 2){
            Token result = Token(Operator('-', 2, false));
            tokens.push_back(result);
        }
        //negation operator, not subtraction
        else if (first=='-' && fragments.at(0).length() <= 2){
            negate = true;
			// Erase first character of the string
            fragments.at(0).erase(0);
			tokens.push_back( Token(createNumber(fragments.at(0), first)) );
        }
        else
		{
            tokens.push_back( Token(createNumber(fragments.at(0), first)) );
		}
		
        fragments.erase(fragments.begin());
    }
	/*
	Token yes = Token( createNumber("0", '0') );
    tokens.push_back(yes);
	
	Token no = tokens.back();*/
    return tokens;
}


Number* Parser::createNumber(string number, char first){
    Number* result;
    //This is probably lazy/ bad, but it basically makes sure that theres no junk before the actual operation.
    if (first != 's' && (int)number.find("rt:") > 0){
        string base (number.find(':')+1, -1);
        string radicand (0, number.find('r')-1);
        result = new Radical(createNumber(base, base.front()), createNumber(radicand, radicand.front()));
    }
    else if (first=='p' && number.at(1) =='i' && number.length() == 2){
        //create pi
        result = new Constant("pi");
    }
    else if (first=='e' && number.length() == 1){
        //create e
        result = new Constant("e");
    }
    else if (first == 's' && (int)number.find("sqrt:") > 0){
        //create a square root
        string base (number.find(':')+1, -1);
        result = new Radical(createNumber(base, base.front()), new Integer(2));
    }
    else if (first == 'l' && (int)number.find("log_") > 0){
        //create a log
        string base (number.find('_')+1, number.find(':'));
        string arg (number.find(':')+1, -1);
        result = new Log(createNumber(base, base.front()), createNumber(arg, arg.front()));
    }
    //all numbers are created here
    else if (isdigit(first) && (int)number.find_last_not_of("0123456789./") != -1){
        //find a '/' to create a fraction
        if((int)number.find_first_of('/') > 0){
            //check to make sure there is only one '/' in the fraction
            if ((int)number.find_first_of('/') != (int)number.find_last_of('/')) {
                //temporary error handling
                throw "Only one / per fracton";
            }
            //create a rational
            string numerator (0, number.find('/')-1);
            string denom ( number.find('/') + 1, -1);
            result = new Rational(createNumber(numerator, numerator.front()), createNumber(denom, denom.front()));
        }
        if((int)number.find_first_of('.') > 0){
            if ((int)number.find_first_of('.') != (int)number.find_last_of('.')){
                throw "Only one . per decimal";
            }
            //create a rational from a decimal
            
            result = new Rational(number);
        }
        //finally, create an integer
        result = new Integer(atoi(number.c_str()));
    }

    return result;
}