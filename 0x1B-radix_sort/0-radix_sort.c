#include "sort.h"

/**
 * get_max - Returns the maximum element from an array
 * @array: The array
 * @size: Size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts the array based on a particular digit
 * @array: The array
 * @size: Size of the array
 * @exp: The exponent representing the current digit position
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);

	if (output == NULL)
		return;

	int count[10] = {0};

	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using radix sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	int max = get_max(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
