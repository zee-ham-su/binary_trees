#include "binary_trees.h"

/**
 * binary_tree_is_complete_recursive - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 * @index: The index of the current node.
 * @node_count: The number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_recursive(const binary_tree_t *tree,
size_t index, size_t node_count)
{
if (tree == NULL)
return (1);

if (index >= node_count)
return (0);

return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
size_t node_count = 0;
size_t index = 0;

if (tree == NULL)
return (0);

node_count = binary_tree_size(tree);

return (is_complete_recursive(tree, index, node_count));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 * Return: The size of the tree (number of nodes), or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
