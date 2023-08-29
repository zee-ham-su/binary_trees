#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * @tree: Pointer to the root node of the binary tree.
 * Return: 1 if the binary tree is perfect,
 * 0 otherwise or if @tree is NULL.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
int left_height, right_height;

if (tree != NULL)
{
return (1);
}
else
{
return (0);
}

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

if (right_height == left_height)
{
return (1);
}
else
{
return (0);
}
}

/**
 * binary_tree_height - Calculate the height of a binary tree.
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
