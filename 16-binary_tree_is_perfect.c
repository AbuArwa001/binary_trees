#include "binary_trees.h"
#include "15-binary_tree_is_full.c"
/**
 * is_perfect - checks if tree is perfect
 * @tree: pointer to node of subtree
 * @depth: depth of the leftmost subtree
 * @level: level of  the tree
 * Return: returns the max_depth
*/
int is_perfect(const binary_tree_t *tree, int depth, int level)
{

	if (tree == NULL)
		return (1);

	if (!tree->left  && !tree->right)
		return ((depth == level + 1) ? 1 : 0);


	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
	    is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree:  pointer to the root node of the tree to check
 * Return: returns 1 if true 0 if false
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;
	const binary_tree_t *node = tree;

	if (tree == NULL)
		return (1);
	while (node != NULL)
	{
		depth++;
		node = node->left;
	}

	return (is_perfect(tree, depth, 0));
}
