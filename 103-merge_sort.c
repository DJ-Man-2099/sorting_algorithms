#include "sort.h"
/**
 * inner_merge_sort - Sorting Operation
 *
 * @array: array to sort
 * @size: size of array to sort
 *
 * sorts the array recursively
 *
 * Return: void
 */
void inner_merge_sort(int *array, size_t size)
{
	int left_size = size / 2, right_size = size - left_size,
		i, left_count = 0, right_count = 0;
	int *left_array, *right_array;

	if (size > 1)
	{
		left_array = calloc(size, sizeof(int));
		if (left_array == NULL)
			return;
		for (i = 0; i < (int)size; i++)
			left_array[i] = array[i];
		right_array = left_array + left_size;
		inner_merge_sort(left_array, left_size);
		inner_merge_sort(right_array, right_size);
		printf("Merging...\n");
		printf("[left]: ");
		print_array(left_array, left_size);
		printf("[right]: ");
		print_array(right_array, right_size);
		for (i = 0; i < (int)size; i++)
		{
			if (left_count < left_size &&
				(right_count >= right_size ||
				 left_array[left_count] <= right_array[right_count]))
			{
				array[i] = left_array[left_count];
				left_count++;
			}
			else
			{
				array[i] = right_array[right_count];
				right_count++;
			}
		}

		printf("[Done]: ");
		print_array(array, size);
		free(left_array);
	}
}
/**
 * merge_sort - Sorting function
 *
 * @array: array to sort
 * @size: size of array to sort
 *
 * sorts an array of integers
 * in ascending order
 * using the Merge sort algorithm
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{

	if (size >= 2)
		inner_merge_sort(array, size);
}
