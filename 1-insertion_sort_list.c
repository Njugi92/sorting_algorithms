#include "sort.h"
/**
 * insertion_sort_list - Function sorts a doubly linked list of integers
 * in ascending order using an insertion sort algorithm
 * @list: Its doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *start, *follow, *new, *tmp;

	if (!list || !(*list) || !((*list)->next))
		return;

	follow = (*list);
	start = (*list)->next;
	while (start)
	{
		new = start->next;
		while (follow && start->n < follow->n)
		{
			/*start and follow swap position*/
			if (follow->prev)
				follow->prev->next = start;
			else
				*list = start;
			if (start->next)
				start->next->prev = follow;
			tmp = start->next;
			start->next = follow;
			start->prev = follow->prev;
			follow->next = tmp;
			follow->prev = start;
			print_list(*list);
			follow = start->prev;
		}
		/*start sorted to left, new cycle starts at right edge*/
		start = new;
		if (start)
			follow = start->prev;
	}
}
