#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * max_depth - finds the max depth of each subtree
 * @tree: pointer to node of subtree
 * Return: returns the max_depth
*/
size_t max_depth(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else
	{
		size_t lh = max_depth(tree->left);
		size_t rh = max_depth(tree->right);

		return (lh > rh ? (lh + 1) : (rh + 1));
	}
}
/**
 * binary_tree_height - Measures height of a binary tree.
 * @tree: pointer to the root node
 * Return: returns he max height
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
	{
		return (0);
	}

	height = max_depth(tree);
	return (height - 1);
}
