#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node whose depth to measure
 * Return: size_t depth from root node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = 0;

	while (tree->parent)
	{
		tree = tree->parent;
		depth += 1;
	}
	return (depth);
}
