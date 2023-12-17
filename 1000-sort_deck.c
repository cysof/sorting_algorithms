#include "deck.h"

/**
 * card_compare - Compare two card_t structures.
 * Used by qsort to sort the array of cards.
 * @a: Pointer to the first card_t.
 * @b: Pointer to the second card_t.
 * Return: -1 if a < b, 0 if a == b, 1 if a > b.
 */
int card_compare(const void *a, const void *b)
{
	card_t *card_a = *((card_t **)a);
	card_t *card_b = *((card_t **)b);

	/* First, compare the kind (SPA, HEART, CLUB, DIAMOND) */
	if (card_a->kind < card_b->kind)
	{
		return (-1);
	}
	else if (card_a->kind > card_b->kind)
	{
		return (1);
	}
	else
	{
		/* If kind is the same, compare the values */
		return (strcmp(card_a->value, card_b->value));
	}
}

/**
 * create_card - Create a new card_t with the same values.
 * @value: Value of the card.
 * @kind: Kind of the card (SPADE, HEART, CLUB, DIAMOND).
 * Return: A new card_t.
 */
card_t *create_card(const char *value, kind_t kind)
{
	card_t *new_card = malloc(sizeof(card_t));
	if (new_card == NULL)
	{
		// Handle memory allocation error if needed.
		return NULL;
	}
	new_card->value = value;
	new_card->kind = kind;
	return new_card;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	card_t *cards[52];
	deck_node_t *current = *deck;
	int i = 0;

	/* Create an array from the deck */
	while (current)
	{
		cards[i] = malloc(sizeof(card_t));
		if (cards[i] == NULL)
		{
			/* Handle memory allocation error if needed. */
			return;
		}
		cards[i]->value = current->card->value;
		cards[i]->kind = current->card->kind;
		current = current->next;
		i++;
	}

	/* Sort the array using qsort */
	qsort(cards, i, sizeof(card_t *), card_compare);

	/* Rebuild the linked list */
	current = *deck;
	i = 0;
	while (current)
	{
		current->card = cards[i];
		current = current->next;
		i++;
	}

	/* Free dynamically allocated card_t structures */
	for (i = 0; i < 52; i++)
	{
		free(cards[i]);
	}
}
