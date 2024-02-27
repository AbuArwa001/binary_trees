#include "binary_trees.h"
/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each mode
*/

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}
	else
	{
		if (tree->left)
		{
			binary_tree_inorder(tree->left, func);
		}

		func(tree->n);

		if (tree->right)
		{
			binary_tree_inorder(tree->right, func);
		}
	}
}
