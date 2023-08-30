#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to insert into the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *new_node = NULL;
bst_t *current_node;

if (tree == NULL)
return (NULL);

if (*tree == NULL)
{
new_node = binary_tree_node(NULL, value);
*tree = new_node;
return (new_node);
}

current_node = *tree;

while (current_node)
{
if (value < current_node->n)
{
if (current_node->left == NULL)
{
new_node = binary_tree_node(current_node, value);
current_node->left = new_node;
return (new_node);
}
current_node = current_node->left;
}
else
{
if (current_node->right == NULL)
{
new_node = binary_tree_node(current_node, value);
current_node->right = new_node;
return (new_node);
}
current_node = current_node->right;
}
}

return (NULL);
}
