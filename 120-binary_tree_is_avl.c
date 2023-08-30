#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Returns the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
size_t left_height = binary_tree_height(tree->left);
size_t right_height = binary_tree_height(tree->right);
return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}

/**
 * is_avl_help - Checks if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree.
 * @min: Minimum allowed value for nodes in the subtree.
 * @max: Maximum allowed value for nodes in the subtree.
 *
 * Return: 1 if tree is an AVL tree, 0 otherwise.
 */
int is_avl_help(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);

if (tree->n <= min || tree->n >= max)
return (0);
int left_height = binary_tree_height(tree->left);
int right_height = binary_tree_height(tree->right);
if (abs(left_height - right_height) > 1)
return (0);
return (is_avl_help(tree->left, min, tree->n) &&
is_avl_help(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
int results;
results = is_avl_help(tree, INT_MIN, INT_MAX);
return (results);
}
