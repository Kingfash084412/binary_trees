#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation on a
 * binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp1, *temp2;

	if (tree == NULL)
		return (tree);

	temp1 = tree->left;
	temp2 = tree->parent;

	tree->left = temp1->right;

	if (temp1->right != NULL)
		temp1->right->parent = tree;

	temp1->right = tree;

	tree->parent = temp1;

	temp1->parent = temp2;

	if (temp2 != NULL)
	{
		if (temp2->right == tree)
			temp2->right = temp1;

		else
			temp2->left = temp1;
	}

	return (temp1);

}
