#include "sort.h"
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
	listint_t *new_list, *forward_compare, *forward_start,
		*reverse_compare, *reverse_start, *temp;
	int forward = 0, i;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	new_list = *list;
	forward_start = *list;
	while (forward_start != reverse_start)
	{
		for (i = 0; i < forward; i++)
			forward_start = forward_start->next;
		forward_compare = forward_start;
		temp = forward_start->next;
		while (temp != NULL)
		{
			if (temp != NULL && temp->n < forward_compare->n)
			{
				swap(&forward_compare, &temp);
				if (temp->prev == NULL)
					new_list = temp;
				print_list(new_list);
			}
			forward_compare = temp;
			temp = temp->next;
		}
		reverse_start = forward_compare->prev;
		for (i = 0; i < forward; i++)
			reverse_start = reverse_start->prev;
		forward++;
		reverse_compare = reverse_start;
		temp = reverse_start->prev;
		while (temp != NULL)
		{
			if (temp != NULL && temp->n > reverse_compare->n)
			{
				swap(&temp, &reverse_compare);
				if (reverse_compare->prev == NULL)
					new_list = reverse_compare;
				print_list(new_list);
			}
			reverse_compare = temp;
			temp = temp->prev;
		}
		forward_start = reverse_compare->next;
	}
	*list = new_list;
}
