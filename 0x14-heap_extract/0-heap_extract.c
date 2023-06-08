#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two nodes
 * @node1: First node
 * @node2: Second node
 * Return: NULL
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * get_parent - Retrieves the parent of a node
 * @node: Pointer to the node
 * Return: Pointer to the parent node
 */
heap_t *get_parent(heap_t *node)
{
	if (node && node->parent)
		return (node->parent);
	return (NULL);
}

/**
 * get_last_node - Retrieves the last level-order node of the heap
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	int size;
	int i;
	heap_t *queue[100];
	heap_t *node;

	if (!root)
		return (NULL);

	size = 0;
	queue[size++] = root;

	for (i = 0; i < size; ++i)
	{
		node = queue[i];
		if (node->left)
			queue[size++] = node->left;
		if (node->right)
			queue[size++] = node->right;
	}

	return (node);
}

/**
 * heapify_down - Fixes the heap property downwards from the root
 * @root: Pointer to the root node of the heap
 * Return: nothing
 */
void heapify_down(heap_t **root)
{
	heap_t *node;
	heap_t *largest;

	if (!root || !*root)
		return;

	node = *root;

	while (1)
	{
		largest = node;

		if (node->left && node->left->n > largest->n)
			largest = node->left;

		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		swap_values(node, largest);
		node = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;

	if (!root || !*root)
		return (0);
	value = (*root)->n;
	last_node = get_last_node(*root);
	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	else
	{
		*root = NULL;
	}
	if (*root != last_node)
	{
		last_node->parent = NULL;
		last_node->left = (*root)->left;
		last_node->right = (*root)->right;
		if (last_node->left)
			last_node->left->parent = last_node;
		if (last_node->right)
			last_node->right->parent = last_node;
		*root = last_node;
		heapify_down(root);
	}
	free(last_node);
	return (value);
}
