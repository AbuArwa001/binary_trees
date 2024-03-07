#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotates node to the left
 * @tree: sub tree to be rotated
 * Return: returns the parent node of the tree rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node = NULL;

	if (!tree || !tree->right)
	{
		return (NULL);
	}

	node = tree->right;

	tree->right = node->left;

	if (node->left)
	{
		node->left->parent = tree;
	}

	node->left = tree;
	node->parent = tree->parent;
	tree->parent = node;
	return (node);
}
