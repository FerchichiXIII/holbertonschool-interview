#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present in the list or if head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *express;

    if (list == NULL)
        return (NULL);

    express = list;
    while (express)
    {
        current = express;
        if (express->express)
        {
            printf("Value checked at index [%lu] = [%d]\n",
                   express->express->index, express->express->n);
            if (express->express->n >= value)
            {
                printf("Value found between indexes [%lu] and [%lu]\n",
                       current->index, express->express->index);
                break;
            }
            express = express->express;
        }
        else
        {
            while (current->next)
                current = current->next;
            printf("Value found between indexes [%lu] and [%lu]\n",
                   express->index, current->index);
            break;
        }
    }

    while (current)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return (current);
        if (current->n > value)
            break;
        current = current->next;
    }

    return (NULL);
}
    