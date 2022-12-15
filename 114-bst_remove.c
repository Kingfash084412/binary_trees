#include "binary_trees.h"

/**
 * findmin - helper function that returns the smallest node from a tree
 * @node: BST tree to be searched
 * Return: Pointer to the node of smallest value
 */

bst_t *findmin(bst_t *node)
{

	bst_t *temp;

	temp = node;

	if (node == NULL)
		return (NULL);

	while (temp->left != NULL)
		temp = temp->left;

	return (temp);
}

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: root node of BST
 * @value: value of node to be deleted
 * https://www.youtube.com/watch?v=gcULXE7ViZw
 * Return: pointer to the new root node of the tree after removing the
 * desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (root);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL || root->right == NULL)
		{
			temp = root;
			if (root->left)
				root = root->left;
			else if (root->right)
				root = root->right;

			if (temp->parent->left == temp)
				temp->parent->left = root;
			else
				temp->parent->right = root;
			root->parent = temp->parent;
			free(temp);
		}
		else
		{
			temp = findmin(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
