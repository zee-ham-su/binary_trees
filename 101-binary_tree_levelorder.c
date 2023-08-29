#include "binary_trees.h"

/**
 * enqueue - Enqueue a node in the queue.
 * @queue: Pointer to the queue structure.
 * @node: Pointer to the binary tree node to enqueue.
 * This function adds a new node to the rear of the queue.
 */

void enqueue(queue_t *queue, const binary_tree_t *node)
{
queue_node_t *new_node = malloc(sizeof(queue_node_t));
if (new_node == NULL)
{
return;
}
new_node->node = node;
new_node->next = NULL;

if (queue->rear == NULL)
{
queue->front = new_node;
queue->rear = new_node;
}
else
{
queue->rear->next = new_node;
queue->rear = new_node;
}
}

/**
 * dequeue - Dequeue a node from the queue.
 * @queue: Pointer to the queue structure.
 * Return: Returns NULL if the queue is empty.
 */

const binary_tree_t *dequeue(queue_t *queue)
{
if (queue->front == NULL)
return (NULL);

const binary_tree_t *node = queue->front->node;
queue_node_t *temp = queue->front;

if (queue->front == queue->rear)
{
queue->front = NULL;
queue->rear = NULL;
}
else
{
queue->front = queue->front->next;
}

free(temp);
return (node);
}

/**
 * binary_tree_levelorder - Perform level-order traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node's value.
 * If @tree or @func is NULL, the function does nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

queue_t queue;
queue.front = NULL;
queue.rear = NULL;

enqueue(&queue, tree);

while (queue.front != NULL)
{
const binary_tree_t *node = dequeue(&queue);
func(node->n);

if (node->left != NULL)
enqueue(&queue, node->left);
if (node->right != NULL)
enqueue(&queue, node->right);
}
}
