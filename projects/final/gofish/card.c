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
    if (card == NULL)
    {
        return;
    }
    for (int h = 0; h < CARD_HEIGHT; h++)
    {
        if (h != 0 && h != CARD_HEIGHT - 1)
        {
            printf("|");
        }
        for (int w = 0; w < CARD_WIDTH; w++)
        {
            if (h == 0 || h == CARD_HEIGHT - 1)
            {
                if (w == 0 || w == CARD_WIDTH - 1)
                {
                    printf(" ");
                }
                else if (h == 0)
                {
                    printf("_");
                }
                else if (h == CARD_HEIGHT - 1)
                {
                    printf("~");
                }
            }
            else
            {
                if (w == CARD_WIDTH - 1)
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        // printf("|\n");
        printf("\n");
    }
    //exit(1);
    // printf("%c of %s\n", card->value, card->suit);
}
