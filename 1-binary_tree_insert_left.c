#include "binary_trees.h"

/**
 * binary_tree_insert_left - insterts a node as the left-child of another node
 * @parent: pointer to the node to insert left-child into
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
	{
		return (NULL);
	}

	if (parent->left == NULL)
		parent->left = binary_tree_node(parent, value);
	else
	{
		new = binary_tree_node(parent, value);
		new->left = parent->left;
		new->left->parent = new;
		parent->left = new;
	}
	return (new);
}
