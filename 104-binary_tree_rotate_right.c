#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *new_root, *subtree;

if (tree == NULL || tree->left == NULL)
return (NULL);

new_root = tree->left;
subtree = new_root->right;
new_root->right = tree;
tree->left = subtree;
if (subtree != NULL)
subtree->parent = tree;
subtree = tree->parent;
tree->parent = new_root;
new_root->parent = subtree;
if (subtree != NULL)
{
if (subtree->left == tree)
subtree->left = new_root;
else
subtree->right = new_root;
}

return (new_root);
}
