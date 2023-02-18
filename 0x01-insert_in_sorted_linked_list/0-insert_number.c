#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: listint
 * @number: int
 * Return: NULL if failed else Return thr add of the new node
 */

listint_t *insert_node(listint_t **head, int number) {
    listint_t *new_node, *current;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        return NULL; /* Return NULL if malloc fails */
    }

    /* Set the value of the new node */
    new_node->n = number;

    /* Handle the case where the new node should be inserted at the head */
    if (*head == NULL || (*head)->n >= number) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    /* Traverse the list to find the position to insert the new node */
    current = *head;
    while (current->next != NULL && current->next->n < number) {
        current = current->next;
    }

    /* Insert the new node into the list */
    new_node->next = current->next;
    current->next = new_node;

    /* Return the address of the new node */
    return new_node;
}
