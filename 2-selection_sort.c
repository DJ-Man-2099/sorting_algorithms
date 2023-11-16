#include "sort.h"
/**
 * selection_sort - Sorting function
 *
 * @array: array to sort
 * @size: size of array
 *
 * sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_j;
	int temp, min;

	if (size >= 2)
		for (i = 0; i < size - 1; i++)
		{
			min = array[i];
			min_j = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < min)
				{
					min_j = j;
					min = array[j];
				}
			}
			if (i != min_j)
			{
				temp = array[i];
				array[i] = min;
				array[min_j] = temp;
				print_array(array, size);
			}
		}
}
