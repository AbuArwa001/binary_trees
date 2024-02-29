#include "binary_trees.h"
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
 * printCurrentLevel - prints current level
 * @tree: pointer to node of subtree
 * @level: current level
 * @func: function pointer to print function
*/
void printCurrentLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else
		if (level > 1)
		{
			printCurrentLevel(tree->left, level - 1, func);
			printCurrentLevel(tree->right, level - 1, func);
		}
}
/**
 * printLevelOrder - Function to print level order traversal a tree
 * @tree: pointer to node of subtree
 * @func: function pointer to print function
*/
void printLevelOrder(const binary_tree_t *tree, void (*func)(int))
{
	int h = max_depth(tree);
	int i;

	for (i = 1; i <= h; i++)
		printCurrentLevel(tree, i, func);
}
/**
 * binary_tree_levelorder -  the lowest common ancestor of two nodes
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}

	printLevelOrder(tree, func);
}
