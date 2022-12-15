#include "binary_trees.h"
/**
 * binary_tree_height - determine the height of the tree
 * @tree: tree of nodes
 * Return: height of tree or NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftheight, rightheight;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	leftheight = binary_tree_height(tree->left);
	rightheight = binary_tree_height(tree->right);

	if (leftheight < rightheight)
		return (leftheight + 1);
	else
		return (rightheight + 1);
}

/**
 * print - prints the level where you are at.
 * @tree: the input root address
 * @func: input func address
 * @level: height of node to be printed
 */
void print(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		print(tree->left, func, level - 1);
		print(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 * @tree: the input root address
 * @func: input func address
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i = 1;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree) + 1;

	while (i <= height)
	{
		print(tree, func, i);
		i++;
	}
}
