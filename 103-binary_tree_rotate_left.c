#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *new_root;
binary_tree_t *subtree;

if (tree == NULL || tree->right == NULL)
return (NULL);
new_root = tree->right;
subtree = new_root->left;
new_root->left = tree;
tree->right = subtree;
if (subtree)
subtree->parent = tree;
subtree = tree->parent;
tree->parent = new_root;
new_root->parent = subtree;
if (subtree)
{
if (subtree->left == tree)
subtree->left = new_root;
else
subtree->right = new_root;
}

return (new_root);
}
