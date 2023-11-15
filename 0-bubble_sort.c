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
	size_t i, j, last_index;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		print_array(array, size);
		if (array[i] > array[i + 1])
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			last_index = i;
			for (j = last_index; j > 0; j--)
			{
				if (array[j - 1] > array[j])
				{
					print_array(array, size);
					temp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = temp;
				}
			}
		}
	}
}
