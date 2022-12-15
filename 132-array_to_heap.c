#include "binary_trees.h"

/**
 * array_to_heap - function that builds a Max Binary Heap tree from an array
 * @size: number of elements in the array
 * @array: pointer to the first element of the array to be converted
 * Return: pointer to the root node of the created binary heap, NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;

	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
