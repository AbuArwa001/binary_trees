#include "binary_trees.h"
/**
 * tree_size - Measurs the size of a binary tree
 * @tree: A pointer to root node to be measured
 * Return: NUmber of nodes;
*/
size_t tree_size(const binary_tree_t *tree)
{
	size_t sum = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		size_t left = tree_size(tree->left);

		left += 1;
		sum += left;
	}

	if (tree->right)
	{
		size_t right = tree_size(tree->right);

		right += 1;
		sum += right;
	}

	return (sum);
}
/**
 * binary_tree_size - Measurs the size of a binary tree
 * @tree: A pointer to root node to be measured
 * Return: size of the tree;
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_siz = 0;

	if (!tree)
	{
		return (0);
	}

	tree_siz = tree_size(tree);

	return (tree_siz + 1);
}
