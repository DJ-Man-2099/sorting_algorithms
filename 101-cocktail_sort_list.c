#include "sort.h"
/**
 * swap2 - List Function
 *
 * @a: 1st node
 * @b: 2nd node
 *
 * swap2s a and b
 *
 * Return: void
 */
void swap2(listint_t **a, listint_t **b)
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
 * cocktail_sort_list - Sorting function
 *
 * @list: list to sort
 *
 * sorts a doubly linked list of integers
 * in ascending order
 * using the Cocktail shaker sort algorithm
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *forward_compare, *forward_start,
		*reverse_compare, *reverse_start, *temp;
	int forward = 0, i;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	forward_start = *list;
	for (; forward_start != reverse_start; forward++)
	{
		for (i = 0; i < forward; i++)
			forward_start = forward_start->next;
		if (forward_start != reverse_start)
			break;
		forward_compare = forward_start;
		temp = forward_start->next;
		while (temp != NULL)
		{
			if (temp != NULL && temp->n < forward_compare->n)
			{
				swap2(&forward_compare, &temp);
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
			}
			forward_compare = temp;
			temp = temp->next;
		}
		reverse_start = forward_compare->prev;
		for (i = 0; i < forward + 1; i++)
			reverse_start = reverse_start->prev;
		reverse_compare = reverse_start;
		temp = reverse_start->prev;
		while (temp != NULL)
		{
			if (temp != NULL && temp->n > reverse_compare->n)
			{
				swap2(&temp, &reverse_compare);
				if (reverse_compare->prev == NULL)
					*list = reverse_compare;
				print_list(*list);
			}
			reverse_compare = temp;
			temp = temp->prev;
		}
		forward_start = reverse_compare->next;
	}
}
