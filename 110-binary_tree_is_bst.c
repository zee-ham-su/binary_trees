#include "binary_trees.h"
#include <stdbool.h>

/**
 * is_bst_recurs - Helper function to recursively check
 * if a tree is a valid BST.
 * @node: Current node being checked.
 * @min: Minimum value allowed for this node.
 * @max: Maximum value allowed for this node.
 *
 * Return: 1 if the subtree rooted at 'node' is a valid BST, 0 otherwise.
 */
int is_bst_recurs(const binary_tree_t *node, const binary_tree_t *min,
const binary_tree_t *max)
{
if (node == NULL)
return (1);

if ((min && node->n <= min->n) || (max && node->n >= max->n))
return (0);

return (is_bst_recurs(node->left, min, node) &&
is_bst_recurs(node->right, node, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
bool result = is_bst_recurs(tree, NULL, NULL);
return (result);
}

