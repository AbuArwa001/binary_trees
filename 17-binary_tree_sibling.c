#include "binary_trees.h"
#include "15-binary_tree_is_full.c"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node:  a pointer to the node to find the sibling
 * Return:  return a pointer to the sibling node
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
	{
		return (NULL);
	}

	if (node->parent)
	{
		if (node->parent->left == node)
		{
			return (node->parent->right);
		}
		else
		{
			return (node->parent->left);
		}

	}

	return (NULL);
}
