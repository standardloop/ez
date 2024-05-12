#include <stdio.h>
#include <stdlib.h>

#include "./main.h"

Hand *InitHand(char *name)
{
    if (name == NULL)
    {
        return NULL;
    }
    Hand *hand = malloc(sizeof(Hand));
    if (hand == NULL)
    {
        return NULL;
    }
    hand->max = HAND_MAX_SIZE;
    hand->size = 0;
    hand->cards = NULL;
    hand->name = name;

    return hand;
}

int PutCardInHand(Hand *hand, Card *card)
{
    if (hand == NULL || card == NULL)
    {
        return -1;
    }
    return hand->size;
}

void FreeHand(Hand *hand)
{
    if (hand == NULL)
    {
        return;
    }
    if (hand->cards != NULL)
    {
        FreeAllCards(hand->cards);
    }
    if (hand->name != NULL)
    {
        free(hand->name);
    }
    free(hand);
}
