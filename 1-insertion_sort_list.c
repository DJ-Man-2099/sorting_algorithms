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
              *current = (*list)->next,
              *old_list = *list,
              *temp_prev,
              *print_head = *list;

    while (old_list != NULL)
    {
        old_list = old_list->next;

        while (new_list != NULL &&
               new_list->next != NULL &&
               new_list->next->n < current->n)
            new_list = new_list->next;

        temp_prev = current->prev;
        current->prev = new_list;
        current->next = new_list->next;
        new_list->next = current;

        print_list(print_head);
    }

    *list = new_list;
}