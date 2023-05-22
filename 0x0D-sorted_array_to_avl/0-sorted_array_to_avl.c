#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_avl_tree - Creates an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the sorted array
 * @start: Index of the start element
 * @end: Index of the end element
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *create_avl_tree(int *array, int start, int end)
{
    avl_t *new_node;
    int mid;

    if (start > end)
        return NULL;

    mid = (start + end) / 2;

    new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = array[mid];
    new_node->parent = NULL;
    new_node->left = create_avl_tree(array, start, mid - 1);
    new_node->right = create_avl_tree(array, mid + 1, end);

    if (new_node->left != NULL)
        new_node->left->parent = new_node;
    if (new_node->right != NULL)
        new_node->right->parent = new_node;

    return new_node;
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    return create_avl_tree(array, 0, size - 1);
}
