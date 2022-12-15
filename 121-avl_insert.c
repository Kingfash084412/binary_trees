#include "binary_trees.h"

/**
 * avl_rebalance - helper func that rebalances the AVL tree when needed
 * @tree: double pointer to the root node to be checked for rebalancing
 * @value: value to store in the node to be inserted
 * @bal: int for measure of the balance factor of the node given
 * Return: pointer to the created node, or tree otherwise
 */

avl_t *avl_rebalance(avl_t **tree, int bal, int value)
{
	if (bal > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);

	else if (bal < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);

	else if (bal > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}

	else if (bal < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert2 - helper function that assigns and rebalances nodes for AVL tree
 * @tree: double pointer to the root node of the AVL tree to insert the value
 * @value: value to store in the node to be inserted
 * @ret: pointer that stores the last return value from initial call of
 * avl_insert func
 * Return: pointer to the created node, or NULL on failure
 */

avl_t *avl_insert2(avl_t **tree, int value, avl_t **ret)
{
	int bal;

	avl_t *l, *r;

	if (*tree == NULL)
	{
		l = binary_tree_node(*tree, value);
		*tree = l;
		*ret = l;
		return (l);
	}

	if (value > (*tree)->n)
	{
		r = avl_insert2(&(*tree)->right, value, ret);
		(*tree)->right = r;
		r->parent = *tree;
	}

	else if (value < (*tree)->n)
	{
		l = avl_insert2(&(*tree)->left, value, ret);
		(*tree)->left = l;
		l->parent = *tree;
	}

	bal = binary_tree_balance(*tree);

	*tree = avl_rebalance(tree, bal, value);

	return (*tree);
}

/**
 * avl_insert - function that inserts a value in an AVL Tree
 * Tree if initial tree is NULL, otherwise calls on helper func to add the node
 * @tree: double pointer to the root node of the AVL tree to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *l = NULL;

	avl_insert2(tree, value, &l);

	return (l);
}
