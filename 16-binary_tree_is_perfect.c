#include "binary_trees.h"
#include "15-binary_tree_is_full.c"
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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree:  pointer to the root node of the tree to check
 * Return: returns 1 if true 0 if false
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
	{
		return (0);
	}

	left = max_depth(tree->left);
	right = max_depth(tree->right);
	return (left - right == 0 && binary_tree_is_full(tree) ? 1 : 0);
}
