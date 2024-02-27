#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_preorder - goes through binary tree using pre-order
 * @tree: pointer to the root node of the tree to travers
 * @func: is a pointer to a function to call for each node
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}
	else
	{
		func(tree->n);

		if (tree->left)
		{
			binary_tree_preorder(tree->left, func);
		}

		if (tree->right)
		{
			binary_tree_preorder(tree->right, func);
		}
	}
}
