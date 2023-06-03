#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Adjusts the heap by sifting down the element at the given index
 * @array: Array of integers
 * @size: Size of the array
 * @index: Index of the element to sift down
 * @heap_size: Size of the heap
 */
void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
    size_t max = index;
    size_t left_child = 2 * index + 1;
    size_t right_child = 2 * index + 2;

    if (left_child < heap_size && array[left_child] > array[max])
        max = left_child;

    if (right_child < heap_size && array[right_child] > array[max])
        max = right_child;

    if (max != index)
    {
        swap(&array[index], &array[max]);
        print_array(array, size);
        sift_down(array, size, max, heap_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    /* Build max heap */
    for (int i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    /* Heap sort */
    for (int i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, size, 0, i);
    }
}
