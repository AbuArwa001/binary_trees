#include "binary_trees.h"
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
 * binary_tree_balance - Measurs the balance factor of binary tree
 * @tree: pointer to the root node of the tree
 * Return: Te balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
	{
		return (0);
	}

	left = max_depth(tree->left);
	right = max_depth(tree->right);
	return (left - right);
}
