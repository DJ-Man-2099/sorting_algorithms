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
void insertion_sort_list_original(listint_t **list)
{
	listint_t *new_list = *list, *to_compare = NULL,
			  *current_compare = NULL, *current_list = *list;
	size_t n = 0, i;

	if (*list != NULL)
		current_compare = (*list)->next;
	if (current_compare != NULL)
		to_compare = current_compare->next;
	while (current_compare != NULL)
	{
		if (current_compare->prev != NULL)
			current_compare->prev->next = current_compare->next;
		if (current_compare->next != NULL)
			current_compare->next->prev = current_compare->prev;
		if (current_list->n <= current_compare->n)
		{
			for (i = 0; i < n && current_list != NULL &&
						current_list->next != NULL &&
						current_list->next->n < current_compare->n;
				 i++)
				current_list = current_list->next;
			if (current_list != NULL)
			{
				current_compare->prev = current_list;
				if (current_list->next != NULL)
					current_list->next->prev = current_compare;
				current_compare->next = current_list->next;
				current_list->next = current_compare;
			}
		}
		else
		{
			current_compare->prev = NULL;
			current_compare->next = new_list;
			new_list->prev = current_compare;
			new_list = current_compare;
		}
		n++;
		current_compare = to_compare;
		if (i < n - 1)
			print_list(new_list);
		current_list = new_list;
		if (to_compare != NULL)
			to_compare = to_compare->next;
	}
	*list = new_list;
}
