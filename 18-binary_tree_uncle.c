#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: the node to find it's uncle
 * Return: pointer to the uncle, or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandma;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->parent == NULL)
		return (NULL);

	grandma = node->parent->parent;
	if (grandma->right == node->parent)
		return (grandma->left);
	else
		return (grandma->right);
}
