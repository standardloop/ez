#include <stdio.h>
#include <stdlib.h>

#include "./main.h"

#define NULL_CHAR '\0'

int main(void)
{
    Deck *deck = InitDeck();
    if (deck == NULL)
    {
        printf("[FATAL]: Couldn't allocate memory for Deck\n");
        return EXIT_FAILURE;
    }
    (void)PrintDeck(deck);

    (void)ShuffleDeck(deck);

    (void)PrintDeck(deck);

    (void)FreeDeck(deck);

    // size_t josh = 5;
    // char *player_name = malloc(sizeof(char) * josh);
    // if (player_name == NULL)
    // {
    //     FreeDeck(deck);
    //     printf("[FATAL]: Couldn't allocate memory for player name\n");
    //     return EXIT_FAILURE;
    // }

    // // FIXME
    // *(player_name + 0) = 'j';
    // *(player_name + 1) = 'o';
    // *(player_name + 2) = 's';
    // *(player_name + 3) = 'h';
    // *(player_name + 4) = NULL_CHAR;

    // Hand *hand = InitHand(player_name);
    // if (hand == NULL)
    // {
    //     FreeDeck(deck);
    //     free(player_name);
    //     printf("[FATAL]: Couldn't allocate memory for player Hand\n");
    //     return EXIT_FAILURE;
    // }

    // Card *card = GetTopOfDeck(deck);
    // (void)PutCardInHand(hand, card);
    // if (card == NULL)
    // {
    //     FreeHand(hand); // handles memory for player_name
    //     FreeDeck(deck);
    //     printf("[FATAL]: Couldn't add card into player name\n");
    //     return EXIT_FAILURE;
    // }
    // PrintCard(card);
    return EXIT_SUCCESS;
}
