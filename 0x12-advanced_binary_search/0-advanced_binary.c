#include "search.h"
#include <stdio.h>

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located or -1 if not found or array is NULL
 */

int advanced_binary(int *array, size_t size, int value)

{

	size_t i = 0;

	int half = ((size - 1) / 2), result = 0;

	if (array == NULL || size < 1)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != (size - 1))
			printf(", ");
		else
			printf("\n");
	}

	if (array[half] == value && half == 0)
		return (half);
	else if (size == 1)
		return (-1);

	if (array[half] >= value)
		return (advanced_binary(array, half + 1, value));

	half++;
	result = advanced_binary(&array[half], size - half, value);
	if (result == -1)
		return (-1);
	return (half + result);
}
