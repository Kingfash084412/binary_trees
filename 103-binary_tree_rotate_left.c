#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a left-rotation on a binary
 * tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *temp1, *temp2;

	if (tree == NULL)
		return (tree);

	temp1 = tree->right;
	temp2 = tree->parent;

	tree->right = temp1->left;

	if (temp1->left != NULL)
		temp1->left->parent = tree;

	temp1->left = tree;

	tree->parent = temp1;

	temp1->parent = temp2;

	if (temp2 != NULL)
	{
		if (temp2->left == tree)
			temp2->left = temp1;

		else
			temp2->right = temp1;
	}

	return (temp1);
}
