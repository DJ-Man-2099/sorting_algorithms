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
 * get_end - List Operation
 * @list: list to sort
 *
 * gets end of list
 *
 * Return: end of list
 */
listint_t *get_end(listint_t *list)
{
	while (list->next != NULL)
		list = list->next;

	return (list);
}
/**
 * cocktail_forward - Cocktail Sort Operation
 * @list: list to sort
 * @start: start of list to sort
 * @count: steps taken
 *
 * sorts the list in the forward direction
 *
 * Return: void
 */
void cocktail_forward(listint_t **list, listint_t *start, int count)
{
	listint_t *temp;
	int i;

	temp = start->next;
	while (temp != NULL)
	{
		if (temp != NULL && temp->n < start->n)
		{
			swap2(&start, &temp);
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		start = temp;
		temp = temp->next;
	}
}
/**
 * cocktail_reverse - Cocktail Sort Operation
 * @list: list to sort
 * @start: start of list to sort
 * @count: steps taken
 *
 * sorts the list in the reverse direction
 *
 * Return: void
 */
void cocktail_reverse(listint_t **list, listint_t *start, int count)
{
	listint_t *temp;
	int i;

	temp = start->prev;
	while (temp != NULL)
	{
		if (temp != NULL && temp->n > start->n)
		{
			swap2(&temp, &start);
			if (start->prev == NULL)
				*list = start;
			print_list(*list);
		}
		start = temp;
		temp = temp->prev;
	}
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
	listint_t *forward_start, *start,
		*reverse_start, *end;
	int count = 0, i;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	start = *list;
	forward_start = start;
	end = get_end(*list);
	while (forward_start != NULL && forward_start != reverse_start)
	{
		cocktail_forward(list, forward_start, count);

		reverse_start = end;
		for (i = 0; i < count; i++)
			reverse_start = reverse_start->prev;

		if (forward_start == reverse_start)
			break;

		count++;
		cocktail_reverse(list, reverse_start, count);

		forward_start = start;
		for (i = 0; i < count; i++)
			forward_start = forward_start->next;
	}
}
