#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order using
 * the Cocktail Shaker Sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = (*list);
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		current = current->next;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the list.
 * @a: First node to be swapped.
 * @b: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *temp_prev, *temp_next;

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	temp_prev = a->prev;
	temp_next = b->next;

	a->prev = b;
	b->next = a;

	a->next = temp_next;
	b->prev = temp_prev;
}
