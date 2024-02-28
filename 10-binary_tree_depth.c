#include "binary_trees.h"
/**
 * max_depth - measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the deth
 * Return: depth of the node
*/
size_t max_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
	{
		return (0);
	}

	depth = max_depth(tree->parent);
	return (depth + 1);
}
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the deth
 * Return: depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dp = 0;

	if (!tree)
	{
		return (0);
	}

	dp = max_depth(tree);
	return (dp - 1);
}
