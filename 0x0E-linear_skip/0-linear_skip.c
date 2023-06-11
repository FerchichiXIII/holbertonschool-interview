#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Pointer to the head of the skip list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *express;

	if (list == NULL)
		return (NULL);

	current = list;
	express = list->express;

	while (express != NULL && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   express->index, express->n);
		current = express;
		express = express->express;
	}

	if (express == NULL)
	{
		size_t index = current->index;
		while (current->next != NULL)
			current = current->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			   index, current->index);
	}
	else
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   express->index, express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
			   current->index, express->index);
	}

	while (current != NULL && current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		current = current->next;
	}

	if (current != NULL && current->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		return (current);
	}

	// Handle case when value is greater than the last node
	if (current != NULL && current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		printf("Found at index: (nil)\n");
		return (NULL);
	}

	return (NULL);
}
