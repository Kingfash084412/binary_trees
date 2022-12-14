#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = binary_tree_left_max_depth(tree);
	return (tree_is_perfect_help(tree, depth, 0));
}

/**
 * tree_is_perfect_help - checks if a binary tree is perfect
 * @tree: pointer to the root
 * @depth: the max left-most depth of the tree from the root
 * @level: the current level we are checking
 * Return: 1 if perfect, 0 if not
 */
int tree_is_perfect_help(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (depth == level + 1);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (tree_is_perfect_help(tree->left, depth, level + 1) &&
		tree_is_perfect_help(tree->right, depth, level + 1));
}

/**
 * binary_tree_left_max_depth - finds the max depth of the left most branch
 * @tree: pointer to the root node
 * Return: the depth
 */
int binary_tree_left_max_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

