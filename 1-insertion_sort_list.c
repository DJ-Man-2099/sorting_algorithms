#include "sort.h"
/**
 * insertion_sort_list - Sorting function
 *
 * @array: array to sort
 * @size: length of array
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
              *to_compare = NULL,
              *current_compare = NULL,
              *current_list = *list;
    size_t n = 1, i;

    if (*list != NULL)
        current_compare = (*list)->next;
    if (current_compare != NULL)
        to_compare = current_compare->next;

    while (current_compare != NULL)
    {
        i = 0;
        if (current_list->n <= current_compare->n)
        {
            while (i < n &&
                   current_list != NULL &&
                   current_list->next != NULL &&
                   current_list->next->n < current_compare->n)
            {
                current_list = current_list->next;
                i++;
            }
        }
        current_compare->prev = current_list->prev;
        current_list->next = current_compare->next;
        current_compare->next = current_list;
        current_list->prev = current_compare;
        n++;
        current_compare = to_compare;
        current_list = new_list;
        if (to_compare != NULL)
            to_compare = to_compare->next;
    }
    /*on swap only*/
    print_list(new_list);
}