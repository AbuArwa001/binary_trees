#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate sub tree right
 * @tree: sub tree to be rotated
 * Return: return the new sub tree root
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node = NULL;

	if (!tree || !tree->left)
	{
		return (NULL);
	}

	node = tree->left;

	tree->left = node->right;

	if (node->right)
	{
		node->right->parent = tree;
	}

	node->right = tree;
	node->parent = tree->parent;
	tree->parent = node;
	return (node);
}
