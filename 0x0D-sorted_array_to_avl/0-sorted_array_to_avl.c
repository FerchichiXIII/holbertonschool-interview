#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node;
	size_t mid;

	if (size == 0)
		return (NULL);

	mid = size / 2;

	/* Create new node for the middle element */
	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = array[mid];
	new_node->parent = NULL;
	new_node->left = sorted_array_to_avl(array, mid);
	new_node->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

	if (new_node->left != NULL)
		new_node->left->parent = new_node;

	if (new_node->right != NULL)
		new_node->right->parent = new_node;

	return (new_node);
}
