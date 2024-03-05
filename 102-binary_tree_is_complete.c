#include "binary_trees.h"
#include <stdio.h>

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
queue_t *enqueue(const binary_tree_t *tree, queue_t *q, Queue_t *fr)
{
    queue_t *new_node = malloc(sizeof(queue_t));

    new_node->node =(binary_tree_t *) tree;
    new_node->next = NULL;

    if (!fr->front && !fr->rear)
    {
        fr->front = fr->rear =  new_node;
        return new_node;
    }
    fr->rear->next =  new_node;
    fr->rear =  new_node;
    return (q);
}

binary_tree_t *dequeue(Queue_t *fr)
{
    if (!fr->front)
    {
        return NULL;
    }
    binary_tree_t *data = fr->front->node;
    queue_t *temp = fr->front;
    if (fr->front == fr->rear)
    {
        fr->front = fr->rear = NULL;
    }
    else
    {
        fr->front = fr->front->next;
    }
    free(temp);
    return data;
}

/**
 * printCurrentLevel - prints current level
 * @tree: pointer to node of subtree
 * @level: current level
 * @q: pointer to the queue
 * @fr: pointer to the queue structure
*/
void CurrentLevel(const binary_tree_t *tree, int level,  queue_t **q, Queue_t *fr)
{
	if (tree == NULL)
    {
        printf("NULL");
        *q = enqueue(tree, *q, fr);
        return;
    }

	if (level == 1)
    {
        // Enqueue the node to the queue and update the queue pointer
        *q = enqueue(tree, *q, fr);
        printf("%d ", tree->n);
    }
	else if (level > 1)
    {
        CurrentLevel(tree->left, level - 1,  q, fr);
        CurrentLevel(tree->right, level - 1, q, fr);
    }
}

/**
 * printLevelOrder - Function to print level order traversal a tree
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
Queue_t *createQueue()
{
    Queue_t *qu = malloc(sizeof(Queue_t));
    qu->front = NULL;
    qu->rear = NULL;
    return (qu);
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
    {
        return (0);
    }
    queue_t *q = NULL;
    Queue_t *fr = createQueue();
    levelOrder(tree,  &q, fr);
    while (fr->rear)
    {
        binary_tree_t *pr = dequeue(fr);
        printf("%d ", pr->n);  
        if (pr && fr->rear)
        {
            
        }
        else if (!pr && fr->rear)
        {
            return (0);
        }

    }
    // printf("END OF A TREE\n");
    return (1);
}