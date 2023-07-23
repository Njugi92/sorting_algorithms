#include "sort.h"
#include <stdbool.h>
/**
 * dll_adj_swap - It swaps two adjacent nodes of a doubly linked
 * list
 *
 * @list: its doubly linked list of integers to be sorted
 * @left: node closer to head, right->prev
 * @right: node closer to tail, left->next
 */
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *swap;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;
	left->prev = right;
	swap = right;
	left->next = right->next;
	swap->next = left;

	print_list(*list);
}
/**
 * cocktail_sort_list - function sorts a doubly linked list of
 * integers in ascending order using a cocktail shaker algorithm.
 *
 * @list: Its doubly linked list of integers to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped_f, swapped_b;
	int shake_range = 1000000, checks;
	listint_t *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	do {
		swapped_f = swapped_b = 0;
		for (checks = 0; tmp->next && checks < shake_range; checks++)
		{
			if (tmp->next->n < tmp->n)
			{
				dll_adj_swap(list, tmp, tmp->next);
				swapped_f = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!tmp->next) /*its first loop measuring list*/
			shake_range = checks;
		if (swapped_f)
			tmp = tmp->prev;
		shake_range--;
		for (checks = 0; tmp->prev && checks < shake_range; checks++)
		{
			if (tmp->n < tmp->prev->n)
			{
				dll_adj_swap(list, tmp->prev, tmp);
				swapped_b = 1;
			}
			else
				tmp = tmp->prev;
		}
		if (swapped_b)
			tmp = tmp->next;
	} while (swapped_f || swapped_b);
}

