#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * A binary tree is considered perfect if all of its levels are completely
 * filled and the tree is full (every node has either 0 or 2 children).
 * @tree: Pointer to the root node of the binary tree.
 * Return: 1 if the binary tree is perfect, 0 otherwise or if @tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

int left_height = binary_tree_height(tree->left);
int right_height = binary_tree_height(tree->right);

if (tree->left == NULL && tree->right == NULL)
return (1);

if (tree->left == NULL || tree->right == NULL)
return (0);

if (left_height != right_height)
return (0);

return (binary_tree_is_perfect(tree->left) &&
binary_tree_is_perfect(tree->right));
}

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * The height of a binary tree is the number of edges on the longest path
 * from the root node to a leaf node.
 * @tree: Pointer to the root node of the binary tree.
 * Return: Height of the binary tree. 0 if @tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (1 + ((left_height > right_height) ? left_height : right_height));
}
