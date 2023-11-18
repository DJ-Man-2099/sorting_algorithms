#include "sort.h"
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
/**
 * insertion_sort_list - Sorting function
 *
 * @list: list to sort
 *
 * sorts a doubly linked list of integers
 * in ascending order
 * using the Insertion sort algorithm
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new_list,
		*current_compare,
		*temp;

	if (list == NULL || *list == NULL ||
		(*list)->next == NULL)
		return;
	new_list = *list;
	temp = *list;
	current_compare = (*list)->next;
	while (current_compare != NULL)
	{
		while (temp != NULL &&
			   current_compare->n < temp->n)
		{
			swap(&temp, &current_compare);
			if (current_compare->prev == NULL)
			{
				new_list = current_compare;
				print_list(new_list);
				break;
			}
			print_list(new_list);
			current_compare = current_compare->prev;
			temp = current_compare->prev;
		}
		temp = current_compare;
		current_compare = current_compare->next;
	}
	*list = new_list;
}
