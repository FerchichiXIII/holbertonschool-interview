#include "sort.h"

/**
 * heapify - Heapify a subtree rooted at index 'root'
 * @array: The array to be sorted
 * @size: Size of the array
 * @root: Index of the root node
 * @heap_size: Size of the heap
 */
 
 void heapify(int *array, size_t size, size_t root, size_t heap_size)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < heap_size && array[left] > array[largest])
        largest = left;

    if (right < heap_size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        print_array(array, size);
        heapify(array, size, largest, heap_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);
        heapify(array, size, 0, i);
    }
}
