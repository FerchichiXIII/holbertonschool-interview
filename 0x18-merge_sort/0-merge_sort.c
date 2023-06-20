#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of `array`
 * @array: The array to be sorted
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 **/
void merge(int *array, int *left, size_t left_size,
							 int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *tmp = malloc((left_size + right_size) * sizeof(int));

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			tmp[k] = left[i];
			i++;
		}
		else
		{
			tmp[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		tmp[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		tmp[k] = right[j];
		j++;
		k++;
	}

	for (i = 0; i < left_size + right_size; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
	free(tmp);
}
/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, mid, right, size - mid);
}
