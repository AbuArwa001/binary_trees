#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_insert_left - a function that inserts a
 *   node as the left-child of another node
 * @parent: a pointer to the node to insert the lef-child in
 * @value: the value to store in the new node
 * Return: return a pointer to the created node  or NULL
 *          on failure
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (!parent)
	{
		return (NULL);
	}

	if (parent->left)
	{
		binary_tree_t *new_node = binary_tree_node(parent, value);

		if (!new_node)
		{
			return (NULL);
		}

		new_node->left = parent->left;
		parent->left->parent = new_node;

		parent->left = new_node;
	}
	else
	{
		parent->left = binary_tree_node(parent, value);
	}

	return (parent->left);
}
