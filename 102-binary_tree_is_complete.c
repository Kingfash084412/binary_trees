#include "binary_trees.h"


/**
 * binary_tree_size_helper - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size of tree of type int, 0 if tree is NULL
 */

int binary_tree_size_helper(const binary_tree_t *tree)
{
	int size = 0;

	if (tree == NULL)
		return (0);

	size += binary_tree_size_helper(tree->left);

	size += binary_tree_size_helper(tree->right);

	++size;

	return (size);
}

/**
 * indexer - main driver function that returns whether a tree is complete
 * assuming tree is not NULL
 * @root: pointer to the root node of the tree to examine if complete or not
 * @i: int that helps assign an index to each node
 * @count: total number of nodes from original tree passed from main
 * Return: 1 if tree is complete, 0 otherwise
 */

int indexer(const binary_tree_t *root, int i, int count)
{
	if (root == NULL)
		return (1);

	if (i >= count)
		return (0);

	return (indexer(root->left, 2 * i + 1, count) == 1 &&
		indexer(root->right, 2 * i + 2, count) == 1);
}


/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count;

	if (tree == NULL)
		return (0);

	count = binary_tree_size_helper(tree);

	return (indexer(tree, 0, count));
}
