#include "binary_trees.h"

/**
 * convert2 - function that ids nodes of a binary tree
 * @num: unsigned long int of number to be converted to binary string
 * @base: int of base 2
 * http://www.firmcodes.com/write-printf-function-c/
 * Return: Char pointer of binary string for number passed
 */

char *convert2(unsigned long int num, int base)
{
	static char *rep;
	static char buffer[33];
	char *ptr;

	rep = "0123456789";
	ptr = &buffer[32];
	*ptr = 0;
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
}

/**
 * binary_tree_size2 - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size of tree of type size_t, 0 if tree is NULL
 */

size_t binary_tree_size2(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size += binary_tree_size2(tree->left);
	size += binary_tree_size2(tree->right);
	++size;

	return (size);
}

/**
 * trickle_down - function that ensures subtrees maintain max heap property
 * by heapifying from root downward
 * @node: heap_t node to be moved in tree as needed in order to preserve
 * max heap
 * http://www.crazyforcode.com/heap-data-structure/
 * https://ocw.mit.edu/courses/electrical-engineering-and-computer-science
 * /6-006-introduction-to-algorithms-fall-2011/lecture-videos/
 * /MIT6_006F11_lec04.pdf
 * Return: returns newly created heap_t node after heapify process
 */

heap_t *trickle_down(heap_t *node)
{
	heap_t *temp;
		int value;
	temp = node;

	if (temp->left == NULL && temp->right == NULL)
		return (NULL);

	if (temp->left && temp->n > temp->left->n && temp->right == NULL)
		return (NULL);

	if (temp->left && temp->n < temp->left->n &&
	    (!temp->right || temp->left->n > temp->right->n))
	{
		value = temp->n;
		temp->n = temp->left->n;
		temp->left->n = value;
		temp = temp->left;
		return (trickle_down(temp));
	}

	if (temp->right && temp->n < temp->right->n &&
	    (!temp->left || temp->right->n > temp->left->n))
	{

		value = temp->n;
		temp->n = temp->right->n;
		temp->right->n = value;
		temp = temp->right;
		return (trickle_down(temp));
	}
	return (NULL);
}


/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * Return: 0 on failure
 */

int heap_extract(heap_t **root)
{
	char *ptr;
	heap_t *temp;
	unsigned long int i;
	size_t size;
	int extracted;

	if (root == NULL || *root == NULL)
		return (0);

	temp = *root;
	size =  binary_tree_size2(temp);
	ptr = convert2(size, 2);

	for (i = 1; i < strlen(ptr) - 1; ++i)
		if (ptr[i] == '1')
			temp = temp->right;
		else
			temp = temp->left;

	extracted = (*root)->n;

	if (size == 1)
		return (*root = (free(*root), NULL), extracted);

	if (ptr[i] == '1')
	{
		(*root)->n = temp->right->n;
		temp->right = (free(temp->right), NULL);
		trickle_down(*root);
		return (extracted);
	}
	else
	{
		(*root)->n = temp->left->n;
		temp->left = (free(temp->left), NULL);
		trickle_down(*root);
		return (extracted);
	}
	return (0);
}
