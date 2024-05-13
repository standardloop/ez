#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "./main.h"

int placeCardOnBottomOfDeck(Deck *, Card *);
int placeCardOnTopOfDeck(Deck *, Card *);
int placeCardRandomlyInDeck(Deck *, Card *);

bool isDeckEmpty(Deck *);

bool isDeckEmpty(Deck *deck)
{
    return (deck->size == 0 && deck->cards == NULL);
}

void ShuffleDeck(Deck *deck)
{
    if (deck == NULL || isDeckEmpty(deck))
    {
        for (int i = deck->size - 1; i > 0; i--)
        {
            //int j = rand() % (i + 1);
            Swap();
        }
        return;
    }
}

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

    for (enum Suit curr_suit = Clubs; curr_suit < NUM_SUITS; curr_suit++)
    {
        char *char_suit = NULL;
        switch (curr_suit)
        {
        case Clubs:
            char_suit = "♣";
            break;
        case Diamonds:
            char_suit = "♦";
            break;
        case Hearts:
            char_suit = "♥";
            break;
        case Spades:
            char_suit = "♠";
            break;
        default:
            break;
        }

        for (enum CardValue enum_card_value = Ace; enum_card_value < NUM_CARDS_IN_SUITS; enum_card_value++)
        {
            char *char_card_value;
            switch (enum_card_value)
            {
            case Ace:
                char_card_value = "A";
                break;
            case Two:
                char_card_value = "2";
                break;
            case Three:
                char_card_value = "3";
                break;
            case Four:
                char_card_value = "4";
                break;
            case Five:
                char_card_value = "5";
                break;
            case Six:
                char_card_value = "6";
                break;
            case Seven:
                char_card_value = "7";
                break;
            case Eight:
                char_card_value = "8";
                break;
            case Nine:
                char_card_value = "9";
                break;
            case Ten:
                // char_card_value = "10";
                char_card_value = "T";
                break;
            case Jack:
                char_card_value = "J";
                break;
            case Queen:
                char_card_value = "Q";
                break;
            case King:
                char_card_value = "K";
                break;
            default:
                break;
            }
            // printf("%d %c\n", curr_suit, char_card_value);
            Card *card = InitCard(char_suit, char_card_value);
            if (card == NULL)
            {
                // FIXME mem leak
                printf("Couldn't allocate memory for a card\n");
                exit(EXIT_FAILURE);
                return NULL;
            }
            (void)PlaceCardInDeck(deck, card, 'b');
        }
    }

    if (deck->cards == NULL)
    {
        FreeDeck(deck);
        return NULL;
    }
    if (deck->size != NUM_CARDS_IN_STANDARD_DECK)
    {
        printf("[FATAL]: couldn't create enough cards for deck of size: %d != %d\n", deck->size, NUM_CARDS_IN_STANDARD_DECK);
        exit(1);
    }

    return deck;
}

int PlaceCardInDeck(Deck *deck, Card *card, char mode)
{
    switch (mode)
    {
    case 't':
    case 'T':
        return placeCardOnTopOfDeck(deck, card);
    case 'b':
    case 'B':
        return placeCardOnBottomOfDeck(deck, card);
    case 'r':
    case 'R':
        return placeCardRandomlyInDeck(deck, card);
    default:
        printf("Unsupported mode for placing card in deck");
        return ERROR_FIXME;
    }
}

int placeCardOnBottomOfDeck(Deck *deck, Card *card)
{
    if (deck == NULL || card == NULL)
    {
        return ERROR_FIXME;
    }
    Card *head = deck->cards;
    if (head == NULL)
    {
        deck->cards = card;
        deck->size = 1;
        return deck->size;
    }
    Card *last = deck->cards;

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = card;
    deck->size++;

    return deck->size;
}

int placeCardOnTopOfDeck(Deck *deck, Card *card)
{
    if (deck == NULL || card == NULL)
    {
        return ERROR_FIXME;
    }
    Card *head = deck->cards;
    if (head == NULL)
    {
        deck->cards = card;
        deck->size = 1;
        return deck->size;
    }
    card->next = head;
    deck->cards = card;
    deck->size++;

    return deck->size;
}

int placeCardRandomlyInDeck(Deck *deck, Card *card)
{
    if (deck == NULL || card == NULL)
    {
        return ERROR_FIXME;
    }
    return deck->size;
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

void PrintDeck(Deck *deck)
{
    if (deck == NULL)
    {
        return;
    }
    Card *card_iterator = deck->cards;
    while (card_iterator != NULL)
    {
        (void)PrintCard(card_iterator, true);
        card_iterator = card_iterator->next;
    }
}
