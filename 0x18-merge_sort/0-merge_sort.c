#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of 'array'
 * @array: The array containing the subarrays
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 **/
void merge(int *array, int *left, size_t left_size,
		   int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	size_t total_size = left_size + right_size;
	int *tmp = malloc(sizeof(int) * total_size);

	if (tmp == NULL)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			tmp[k++] = left[i++];
		else
			tmp[k++] = right[j++];
	}

	while (i < left_size)
		tmp[k++] = left[i++];

	while (j < right_size)
		tmp[k++] = right[j++];

	for (i = 0; i < total_size; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array, total_size);

	free(tmp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (size < 2 || array == NULL)
		return;

	mid = size / 2;

	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, mid, right, size - mid);
}
