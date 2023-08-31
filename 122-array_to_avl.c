#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to convert
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
avl_t *root = NULL;
size_t j;

for (j = 0; j < size; j++)
(avl_insert(&root, array[j]));
return (root);
}
