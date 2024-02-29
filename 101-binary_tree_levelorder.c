#include "binary_trees.h"
#include "bintree.c"

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

	/*create a queue */
	Queue *q = createQueue();

	if (!q)
	{
		return;
	}

	/* enqueue the root node of the tree */
	enqueue(q, (void *)tree);

	while (!isEmpty(q))
	{
		/* dequeue the front node of the queue */
		binary_tree_t *node = dequeue(q);
		/* call the func function on the node's value */
		func(node->n);

		/* if the node has a left chil */
		if (node->left)
		{
			/* enqueue the left child to the queue */
			enqueue(q, (void *)node->left);
		}

		/* if the node has a right chil */
		if (node->right)
		{
			/* enqueue the right child to the queue */
			enqueue(q, (void *)node->right);
		}
	}

	destroyQueue(q);
}
