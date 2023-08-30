#include "binary_trees.h"

/**
 * min_node - Finds the minimum node in a binary search tree subtree.
 * @subtree_root: The root of the subtree to search.
 *
 * Return: A pointer to the node with the minimum value.
 */

bst_t *min_node(bst_t *subtree_root)
{
while (subtree_root->left != NULL)
{
subtree_root = subtree_root->left;
}
return (subtree_root);
}

/**
 * del_bst_node - Deletes a node from a binary search tree.
 * @tree_root: A pointer to the root node of the BST.
 * @node_to_delete: The node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *del_bst_node(bst_t *tree_root, bst_t *node_to_delete)
{
bst_t *parent = node_to_delete->parent;
bst_t *replacement = NULL;
if (node_to_delete->left == NULL)
{
replacement = node_to_delete->right;
if (parent != NULL)
{
if (parent->left == node_to_delete)
{
parent->left = replacement;
}
else
{
parent->right = replacement;
}
}
if (replacement != NULL)
{
replacement->parent = parent;
}
free(node_to_delete);
return ((parent == NULL) ? replacement : tree_root);
}
else if (node_to_delete->right == NULL)
{
replacement = node_to_delete->left;
if (parent != NULL)
{
if (parent->left == node_to_delete)
{
parent->left = replacement;
}
else
{
parent->right = replacement;
}
}
if (replacement != NULL)
{
replacement->parent = parent;
}
free(node_to_delete);
return ((parent == NULL) ? replacement : tree_root);
}
replacement = min_node(node_to_delete->right);
node_to_delete->n = replacement->n;
return (del_bst_node(tree_root, replacement));
}

/**
 * bst_remove_recur - Removes a node recursively from a BST.
 * @tree_root: A pointer to the root node of the BST.
 * @current_node: The current node being searched.
 * @value: The value to remove.
 *
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_remove_recur(bst_t *tree_root, bst_t *current_node, int value)
{
if (current_node != NULL)
{
if (current_node->n == value)
{
return (del_bst_node(tree_root, current_node));
}
else if (current_node->n > value)
{
return (bst_remove_recur(tree_root, current_node->left, value));
}
else
{
return (bst_remove_recur(tree_root, current_node->right, value));
}
}
return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove.
 *
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *results;
results = bst_remove_recur(root, root, value);
return (results);
}
