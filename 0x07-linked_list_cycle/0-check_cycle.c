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
    listint_t *f;
    listint_t *s;

    if (list == NULL || list->next == NULL)
    {
        return (0);
    }
    f = list;
    s = list;
    
    while (s != NULL)
    {
        s = s->next->next;
        f = f->next;
        if (s == f)
        {
            return (1);
        }
    }
    return (0);

 }