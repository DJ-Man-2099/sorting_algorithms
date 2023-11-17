#include "sort.h"
/**
 * lomuto_partitioner - Partitioning Scheme
 *
 * @array: array to partition
 * @low: start
 * @high: end
 * @orig_size: full size
 *
 * gets the splitting pivot for the rest of the sort
 *
 * Return: pivot index
 */
int lomuto_partitioner(int *array, int low, int high, size_t orig_size)
{
	int i = low - 1, j;
	int temp, pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j && array[j] != array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, orig_size);
			}
		}
	}
	if (i + 1 != high && array[high] != array[i + 1])
	{
		temp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, orig_size);
	}
	return (i + 1);
}
/**
 * inner_quick_sort - Sorting function
 *
 * @array: array to partition
 * @low: start
 * @high: end
 * @orig_size: full size
 *
 * sorts an array of integers in ascending order
 * recursively
 * using the Quick sort algorithm
 *
 * Return: void
 */
void inner_quick_sort(int *array, int low, int high, size_t orig_size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partitioner(array, low, high, orig_size);
		inner_quick_sort(array, low, pi - 1, orig_size);
		inner_quick_sort(array, pi + 1, high, orig_size);
	}
}
/**
 * quick_sort - Sorting function
 *
 * @array: array to sort
 * @size: size of array
 *
 * sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1, pi;

	if (size >= 2)
	{
		pi = lomuto_partitioner(array, low, high, size);
		inner_quick_sort(array, low, pi - 1, size);
		inner_quick_sort(array, pi + 1, high, size);
	}
}
