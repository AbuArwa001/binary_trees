#include "binary_trees.h"
#include "101-binary_tree_levelorder.c"
#include <stdio.h>

/**
 * enqueue - Adds a node to the rear of the queue
 * @q: Pointer to the queue
 * @tree: Pointer to the binary tree node to enqueue
 * @fr: pointer to front and rear
 * Return: returns queue node
 */
queue_t *enqueue(const binary_tree_t *tree, queue_t *q, Queue_t *fr)
{
	queue_t *new_node = malloc(sizeof(queue_t));

	new_node->node = (binary_tree_t *) tree;
	new_node->next = NULL;

	if (!fr->front && !fr->rear)
	{
		fr->front = fr->rear =  new_node;
		return (new_node);
	}

	fr->rear->next =  new_node;
	fr->rear =  new_node;
	return (q);
}
/**
 * dequeue - Removes and returns the node at the front of the queue
 * @fr: Pointer to the front and rear
 * Return: Pointer to the dequeued binary tree node,
 *          or NULL if the queue is empty
 */
binary_tree_t *dequeue(Queue_t *fr)
{
	binary_tree_t *data = fr->front->node;
	queue_t *temp = fr->front;

	if (!fr->front)
	{
		return (NULL);
	}

	if (fr->front == fr->rear)
	{
		fr->front = fr->rear = NULL;
	}
	else
	{
		fr->front = fr->front->next;
	}

	free(temp);
	return (data);
}

/**
 * CurrentLevel - prints current level
 * @tree: pointer to node of subtree
 * @level: current level
 * @q: pointer to the queue
 * @fr: pointer to the queue structure
*/
void CurrentLevel(const binary_tree_t *tree, int level,  queue_t **q,
		Queue_t *fr)
{
	if (tree == NULL)
	{
		*q = enqueue(tree, *q, fr);
		return;
	}

	if (level == 1)
	{
		*q = enqueue(tree, *q, fr);
	}
	else
		if (level > 1)
		{
			CurrentLevel(tree->left, level - 1,  q, fr);
			CurrentLevel(tree->right, level - 1, q, fr);
		}
}

/**
 * levelOrder - Function to print level order traversal a tree
 * @tree: pointer to node of subtree
 * @q: pointer to the queue
 * @fr: pointer to the queue structure
*/
void levelOrder(const binary_tree_t *tree,  queue_t **q, Queue_t *fr)
{
	int h = max_depth(tree);
	int i;

	for (i = 1; i <= h; i++)
		CurrentLevel(tree, i, q, fr);
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: return 1 if complete btree or 0 if not
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *q = NULL;
	Queue_t *fr = malloc(sizeof(Queue_t));
	int flg = -1;

	if (!tree)
		return (0);



	if (!fr)
		return (0);

	fr->front = NULL;
	fr->rear = NULL;
	levelOrder(tree,  &q, fr);

	while (fr->rear)
	{
		binary_tree_t *pr = dequeue(fr);

		if (!pr)
		{
			flg = 1;
		}
		else
			if (flg == 1 && pr)
			{
				flg = 0;
				break;
			}
	}
	if ((!fr->front && !fr->rear) && flg == -1)
	{
		free(fr);
		return (1);
	}
	free(fr);
	if (flg == 0)
		return (0);
	return (1);
}
