#include "binary_trees.h"
#include <limits.h>
/**
 * is_bst - check recursively if is binary search tree
 * @tree: tree to check
 * @min: the minimum value that a node in the tree can have
 * @max: the maximum value that a node in the tree can have
 * Return: returns 1 if true 0 if false;
*/
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
	{
		return (1);
	}

	if (tree->n < min || tree->n > max)
	{
		return (0);
	}

	return (is_bst(tree->left, min, tree->n - 1) &&
is_bst(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: tree to be checked
 * Return: returns 1 if true 0 if false;
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (is_bst(tree, INT_MIN, INT_MAX));
}
