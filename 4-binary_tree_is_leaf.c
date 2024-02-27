#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_is_leaf -  checks if a node is a leaf
 * @node: Pointer to the node to check
 * Return: return 1 if node is leaf otherwise 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}

	if (node->left || node->right)
	{
		return (0);
	}
	else
	{
		return (1);
	}

}
