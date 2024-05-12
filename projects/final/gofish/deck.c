#include <stdio.h>
#include <stdlib.h>

#include "./main.h"

Deck *InitDeck()
{
    Deck *deck = malloc(sizeof(Deck));
    if (deck == NULL)
    {
        return NULL;
    }
    deck->max = NUM_CARDS_IN_STANDARD_DECK;
    deck->size = 0;

    deck->cards = NULL;

    return deck;
}

void FreeDeck(Deck *deck)
{
    if (deck == NULL)
    {
        return;
    }
    if (deck->cards != NULL)
    {
        (void)FreeAllCards(deck->cards);
    }
    free(deck);
}

Card *GetTopOfDeck(Deck *deck)
{
    if (deck == NULL)
    {
        return NULL;
    }
    return NULL;
}
