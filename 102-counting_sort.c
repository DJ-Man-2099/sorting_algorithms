#include "sort.h"
/**
 * counting_sort - Sorting function
 *
 * @array: array to sort
 * @size: size of array to sort
 *
 * sorts an array of integers
 * in ascending order
 * using the Counting sort algorithm
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array, i, max;

	if (array != NULL && size >= 2)
	{
		max = array[0];
		output_array = calloc(size, sizeof(int));
		if (output_array == NULL)
			return;
		for (i = 1; i < (int)size; i++)
			if (max < array[i])
				max = array[i];

		count_array = calloc(max + 1, sizeof(int));
		if (count_array == NULL)
			return;

		for (i = 0; i < (int)size; i++)
			count_array[array[i]]++;

		for (i = 1; i <= max; i++)
			count_array[i] = count_array[i - 1] + count_array[i];

		print_array(count_array, max + 1);

		for (i = (int)size - 1; i >= 0; i--)
		{
			output_array[count_array[array[i]] - 1] = array[i];
			count_array[array[i]]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = output_array[i];

		free(count_array);
		free(output_array);
	}
}
