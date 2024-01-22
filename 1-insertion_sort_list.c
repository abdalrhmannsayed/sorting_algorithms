#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm
 * @list: the list to sort
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		prev = current->prev;

		while (prev && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
			prev = current->prev;
		}
		current = next;
	}
}
