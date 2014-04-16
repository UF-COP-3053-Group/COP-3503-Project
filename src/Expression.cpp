//
//  Expression.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#include "Expression.h"

/**
 * Constructor for a leaf (number) node
 */
Expression::Expression(Number* num)
{
	// Initilize the pointers to null
	this->left = nullptr;
	this->right = nullptr;
	
	// Initilize the operation to the null operator
	this->op = Operator();
	
	// Initlize the number to num
	this->num = num;
}

/**
 * Constructor for operator nodes.
 */
Expression::Expression(Operator op, Expression* leftNode, Expression* rightNode)
{
	this->left = leftNode;
	this->right = rightNode;
	this->op = op;
	this->num = nullptr;
}


/**
 * Destructor
 */
Expression::~Expression()
{
	/* FIXME: I leak.
	// Call the destructor on both the left and right sides.
	if( this->left != nullptr)
		delete this->left;
	if( this->right != nullptr)
		delete this->right;
	if( this->num != nullptr)
		delete this->num;
	*/
}


/**
 * Returns the number stored by this class
 * Note: before calling this method, check that this is a number node with isNumber()
 */
Number* Expression::getNumber()
{
	return this->num;
}


/**
 * Returns the operator symbol for this node. Will return the null character ('\0') if not an operator
 */
char Expression::getOperatorSymbol()
{
	return this->op.getSymbol();
}


/**
 * Returns true if this expression node stores a number, false if not
 */
bool Expression::isNumber()
{
	// If both the left and right are null, it's a leaf node, AKA a number
	if (this->left == nullptr && this->right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
 * Recursively deletes the given expression tree, freeing memory to prevent memory leaks.
 * Does the same thing as the destructor, but can be called explicitly on any node.
 */
void Expression::deleteExpressionTree(Expression* node)
{
	// If the left node has an expression, delete it
	if (node->left != nullptr)
	{
		deleteExpressionTree(node->left);
	}
	
	// If the right node has an expression, delete it
	if (node->right != nullptr)
	{
		deleteExpressionTree(node->right);
	}
	
	// Finally, delete this node itself
	delete node;
}

/**
 * Retuns the left node of this tree
 */
Expression* Expression::getLeftNode()
{
	return this->left;
}


/**
 * Retuns the right node of this tree
 */
Expression* Expression::getRightNode()
{
	return this->right;
}


/**
 * Sets the left pointer of this node to the passes expression
 * Note: null pointers are specifically allowed to be inserted here
 */
void Expression::setLeft(Expression* newLeft)
{
	this->left = newLeft;
}


/**
 * Sets the left pointer of this node to the passes expression
 * Note: null pointers are specifically allowed to be inserted here
 */
void Expression::setRight(Expression* newRight)
{
	this->right = newRight;
}
