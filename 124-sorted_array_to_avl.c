#include "binary_trees.h"

/**
 * sorted_array_to_avl2 - main function that adds nodes to create an AVL tree
 * @arr:  pointer to the array to be converted
 * @start: beginning index of type int for current recursion
 * @end: ending index of type int for current recursion
 * Return: pointer to the root node of the created AVL tree
 */

avl_t *sorted_array_to_avl2(int *arr, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;

	root = binary_tree_node(NULL, arr[mid]);

	root->left = sorted_array_to_avl2(arr, start, mid - 1);

	if (root->left)
		root->left->parent = root;

	root->right = sorted_array_to_avl2(arr, mid + 1, end);

	if (root->right)
		root->right->parent = root;

	return (root);
}


/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size:number of elements in the array
 * Return: pointer to the root node of the created AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node;

	if (size == 0)
		return (NULL);

	if (size == 1)
	{
		node = binary_tree_node(NULL, array[0]);
		return (node);
	}

	if (size == 2)
	{
		node = binary_tree_node(NULL, array[0]);
		node->right = binary_tree_node(node, array[1]);
		return (node);
	}

	node = sorted_array_to_avl2(array, 0, (int) size - 1);

	return (node);
}
