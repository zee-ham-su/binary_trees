#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a new node as
 * the right-child
 * of a parent node.
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 * Return: A pointer to the newly created binary tree node,
 * or NULL on failure
 * or if the parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *created_node;

if (parent == NULL)
return (NULL);

created_node = binary_tree_node(parent, value);
if (created_node == NULL)
return (NULL);

if (parent->right != NULL)
{
created_node->right = parent->right;
parent->right->parent = created_node;
}
parent->right = created_node;
return (created_node);
}
