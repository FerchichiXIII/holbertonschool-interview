#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 *
 * @list: listint.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

 int check_cycle(listint_t *list)
 {
	listint_t *a;
	listint_t *b;

	if (list == NULL || list->next == NULL)
	/* if list is NULL or empty, return 0 for no cycle */
		return (0);
	/* set slow moving pointer to start of list */
	a = list;
	/* set fast moving pointer to the next node */
	b = list;
	/* ensure hare can move forward two spots without segfaulting */
	while (b != NULL)
	{
		/* if both pointers ever point to same node, a cycle is found */
		b = b->next->next;
		a = a->next;
		if (b == a)
			return (1);
			/* otherwise, slow pointer moves forward one node */
	}
	/* return 0 if made to end of the list and did not find a match */
	return (0);
}
