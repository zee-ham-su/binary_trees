#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* DATA STRUCTURES */

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* Queue structure for level-order traversal */

/**
 * struct queue_node - A node in a queue for binary tree traversal.
 * @node: Reference to a binary tree node.
 * @next: Pointer to the next node in the queue.
 */
typedef struct queue_node
{
	const binary_tree_t *node;
	struct queue_node *next;
} queue_node_t;

/**
 * struct queue_s - A queue data structure for binary tree traversal.
 * @front: Pointer to the front (head) node of the queue.
 * @rear: Pointer to the rear (tail) node of the queue.
 */
typedef struct queue_s
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

/* Mandatory function prototypes */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Advanced tasks prototypes */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Aux function prototypes */
void enqueue(queue_t *queue, const binary_tree_t *node);
const binary_tree_t *dequeue(queue_t *queue);

#endif /* _BINARY_TREES_H_ */
