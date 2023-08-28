#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a new binar tree node
 * @parent: pointer to the parent node
 * @value: value that is to be stored in the new node created
 * Return: return a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *created_node;

created_node = malloc(sizeof(binary_tree_t));
if (created_node == NULL)
return (NULL);

created_node->n = value;
created_node->parent = parent;
created_node->left = NULL;
created_node->right = NULL;

return (created_node);
}
