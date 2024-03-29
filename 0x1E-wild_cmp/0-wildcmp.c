#include "holberton.h"
/**
 * wildcmp - compares two str and returns 1 if the str can be considere
 * @s1: string
 * @s2: string
 *
 * Return: Zero
 */
int wildcmp(char *s1, char *s2)
{

	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
