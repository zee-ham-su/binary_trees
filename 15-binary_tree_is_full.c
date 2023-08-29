#include "binary_trees.h"

/**
 * binary_tree_is_full - Check if a binary tree is full.
 * A binary tree is considered full if every node has either 0 or 2 children.
 * @tree: Pointer to the root node of the binary tree.
 * Return: 1 if the binary tree is full, 0 otherwise or if @tree is NULL.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
int left_full, right_full;

if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (1);

left_full = binary_tree_is_full(tree->left);
right_full = binary_tree_is_full(tree->right);

if (left_full == 0 || right_full == 0)
return (0);

return (1);
}
