#include "binary_trees.h"

/**
 * findmin - helper function that returns the smallest node from a tree
 * @node: AVL tree to be searched
 * Return: Pointer to the node of smallest value
 */

avl_t *findmin(avl_t *node)
{
	avl_t *current = node;

	if (node == NULL)
		return (NULL);

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * rebalancer - helper func that rebalances the node given as needed per the
 * properties of an AVL tree
 * @root: node to be possibly rebalanced
 * @bal: int of current balance factor of node
 * Return: Pointer to rebalanced node
 */

avl_t *rebalancer(avl_t *root, int bal)
{
	if (bal > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));

	if (bal > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left =  binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (bal < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));

	if (bal < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}

/**
 * avl_remove - function that removes a node from an AVL tree
 * https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value, and after rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	int bal;

	if (root == NULL)
		return (root);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
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
			root = root->left ? root->left : root->right;
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
			root->right = avl_remove(root->right, temp->n);
		}
	}
	if (root == NULL)
		return (root);
	bal = binary_tree_balance(root);
	return (rebalancer(root, bal));
}
