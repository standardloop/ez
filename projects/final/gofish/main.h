#ifndef MAIN_H
#define MAIN_H

#define NUM_CARDS_IN_STANDARD_DECK 52 // no jokers for now
#define HAND_MAX_SIZE 52
#define NUM_SUITS 4

#define CARD_WIDTH 5
#define CARD_HEIGHT 10

enum Suit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades,
};

typedef struct card
{
    struct card *next;
    enum Suit suit;
    char value;
} Card;

typedef struct
{
    int max;
    int size;
    Card *cards;
    char *name;
} Hand;

typedef struct
{
    int max;
    int size;
    Card *cards;
} Deck;

void PrintCard(Card *);
void FreeCard(Card *);
void FreeAllCards(Card *);

int PutCardInHand(Hand *, Card *);
Card *GetTopOfDeck(Deck *);

Hand *InitHand(char *);
void FreeHand(Hand *);

Deck *InitDeck();
void FreeDeck(Deck *);

#endif
