#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list in ascending order
 * using the Insertion algorithm.
 *
 * @list: Pointer to the head of the list.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		sorted = current;
		current = current->next;

		while (sorted->prev && sorted->n < sorted->prev->n)
		{
			temp = sorted->prev;

			if (sorted->next)
				sorted->next->prev = temp;
			temp->next = sorted->next;
			sorted->next = temp;
			sorted->prev = temp->prev;
			temp->prev = sorted;

			if (sorted->prev)
				sorted->prev->next = sorted;
			else
				*list = sorted;

			/* print list after each swap */
			print_list(*list);
		}
	}
}
