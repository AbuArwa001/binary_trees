#include "binary_trees.h"
/**
 * binary_tree_levelorder -  the lowest common ancestor of two nodes
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}


}
