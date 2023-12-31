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
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);


/* Aux function prototypes */
void traverse_level(const binary_tree_t *tree, void (*func)(int), size_t target_level);
int is_complete_recursive(const binary_tree_t *tree,
								  size_t index, size_t node_count);
int is_bst_recurs(const binary_tree_t *node, const binary_tree_t *min, const binary_tree_t *max);
bst_t *bst_min(bst_t *node);
bst_t *bst_remove_recur(bst_t *tree_root, bst_t *current_node, int value);
bst_t *del_bst_node(bst_t *tree_root, bst_t *node_to_delete);
bst_t *min_node(bst_t *subtree_root);
int is_avl_helper(const binary_tree_t *tree, int min, int max);
size_t get_tree_height(const binary_tree_t *node);
int get_balance_factor(const binary_tree_t *node);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
avl_t **new_node_ptr, int value);
bst_t *remove_bst_node(bst_t *root, int value);
int remove_node_type(bst_t *node);
int find_successor(bst_t *node);
void balance_tree(avl_t **tree);
void create_tree(avl_t **node, int *array, size_t size, int mode);


#endif /* _BINARY_TREES_H_ */
