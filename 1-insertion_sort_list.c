#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a DLL of integers in
 * ascending order using the insertion sort
 * algorithm
 *
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current_compare;

	if (!list)
		return;

	temp = *list;

	while (temp)
	{
		while (temp->next && (temp->n > temp->next->n))
		{
			current_compare = temp->next;
			temp->next = current_compare->next;
			current_compare->prev = temp->prev;

			if (temp->prev)
				temp->prev->next = current_compare;

			if (current_compare->next)
				current_compare->next->prev = temp;

			temp->prev = current_compare;
			current_compare->next = temp;

			if (current_compare->prev)
				temp = current_compare->prev;
			else
				*list = current_compare;

			print_list(*list);
		}
		temp = temp->next;
	}
}
