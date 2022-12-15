#include "binary_trees.h"

/**
 * array_to_bst -function that builds a Binary Search Tree from an array
 * @size: number of elements in the array
 * @array: pointer to the first element of the array to be converted
 * Return: pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;

	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
