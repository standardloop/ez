#include <stdio.h>
#include <stdlib.h>

#include "./main.h"

int main(void)
{
    Deck *deck = InitDeck();
    if (deck == NULL)
    {
        printf("[FATAL]: Couldn't allocate memory for Deck\n");
        return EXIT_FAILURE;
    }

    ShuffleDeck(deck);
    // PrintCards(deck->cards);

    Hand *josh_hand = InitHand("Josh");
    if (josh_hand == NULL)
    {
        FreeDeck(deck);
        printf("[FATAL]: Couldn't allocate memory for player Hand\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; i++)
    {
        Card *card = GetTopOfDeck(deck);
        if (card == NULL)
        {
            FreeHand(josh_hand);
            FreeDeck(deck);
            printf("[FATAL]: Couldn't add card into player name\n");
            return EXIT_FAILURE;
        }
        (void)PutCardInHand(josh_hand, card);
    }

    PrintCards(josh_hand->cards, false);
    printf("Deck has %d Cards and %s's Hand has %d Cards!\n", deck->size, josh_hand->name, josh_hand->size);
    FreeHand(josh_hand);
    FreeDeck(deck);
    return EXIT_SUCCESS;
}
