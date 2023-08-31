#include "binary_trees.h"

/**
 * balance_tree - Balances the AVL tree after insertion or removal.
 * @tree: Pointer to the root node of the tree.
 */
void balance_tree(avl_t **tree)
{
    int balance_value;

    if (tree == NULL || *tree == NULL)
        return;
    if ((*tree)->left == NULL && (*tree)->right == NULL)
        return;
    balance_tree(&(*tree)->left);
    balance_tree(&(*tree)->right);
    balance_value = binary_tree_balance((const binary_tree_t *)*tree);
    if (balance_value > 1)
        *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
    else if (balance_value < -1)
        *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the minimum value node in the right subtree.
 * @node: Node to start searching from.
 * Return: The minimum value in the subtree rooted at @node.
 */
int find_successor(bst_t *node)
{
    int left_value = 0;

    if (node == NULL)
    {
        return 0;
    }
    else
    {
        left_value = find_successor(node->left);
        if (left_value == 0)
        {
            return node->n;
        }
        return left_value;
    }
}

/**
 * remove_node_type - Removes a node from the binary search tree based on its children.
 * @node: Node to remove.
 * Return: 0 if it has no children, otherwise a new value to re-balance the tree.
 */
int remove_node_type(bst_t *node)
{
    int new_value = 0;

    if (!node->left && !node->right)
    {
        if (node->parent->right == node)
            node->parent->right = NULL;
        else
            node->parent->left = NULL;
        free(node);
        return 0;
    }
    else if ((!node->left && node->right) || (!node->right && node->left))
    {
        if (!node->left)
        {
            if (node->parent->right == node)
                node->parent->right = node->right;
            else
                node->parent->left = node->right;
            node->right->parent = node->parent;
        }
        if (!node->right)
        {
            if (node->parent->right == node)
                node->parent->right = node->left;
            else
                node->parent->left = node->left;
            node->left->parent = node->parent;
        }
        free(node);
        return 0;
    }
    else
    {
        new_value = find_successor(node->right);
        node->n = new_value;
        return new_value;
    }
}

/**
 * remove_bst_node - Removes a node from the binary search tree.
 * @root: Root of the tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the updated root.
 */
bst_t *remove_bst_node(bst_t *root, int value)
{
    int node_type = 0;

    if (root == NULL)
        return NULL;
    if (value < root->n)
        remove_bst_node(root->left, value);
    else if (value > root->n)
        remove_bst_node(root->right, value);
    else if (value == root->n)
    {
node_type = remove_node_type(root);
if (node_type != 0)
remove_bst_node(root->right, node_type);
}
else
return NULL;
return root;
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Root of the tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the updated root.
 */
avl_t *avl_remove(avl_t *root, int value)
{
avl_t *new_root = (avl_t *)remove_bst_node((bst_t *)root, value);

if (new_root == NULL)
return NULL;
balance_tree(&new_root);
return new_root;
}
