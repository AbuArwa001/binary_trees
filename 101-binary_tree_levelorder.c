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
 * enqueue - Adds a node to the rear of the queue
 * @queue: Pointer to the queue
 * @node: Pointer to the binary tree node to enqueue
 */
void enqueue(Queue *queue, binary_tree_t *node)
{
	queue_t *newNode = malloc(sizeof(queue_t));

	if (!newNode)
	{
		return;
	}

	newNode->node = node;
	newNode->next = NULL;

	if (queue->front == NULL)
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
	if (queue->front == NULL)
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
	while (!(queue->front == NULL))
	{
		dequeue(queue);
	}

	free(queue);
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

}
