#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: parent node
 * @value: value of the current node
 *
 * Return:  a pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));
    if (!node)
    {
        return (NULL);
    }
    
	(*node).left = NULL;
	(*node).right = NULL;
	(*node).n = value;
	(*node).parent = parent;
	return (node);
}
