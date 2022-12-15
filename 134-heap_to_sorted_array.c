#include "binary_trees.h"

/**
 * tree_size - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size of tree of type size_t, 0 if tree is NULL
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size += tree_size(tree->left);

	size += tree_size(tree->right);

	++size;

	return (size);
}

/**
 * heap_to_sorted_array - function that converts a Binary Max Heap to a sorted
 * array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: int array sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted;
	size_t i;
	size_t *length = size;

	if (heap == NULL)
		return (NULL);

	*length = tree_size(heap);

	sorted  = malloc(sizeof(int) * (*length));

	for (i = 0; i < *length; i++)
		sorted[i] = heap_extract(&heap);

	return (sorted);
}
