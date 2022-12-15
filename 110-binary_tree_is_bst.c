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
