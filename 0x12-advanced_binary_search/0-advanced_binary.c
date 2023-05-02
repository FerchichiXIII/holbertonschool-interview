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
    int low = 0;
    int high = size - 1;
    int mid;
    int i;

    if (array == NULL || size == 0)
        return (-1);

    while (low <= high)
    {
        printf("Searching in array: ");
        for (i = low; i < high; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[high]);

        mid = (low + high) / 2;

        if (array[mid] == value)
        {
            if (mid == 0 || array[mid - 1] < value)
                return (mid);
            else
                high = mid - 1;
        }
        else if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (-1); /* Value not found */
}