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
		binary_tree_t *temp_node = malloc(sizeof(binary_tree_t));

		temp_node = parent->left;

		parent->left = binary_tree_node(parent, value);
		parent->left->left = binary_tree_node(parent->left, temp_node->n);
	}
	else
	{
		parent->left = binary_tree_node(parent, value);
	}

	if (!parent->left)
	{
		return (NULL);
	}

	return (parent->left);
}
