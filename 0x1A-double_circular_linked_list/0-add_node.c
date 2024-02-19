#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @lst: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **lst, char *str)
{
	List *new_nd;
	char *node_str;

	if (!lst)
		return (NULL);
	new_nd = malloc(sizeof(List));
	if (!new_nd)
		return (NULL);
	node_str = strdup(str);
	if (!node_str)
	{
		free(new_nd);
		return (NULL);
	}
	new_nd->str = node_str;
	if (!*lst)
	{
		new_nd->next = new_nd;
		new_nd->prev = new_nd;
		*lst = new_nd;
		return (new_nd);
	}
	new_nd->next = *lst;
	new_nd->prev = (*lst)->prev;
	(*lst)->prev = new_nd;
	new_nd->prev->next = new_nd;
	return (new_nd);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular linked list
 * @lst: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_begin(List **lst, char *str)
{
	List *new_nd;
	char *node_str;

	if (!lst)
		return (NULL);
	new_nd = malloc(sizeof(List));
	if (!new_nd)
		return (NULL);
	node_str = strdup(str);
	if (!node_str)
	{
		free(new_nd);
		return (NULL);
	}
	new_nd->str = node_str;
	if (*lst)
	{
		new_nd->next = *lst;
		new_nd->prev = (*lst)->prev;
		(*lst)->prev = new_nd;
		if (new_nd->prev)
			new_nd->prev->next = new_nd;
	}
	else
	{
		new_nd->prev = new_nd;
		new_nd->next = new_nd;
	}
	*lst = new_nd;
	return (new_nd);
}
