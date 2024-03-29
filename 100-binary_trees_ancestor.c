#include "binary_trees.h"
#include "10-binary_tree_depth.c"

/**
 * adjust_to_same_depth - Adjusts the deeper node
 *						to the same depth as the other node.
 * Description: If two nodes are at different depths,
 *				this function moves the deeper
 * node up its ancestor chain untl it reaches the same depth as the other node
 * @deeper_node: A pointer to the pointer of the deeper node to be adjusted.
 * @deeper_depth: A pointer to the depth of the deeper node to be adjusted.
 * @target_depth: The target depth to adjust the deeper node to.
 */
void adjust_to_same_depth(const binary_tree_t **deeper_node,
		size_t *deeper_depth, size_t target_depth)
{
	while (*deeper_depth > target_depth)
	{
		*deeper_node = (*deeper_node)->parent;
		(*deeper_depth)--;
	}
}

/**
 * binary_trees_ancestor -  the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: n a pointer to the lowest
 *          common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t fst = 0, scnd = 0;

	if (!first || !second)
	{
		return (NULL);
	}

	fst = binary_tree_depth(first);
	scnd = binary_tree_depth(second);

/*Adjust the deeper node to the same depth as the other node*/
	adjust_to_same_depth(&first, &fst, scnd);
	adjust_to_same_depth(&second, &scnd, fst);

    /* Loop until the nodes are equal or null */
	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

    /* Return the common ancestor or null */
	return ((binary_tree_t *)first);
}

