#include <stdlib.h>
#include "binary_trees.h"

/**
 * createQueue - Creates an empty queue
 * Return: A pointer to the created queue, or NULL on failure
 */
Queue *createQueue()
{
	Queue *queue = malloc(sizeof(Queue));

	if (!queue)
	{
		/* Failed to allocate memory for queue */
		return (NULL);
	}

	queue->front = queue->rear = NULL;
	return (queue);
}

/**
 * isEmpty - Checks if a queue is empty
 * @queue: Pointer to the queue
 * Return: 1 if the queue is empty, 0 otherwise
 */
int isEmpty(Queue *queue)
{
	return (queue->front == NULL);
}

/**
 * enqueue - Adds a node to the rear of the queue
 * @queue: Pointer to the queue
 * @node: Pointer to the binary tree node to enqueue
 */
void enqueue(Queue *queue, struct binary_tree_s *node)
{
	queue_t *newNode = malloc(sizeof(queue_t));

	if (!newNode)
	{
		return;
	}

	newNode->node = node;
	newNode->next = NULL;

	if (isEmpty(queue))
	{
		queue->front = queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

/**
 * dequeue - Removes and returns the node at the front of the queue
 * @queue: Pointer to the queue
 * Return: Pointer to the dequeued binary tree node,
 *          or NULL if the queue is empty
 */
struct binary_tree_s *dequeue(Queue *queue)
{
	if (isEmpty(queue))
	{
		/* Queue is empty */
		return (NULL);
	}

	queue_t *temp = queue->front;

	queue->front = queue->front->next;

	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

	struct binary_tree_s *node = temp->node;

	free(temp);

	return (node);
}

/**
 * destroyQueue - Frees the memory allocated for a queue
 * @queue: Pointer to the queue
 */
void destroyQueue(Queue *queue)
{
	while (!isEmpty(queue))
	{
		dequeue(queue);
	}

	free(queue);
}
