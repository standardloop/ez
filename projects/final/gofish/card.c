#include <stdio.h>
#include <stdlib.h>

#include "./main.h"

Card *InitCard()
{
    return NULL;
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

void PrintCard(Card *card)
{
    switch (card->suit)
    {
    case Hearts:
        printf("Value: %c\nSuit: %s\n", card->value, "♥");
        // for (int i = 0; i < CARD_HEIGHT; i++)
        // {
        //     if (i == 0)
        //     {
        //         printf("┌");
        //     }
        //     else
        //     {
        //         printf("|");
        //     }

        //     for (int j = 0; j < CARD_WIDTH; j++)
        //     {
        //         if (j == CARD_WIDTH - 1)
        //         {
        //             printf("┐");
        //         }
        //         else
        //         {
        //             printf("─");
        //         }
        //     }

        //     if (1)
        //     {
        //         printf("\n");
        //     }
        // }

        break;
    case Diamonds:
        printf("Value: %c\nSuit: %s\n", card->value, "♦");
        break;
    case Spades:
        printf("Value: %c\nSuit: %s\n", card->value, "♠");
        break;
    case Clubs:
        printf("Value: %c\nSuit: %s\n", card->value, "♣");
        break;
    default:
        break;
    }
}
