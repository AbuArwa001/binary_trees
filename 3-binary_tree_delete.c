#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_delete - Deletes  an entir binary tree
 * @tree: a pointer to the root node of the tree
 * Return: return NULL
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
	{
		return;
	}
	else
	{
		if (tree->left)
		{
			binary_tree_delete(tree->left);
		}

		if (tree->right)
		{
			binary_tree_delete(tree->right);
		}
		free(tree);
		tree = NULL;
	}
}
