#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts node as
 *                      the right-child of another node
 * @parent: pointer to the node to insert the right child in
 * @value: value to store in the new node
 * Return: returns a pointer to the created node or
 *          NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (!parent)
	{
		return (NULL);
	}

	if (parent->right)
	{
		binary_tree_t *new_node = binary_tree_node(parent, value);

		if (!new_node)
		{
			return (NULL);
		}

		new_node->right = parent->right;
		parent->right->parent = new_node;

		parent->right = new_node;
	}
	else
	{
		parent->right = binary_tree_node(parent, value);
	}

	return (parent->right);
}
