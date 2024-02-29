#include "binary_trees.h"
#include "17-binary_tree_sibling.c"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node:  a pointer to the node to find the uncle
 * Return:  return a pointer to the uncle node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (!node)
	{
		return (NULL);
	}

	if (node->parent)
	{
		uncle = binary_tree_sibling(node->parent);

		if (uncle)
		{
			return (uncle);
		}

	}

	return (NULL);
}
