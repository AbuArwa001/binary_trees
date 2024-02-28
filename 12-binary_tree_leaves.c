#include "binary_trees.h"

/**
 * binary_tree_leaves -  a function  that counts the leavs in a binary tree
 * @tree: a pointer to the root node of the tree to count
 * Return: retunrs 0 if NULL else number of leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		size_t num = binary_tree_leaves(tree->left);

		count += num;
	}

	if (tree->right)
	{
		size_t num = binary_tree_leaves(tree->right);

		count += num;
	}

	if (!tree->right && !tree->left)
	{
		return (1);
	}

	return (count);
}
