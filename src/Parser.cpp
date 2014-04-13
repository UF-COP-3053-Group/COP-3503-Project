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
void addNode(stack<Expression*> stack, char op)
{
	Expression* rightNode = stack.top();
	stack.pop();
	Expression* leftNode = stack.top();
	stack.pop();
	stack.push(new Expression(op, leftNode, rightNode));
}

Expression* Parser::createAST(string input)
{
	// Create the needed stacks
	stack<char> operatorStack;
	stack<Expression*> expressionStack;
	
	// Loop through the whole input string
	// For simplicity, we use a GOTO label, since breaking or refactoring nested loops isn't so simple in C++
	Label_MainLoop:
	for (int i = 0; i < input.length(); i++)
	{
		// Assign the current character
		char c = input[i];
		
		// Switch the character, looking for an operator
		switch (c)
		{
			case ' ':
				break;
			
			case '(':
				operatorStack.push('(');
				break;
			
			case ')':
				// Loop until we empty the stack between the parenthesis
				char popOp;
				while( !operatorStack.empty() )
				{
					// Pop off the top operator
					popOp = operatorStack.top();
					operatorStack.pop();
					
					// Check it
					if( '(' == popOp )
					{
						// Continuet the outer for loop
						goto Label_MainLoop;
					}
					else
					{
						addNode(expressionStack, popOp);
					}
				}
				throw runtime_error("Missing a \')\' in the expression");
				break;
			
			default:
				
				break;
		}
		
	}
	
	// Just so this builds right now
	return nullptr;
}


/**
 * Takes in an input string and turns it into a vector of tokens readable
 * by the createAST() function.
 */
vector<Token> Parser::tokenize(string input)
{
	
}
