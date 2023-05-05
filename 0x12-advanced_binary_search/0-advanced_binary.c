#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index where value is located or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i = 0;
    int index;

    if (!array || size == 0)
        return (-1);

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
        printf("%d%s", array[i], i == size - 1 ? "\n" : ", ");

    if (size == 1 && array[0] != value)
        return (-1);

    index = (size - 1) / 2;

    if (array[index] == value)
    {
        if (index == 0 || array[index - 1] != value)
            return (index);
        return (advanced_binary(array, index + 1, value));
    }
    if (array[index] < value)
        return (advanced_binary(&array[index + 1], size - index - 1, value));
    return (advanced_binary(array, index + 1, value));
}
