#include "binary_trees.h"
/**
 * tree_full - check if tree is full
 * @tree: A pointer to root node to be measured
 * Return: NUmber of nodes;
*/
size_t tree_full(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (1);
	}

	if ((tree->left && !tree->right) || (!tree->left && tree->right))
	{
		return (0);
	}

	return (tree_full(tree->left) && tree_full(tree->right));
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: Return 1 if true otherwise return 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (tree_full(tree));
}
