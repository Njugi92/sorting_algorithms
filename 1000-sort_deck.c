#include "deck.h"
#include <stdio.h>
/**
 * strcmp - It compares two strings.
 * @str1: The first string.
 * @str2: The last string.
 * Return: Returns 1 if str1 is equal to str2,
 * and 0 if they are not equal.
 */
int _strcmp(const char *str1, char *str2)
{
	size_t k = 0;

	if (*str1 == '\0')
		return (0);
	while (str1[k])
	{
		if (str1[k] != str2[k])
			return (0);
		k++;
	}
	if (str1[k] == '\0' && str2[k])
		return (0);
	return (1);
}
/**
 * get_card_position - It returns position based on
 * card you put in
 * @node: This represents a card.
 * Return: Returns the card position.
 */
int get_card_position(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}
/**
 * swap_card - It swaps a card for the previous one.
 * @card: card
 * @deck: the card deck
 * Return: It returns a pointer to a card entered
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}
/**
 * insertion_sort_deck - The function that sorts a doubly linked
 * deck of integers in ascending order using the insertion sort
 * algorithm
 *
 * @deck: The double linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int value_prev, value_current;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		/*the previous value*/
		if (node->prev)
		{
			value_prev = get_card_position((node->prev));
			value_current = get_card_position(node);
		}
		while ((node->prev) && (value_prev > value_current))
		{
			value_prev = get_card_position((node->prev));
			value_current = get_card_position(node);
			node = swap_card(node, deck);
		}
		node = node->next;
	}
}
/**
 * sort_deck - This sorts a deck you insert using insertion
 * sort algorithm
 * @deck: deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
