#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the ancestor, or NULL if no such node exists
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *cousin1, *cousin2, **c1_ancestors;
	int h, i;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	cousin1 = (binary_tree_t *)first;
	cousin2 = (binary_tree_t *)second;
	/* Create an array of all first's parents */
	for (h = 0; cousin1; h++)
		cousin1 = cousin1->parent;
	c1_ancestors = malloc(sizeof(binary_tree_t *) * h);
	if (c1_ancestors == NULL)
		return (NULL);
	cousin1 = (binary_tree_t *)first;
	for (i = 0; i < h; i++)
	{
		c1_ancestors[i] = cousin1;
		cousin1 = cousin1->parent;
	}
	/* Compares cousin2's parents to array */
	while (cousin2)
	{
		for (i = 0; i < h; i++)
		{
			if (cousin2 == c1_ancestors[i])
			{
				free(c1_ancestors);
				return (cousin2);
			}
		}
		cousin2 = cousin2->parent;
	}
	free(c1_ancestors);
	return (NULL);
}
