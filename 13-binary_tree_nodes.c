#include "binary_trees.h"
#include "4-binary_tree_is_leaf.c"

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

	if (tree->left || tree->right)
	{
		sum += 1;
	}

	sum += tree_size(tree->left);
	sum += tree_size(tree->right);

	return (sum);
}
/**
 * binary_tree_nodes - Function that counts the nodes withat leaas 1 child
 * @tree: A pointer to the root node of the tree
 * Return: returns number of nodes with children
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (tree_size(tree));
}
