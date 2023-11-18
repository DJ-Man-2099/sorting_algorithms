#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
/**
 * swap - List Function
 *
 * @a: 1st node
 * @b: 2nd node
 *
 * swaps a and b
 *
 * Return: void
 */
void swap(listint_t **a, listint_t **b)
{
	(*a)->next = (*b)->next;
	(*b)->prev = (*a)->prev;
	if ((*a)->prev != NULL)
		(*a)->prev->next = (*b);
	if ((*b)->next != NULL)
		(*b)->next->prev = (*a);
	(*b)->next = (*a);
	(*a)->prev = (*b);
}
