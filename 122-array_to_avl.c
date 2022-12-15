#include "binary_trees.h"

/**
 * array_to_avl -function that builds an AVL Tree from an array
 * @size: number of elements in the array
 * @array: pointer to the first element of the array to be converted
 * Return: pointer to the root node of the created AVL, or NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;

	avl_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
