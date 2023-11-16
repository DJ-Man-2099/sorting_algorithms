#include "sort.h"
/**
 * bubble_sort - Sorting function
 *
 * @array: array to sort
 * @size: length of array
 *
 * sorts an array of integers
 * in ascending order
 * using the Bubble sort algorithm
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size >= 2)
	{
		for (i = 0; i < size - 1; i++)
			for (j = 1; j < size - i; j++)
				if (array[j - 1] > array[j])
				{
					temp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = temp;
					print_array(array, size);
				}
	}
}
