#include "sort.h"
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
	listint_t *new_list = *list,
			  *current_compare,
			  *temp;

	if (*list == NULL)
		return;
	temp = *list;
	while (temp != NULL)
	{
		while (temp->next != NULL &&
			   temp->next->n < temp->n)
		{
			current_compare = temp->next;
			temp->next = current_compare->next;
			current_compare->prev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = current_compare;
			if (current_compare->next != NULL)
				current_compare->next->prev = temp;
			temp->prev = current_compare;
			current_compare->next = temp;
			if (current_compare->prev == NULL)
				new_list = current_compare;
			else
				temp = current_compare->prev;
			print_list(new_list);
		}
		temp = temp->next;
	}
	*list = new_list;
}
