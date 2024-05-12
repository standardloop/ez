#include <stdio.h>
#include <stdlib.h>

#include "./main.h"

Card *InitCard(char *suit, char value)
{
    Card *card = malloc(sizeof(Card));
    if (card == NULL)
    {
        return NULL;
    }
    card->suit = suit;
    card->value = value;
    card->next = NULL;
    return card;
}

void FreeCard(Card *card)
{
    if (card == NULL)
    {
        return;
    }
    free(card);
}

void FreeAllCards(Card *head)
{
    Card *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        FreeCard(temp);
    }
}

// FIXME
// Cool Ascii art need for this one;
void PrintCard(Card *card)
{
    printf("%c of %s\n", card->value, card->suit);
}
