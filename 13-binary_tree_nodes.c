#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count
 * Return: size_t number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t dads;

	if (tree == NULL)
		return (0);

	dads = 0;
	if (tree->left || tree->right)
		dads += 1;

	dads += binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);

	return (dads);
}
