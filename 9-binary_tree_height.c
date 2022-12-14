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

	if (leftheight > rightheight)
		return (leftheight + 1);
	else
		return (rightheight + 1);
}
