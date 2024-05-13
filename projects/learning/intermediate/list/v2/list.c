#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./list.h"

bool isListEmpty(List *);
bool isListFull(List *);
ListNode *newListNode(int);
void freeAllListNodes(ListNode *);
void freeListNode(ListNode *);

List *ListInit(int max)
{
    List *list = malloc(sizeof(List));
    if (list == NULL)
    {
        return NULL;
    }
    list->size = 0;
    list->max = max;
    list->head = NULL;

    return list;
}

ListNode *newListNode(int value)
{
    ListNode *list_node = (ListNode *)malloc(sizeof(ListNode));
    if (list_node == NULL)
    {
        return NULL;
    }
    list_node->next = NULL;
    list_node->value = value;

    return list_node;
}

bool isListEmpty(List *list)
{
    return (list->size == 0);
}

bool isListFull(List *list)
{
    return (list->max == list->size);
}

void ListPrint(List *list)
{
    if (isListEmpty(list))
    {
        return;
    }
    printf("Printing List:\n");
    ListNode *iterator = list->head;
    while (iterator != NULL)
    {
        printf("%d → ", iterator->value);
        // printf("%d -> ", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

int ListAddToFront(List *list, int value)
{

    if (list == NULL || isListFull(list))
    {
        return LIST_ERROR;
    }
    ListNode *list_node = newListNode(value);
    if (list_node == NULL)
    {
        return LIST_ERROR;
    }

    ListNode *head = list->head;
    if (head == NULL)
    {
        list->head = list_node;
        list->size = 1;
        return list->size;
    }
    list_node->next = head;
    list->head = list_node;
    list->size++;
    return list->size;
}

int ListAddToEnd(List *list, int value)
{
    if (list == NULL || isListFull(list))
    {
        return LIST_ERROR;
    }

    ListNode *list_node = newListNode(value);
    if (list_node == NULL)
    {
        return LIST_ERROR;
    }

    ListNode *head = list->head;
    if (head == NULL)
    {
        list->head = list_node;
        list->size = 1;
        return list->size;
    }

    ListNode *last = list->head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = list_node;
    list->size++;

    return list->size;
}

void ListFree(List *list)
{
    if (list == NULL)
    {
        return;
    }
    if (list->head != NULL)
    {
        freeAllListNodes(list->head);
    }
    free(list);
}

void freeAllListNodes(ListNode *head)
{
    ListNode *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        freeListNode(temp);
    }
}

void freeListNode(ListNode *list_node)
{
    if (list_node == NULL)
    {
        return;
    }
    // free the value
    // in our case, we are using int so there is nothing to free
    free(list_node);
}

void ListSwap(List *list, int swap_index_1, int swap_index_2)
{
    if (list == NULL || (swap_index_1 == swap_index_2) || isListEmpty(list) ||
        swap_index_1 < 0 || swap_index_2 < 0 || swap_index_1 > list->size || swap_index_2 > list->size)
    {
        printf("Invalid inputs to ListSwap\n");
        return;
    }
    printf("Swapping index %d and %d!\n", swap_index_1, swap_index_2);
    // ListNode *original_head = list->head;

    ListNode *iterator_1_prev = list->head;
    ListNode *iterator_1 = list->head;

    ListNode *iterator_2_prev = list->head;
    ListNode *iterator_2 = list->head;
    if (swap_index_1 == 0)
    {
        iterator_1_prev = NULL;
    }
    else
    {
        for (int i = 0; i < swap_index_1 - 1; i++)
        {
            iterator_1_prev = iterator_1_prev->next;
        }
    }

    for (int i = 0; i < swap_index_1; i++)
    {
        iterator_1 = iterator_1->next;
    }

    if (swap_index_2 == 0)
    {
        iterator_2_prev = NULL;
    }
    else
    {
        for (int i = 0; i < swap_index_2 - 1; i++)
        {
            iterator_2_prev = iterator_2_prev->next;
        }
    }

    for (int i = 0; i < swap_index_2; i++)
    {
        iterator_2 = iterator_2->next;
    }

    if (iterator_1 == NULL || iterator_2 == NULL || iterator_1 == iterator_2)
    {
        printf("Couldn't located indexes in ListSwap\n");
        return;
    }

    // // error checking complete, swapping begin
    // if (iterator_1_prev == NULL)
    // {
    //     printf("[JOSH]: it_1_prev NULL it_1 %d\n", iterator_1->value);
    // }
    // else
    // {
    //     printf("[JOSH]: it_1_prev %d it_1 %d\n", iterator_1_prev->value, iterator_1->value);
    // }
    // if (iterator_2_prev == NULL)
    // {
    //     printf("[JOSH]: it_2_prev NULL it_2 %d\n", iterator_2->value);
    // }
    // else
    // {
    //     printf("[JOSH]: it_2_prev %d it_2 %d\n", iterator_2_prev->value, iterator_2->value);
    // }

    // exit(1);

    ListNode *temp = iterator_1->next;
    // printf("\n\n[JOSH]: %d\n\n", temp->next->value);
    if (iterator_2_prev != NULL && iterator_2_prev->next == iterator_2)
    {
        iterator_2_prev->next = iterator_1;
    }
    iterator_1->next = iterator_2->next;
    if (iterator_1_prev != NULL && iterator_1_prev->next == iterator_1)
    {
        iterator_1_prev->next = iterator_2;
    }

    iterator_2->next = temp;

    if (swap_index_1 == 0)
    {
        list->head = iterator_2;
    }
    else if (swap_index_2 == 0)
    {
        list->head = iterator_1;
    }

    // printf("\n\n[JOSH]: %d %d\n\n", iterator_1->next->value, iterator_2->next->value);
    return;
}
