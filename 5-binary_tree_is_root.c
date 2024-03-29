#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_is_root -  checks if a node is a root
 * @node: Pointer to the node to check
 * Return: return 1 if node is leaf otherwise 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}

	if (node->parent)
	{
		return (0);
	}
	else
	{
		return (1);
	}

}
