#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Print the array being searched
 * @array: Array to print
 * @left: Left index of the @array to print
 * @right: Right index of the @array to print
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i != right)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary - Search for a value in a sorted array of integers
 * @array: Array to search in
 * @size: Number of elements in the @array
 * @value: Value to search for
 *
 * Return: Index where @value is located, or -1 if @value is not present in @array
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t left = 0, right = size - 1, mid;

    if (!array)
        return (-1);

    while (left <= right)
    {
        mid = (left + right) / 2;
        print_array(array, left, right);

        if (array[mid] < value)
            left = mid + 1;
        else if (array[mid] > value)
            right = mid - 1;
        else
        {
            if (mid == 0 || array[mid - 1] != value)
                return (mid);
            right = mid;
        }
    }

    return (-1);
}
