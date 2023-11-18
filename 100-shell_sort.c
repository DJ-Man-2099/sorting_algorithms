#include "sort.h"

/**
 * shell_sort - Sorting function
 *
 * @array: array to sort
 * @size: size of array
 *
 * sorts an array of integers in ascending order
 * using the Shell sort algorithm
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, k, n = 1;
	int temp;

	if (size < 2)
		return;

	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (i = 0; i < size; i++)
			for (j = i; j < size - n; j += n)
				for (k = j + n; k < size; k += n)
					if (array[j] > array[k])
					{
						temp = array[j];
						array[j] = array[k];
						array[k] = temp;
					}
		n /= 3;
		print_array(array, size);
	}
}
