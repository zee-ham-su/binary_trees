#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the BST to remove a node from
 * @value: The value to remove in the BST
 *
 * Return: A pointer to the new root node of the BST after deletion
 */


bst_t *bst_remove(bst_t *root, int value)
{
if (root == NULL)
return (NULL);

if (value < root->n)
{
root->left = bst_remove(root->left, value);
if (root->left != NULL)
{
root->left->parent = root;
}
}
else if (value > root->n)
{
root->right = bst_remove(root->right, value);
if (root->right != NULL)
{
root->right->parent = root;
}
}
else
{
if (root->left == NULL && root->right == NULL)
{
if (root->parent != NULL && root->parent->left == root)
{
root->parent->left = NULL;
}
else if (root->parent != NULL)
{
root->parent->right = NULL;
}
free(root);
return (NULL);
}

if (root->left != NULL)
{
root->left->parent = root;
}
if (root->right != NULL)
{
root->right->parent = root;
}
}

return (root);
}

/**
 * bst_min - Finds the minimum node in a binary search tree
 * @node: A pointer to the root node of the BST to search
 *
 * Return: A pointer to the node with the smallest value
 */

bst_t *bst_min(bst_t *node)
{
bst_t *current = node;
while (current && current->left != NULL)
current = current->left;

return (current);
}
