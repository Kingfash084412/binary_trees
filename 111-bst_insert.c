#include "binary_trees.h"

/**
 * bst_insert2 - helper func for bst_insert. Inserts a value in a Binary Search
 * Tree if initial tree is not NULL
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * @ret: pointer that stores the last return value from initial call of
 * bst_insert func
 * Return: pointer to the created node, or NULL on failure
 */

bst_t *bst_insert2(bst_t **tree, int value, bst_t **ret)
{
	bst_t *l, *r;

	if (*tree == NULL)
	{
		l = binary_tree_node(*tree, value);
		*tree = l;
		*ret = l;
		return (l);
	}

	else if ((*tree)->n > value)
	{
		l = bst_insert2(&((*tree)->left), value, ret);
		(*tree)->left = l;
		l->parent = *tree;
	}

	else if ((*tree)->n < value)
	{
		r = bst_insert2(&((*tree)->right), value, ret);
		(*tree)->right = r;
		r->parent = *tree;
	}

	return (*tree);
}

/**
 * bst_insert - Inserts a value in a Binary Search
 * Tree if initial tree is NULL, otherwise calls on helper func to add the node
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *l = NULL;

	bst_insert2(tree, value, &l);

	return (l);
}
