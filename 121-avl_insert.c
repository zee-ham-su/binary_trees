#include "binary_trees.h"

/**
* get_tree_height - Computes the height of a binary tree.
* @node: A pointer to the root node of the binary tree
* for height calculation.
* Return: If the root is NULL, the function returns 0
* Otherwise, it returns the height of the tree.
*/

size_t get_tree_height(const binary_tree_t *node)
{
size_t left_height = 0;
size_t right_height = 0;
if (node != NULL)
{
left_height = node->left ? 1 + get_tree_height(node->left) : 1;
right_height = node->right ? 1 + get_tree_height(node->right) : 1;
return ((left_height > right_height) ? left_height : right_height);
}
return (0);
}

/**
* get_balance_factor - Calculates the balance factor of a binary tree.
* @node: A pointer to the root node of the binary tree
* to calculate the balance factor for.
* Return: If the root is NULL, the function returns 0. Otherwise, it returns
* the balance factor of the tree.
*/

int get_balance_factor(const binary_tree_t *node)
{
int results;
results = (node != NULL ? get_tree_height(node->left) - get_tree_height(node->right) : 0);
return (results);
}

/**
* avl_insert_recursive - ecursively inserts a value into an AVL tree.
* @tree: A double pointer to the root node of the AVL tree for insertion.
* @parent: The parent node under which the current node is being considered.
* @new_node_ptr: A double pointer used to hold the newly inserted node.
* @value: The value to be inserted into the AVL tree.
* Return: Returns a pointer to the updated root of the
* AVL tree after the insertion, or NULL if unsuccessful.
*/

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
avl_t **new_node_ptr, int value)
{
int balance_factor;
if (*tree == NULL)
{
*new_node_ptr = binary_tree_node(parent, value);
if (*new_node_ptr == NULL)
return (NULL);
return (*new_node_ptr);
}

if (value < (*tree)->n)
{
(*tree)->left = avl_insert_recursive(&((*tree)->left),
*tree, new_node_ptr, value);
}
else if (value > (*tree)->n)
{
(*tree)->right = avl_insert_recursive(&((*tree)->right),
*tree, new_node_ptr, value);
}
else
{
return (*tree);
}
balance_factor = get_balance_factor(*tree);
if (balance_factor > 1)
{
if (value < (*tree)->left->n)
{
return (binary_tree_rotate_right(*tree));
}
else
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
return (binary_tree_rotate_right(*tree));
}
}
if (balance_factor < -1)
{
if (value > (*tree)->right->n)
{
return (binary_tree_rotate_left(*tree));
}
else
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
return (binary_tree_rotate_left(*tree));
}
}
return (*tree);
}


/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of
 * the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *new_node;
new_node = NULL;
if (tree == NULL)
return (NULL);

if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
avl_insert_recursive(tree, *tree, &new_node, value);

return (new_node);
}
