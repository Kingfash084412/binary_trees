#include "binary_trees.h"


/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root of the tree to be checked
 * Return: 1 if valid, 0 if not.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bt_is_bst_helper((binary_tree_t *)tree, INT_MIN, INT_MAX));
}

/**
 * bt_is_bst_helper - checks a binary tree is a valid BST
 * @node: pointer to the tree to be checked
 * @min: the min value a node can be
 * @max: the max value a node can be
 * Return: 1 if valid, 0 otherwise
 */
int bt_is_bst_helper(binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (bt_is_bst_helper(node->left, min, node->n - 1) &&
		bt_is_bst_helper(node->right, node->n + 1, max));
}


/**
 * height - returns height of a node
 * @tree: binary_tree_t node to search
 * Return: Height as an int, 0 if NULL
 */

int height(binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	if (height(tree->left) >= height(tree->right))
		return (height(tree->left) + 1);

	return (1 + height(tree->right));
}

/**
 * binary_tree_is_avl2 - function that returns whether a tree is AVL
 * assuming the first root passed from main is not NULL
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is aVL, 0 otherwise
 */

int binary_tree_is_avl2(const binary_tree_t *tree)
{
	int LH, RH;

	if (tree == NULL)
		return (1);

	LH = height(tree->left);

	RH = height(tree->right);

	if (abs(LH - RH) <= 1 && binary_tree_is_avl2(tree->left) != 0 &&
	    binary_tree_is_avl2(tree->right) != 0
	    && binary_tree_is_bst(tree) != 0)
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl - function that returns whether a tree is AVL
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is aVL, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl2(tree));
}
