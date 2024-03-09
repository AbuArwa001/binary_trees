#include "binary_trees.h"
/**
 * insert_bst - a function that inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: return a pointer to the created node, or NULL on failure
 *
*/
bst_t *insert_bst(bst_t **tree, int value)
{
	bst_t *node = NULL;

	if (!(*tree))
	{
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
		{
			node = insert_bst(&((*tree)->left), value);
		}
		else
		{
			node = binary_tree_node((*tree), value);
			(*tree)->left = node;
			return (node);
		}
	}
	else
		if (value > (*tree)->n)
		{
			if ((*tree)->right)
			{
				node = insert_bst(&((*tree)->right), value);
			}
			else
			{
				node = binary_tree_node((*tree), value);
				(*tree)->right = node;
				return (node);
			}
		}

	return (node);
}
/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: return a pointer to the created node, or NULL on failure
 *
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL;

	if (!(*tree))
	{
		node = binary_tree_node(NULL, value);
		*tree = node;
		return (node);
	}

	node = insert_bst(tree, value);
	return (node != NULL ? node : NULL);
}
