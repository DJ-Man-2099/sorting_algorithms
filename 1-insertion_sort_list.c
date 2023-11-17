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

	if (list == NULL || *list == NULL ||
		(*list)->next == NULL)
		return;
	temp = *list;
	current_compare = (*list)->next;
	while (current_compare != NULL)
	{
		while (temp != NULL &&
			   current_compare->n < temp->n)
		{
			temp->next = current_compare->next;
			current_compare->prev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = current_compare;
			if (current_compare->next != NULL)
				current_compare->next->prev = temp;
			current_compare->next = temp;
			temp->prev = current_compare;
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
