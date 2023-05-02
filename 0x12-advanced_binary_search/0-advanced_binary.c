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
    int hight = size - 1;
    int mid;
    if (array == NULL || size == 0)
    {
        return (-1)
    }
    while (low <= hight)
    {
        printf("Searching in array: ") for (i = low; i < hight; i++)
        {
            printf("%d, ", array(i));
        }
        printf("%d\n", array[hight]);
        mid = (low + hight) / 2;

        if (array[mid] < value)
        {
            low = mid + 1;
        }

        else
        {
            hight = mid - 1;
        }
    }

    return (-1);
}
