#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert right-child into
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		parent->right = binary_tree_node(parent, value);
		return (parent->right);
	}

	else
	{
		new = binary_tree_node(parent, value);
		new->right = parent->right;
		parent->right = new;
		new->right->parent = new;
	}

	return (new);

}
