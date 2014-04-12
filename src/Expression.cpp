//
//  Expression.cpp
//  COP-3503-Project
//
//  Created by Justin on 4/12/14.
//
//

#include "Expression.h"

/**
 * Constructor
 */
Expression::Expression()
{
	// Initilize the pointers to null
	this->left = nullptr;
	this->right = nullptr;
	
	// Initilize the operation to the null character
	op = '\0';
}


/**
 * Destructor
 */
Expression::~Expression()
{
	// Call the destructor on both the left and right sides.
	delete this->left;
	delete this->right;
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
