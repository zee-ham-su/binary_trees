#include "binary_trees.h"

/**
 * binary_tree_balance - Calculate the balance factor of a binary tree node.
 * @tree: A pointer to the root of the binary tree node
 * to calculate balance for.
 * Return: The balance factor of the binary tree node.
 * A positive value indicates
 * that the left subtree is higher, a negative value indicates that the
 * right subtree is higher, and 0 indicates a balanced tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
int left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (left_height - right_height);
}


/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

return (left_height > right_height ? left_height : right_height);
}