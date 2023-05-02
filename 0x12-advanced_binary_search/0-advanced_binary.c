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
    int low = 0; /* Low index of the search range */
    int high = size - 1; /* High index of the search range */
    int mid; /* Middle index of the search range */
    int i; /* Loop index */

    if (array == NULL || size == 0) /* Check for invalid input */
        return (-1);

    while (low <= high) /* Loop until search range is exhausted */
    {
        printf("Searching in array: "); /* Print current search range */
        for (i = low; i < high; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[high]);

        mid = (low + high) / 2; /* Calculate middle index */

        if (array[mid] == value) /* Check if value is found */
        {
            if (mid == 0 || array[mid - 1] < value) /* Check if first occurrence */
                return (mid); /* Return index */
            else
                high = mid - 1; /* Search left half */
        }
        else if (array[mid] < value) /* Value is in right half */
            low = mid + 1;
        else /* Value is in left half */
            high = mid - 1;
    }

    return (-1); /* Value not found */
}