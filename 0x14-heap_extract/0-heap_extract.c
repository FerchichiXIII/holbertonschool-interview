#include "binary_trees.h"

/**
 * heapify - restores the heap property of the tree
 * @new_root: head of the heap tree
 * Return: Nothing
 */
void heapify(binary_tree_t *new_root)
{
	binary_tree_t *child = NULL;
	int temp_num = 0;

	while (1)
	{
		if (!new_root->left)
			break;
		else if (!new_root->right)
			child = new_root->left;
		else
		{
			if (new_root->left->n >= new_root->right->n)
				child = new_root->left;
			else
				child = new_root->right;
		}

		if (new_root->n >= child->n)
			break;

		temp_num = new_root->n;
		new_root->n = child->n;
		child->n = temp_num;

		new_root = child;
	}
}

/**
 * get_num_nodes - gets the number of nodes of heap
 * @new_root: head of the heap tree
 * Return: all the nodes in heap tree
 */
int get_num_nodes(heap_t *new_root)
{
	int left_count = 0, right_count = 0;

	if (!new_root)
		return 0;

	left_count = get_num_nodes(new_root->left);
	right_count = get_num_nodes(new_root->right);

	return 1 + left_count + right_count;
}

/**
 * get_last_node - gets the last node in heap_min
 * @new_root: head of the heap tree
 * Return: last node in heap_min
 */
binary_tree_t *get_last_node(heap_t *new_root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *last_node = NULL;

	size_heap = get_num_nodes(new_root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (last_node = new_root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return last_node;
}

/**
 * heap_extract - extracts the root node of a Max Heap
 * @root: a double pointer to the root node of the heap
 * Return: the root node number or 0 on failure
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *last_node = NULL, *new_head_node = NULL;
	int extracted_num = 0;

	if (!root || !*root)
		return 0;

	new_head_node = *root;

	if (!new_head_node->left && !new_head_node->right)
	{
		extracted_num = new_head_node->n;
		free(new_head_node);
		*root = NULL;
		return extracted_num;
	}

	new_head_node = *root;
	extracted_num = new_head_node->n;

	last_node = get_last_node(*root);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	last_node->left = new_head_node->left;
	last_node->right = new_head_node->right;
	last_node->parent = new_head_node->parent;

	if (new_head_node->left) {new_head_node->left->parent = last_node;}
	if (new_head_node->right) {new_head_node->right->parent = last_node;}

	*root = last_node;
	free(new_head_node);

	heapify(*root);

	return (extracted_num);
}
