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
    List *list = (List *)malloc(sizeof(List));
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
    if (list->head != NULL)
    {
        freeAllListNodes(list->head);
    }
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
