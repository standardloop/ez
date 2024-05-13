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
    printf("Printing List:\n");
    if (isListEmpty(list) || list == NULL)
    {
        printf("List is empty!\n");
        return;
    }

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

int ListDelete(List *list, int index)
{
    if (list == NULL || isListEmpty(list) || index > list->size - 1)
    {
        return LIST_ERROR;
    }
    if (index == 0)
    {
        ListNode *temp = list->head;
        list->head = list->head->next;
        (void)freeListNode(temp);
        list->size--;
        return list->size;
    }
    ListNode *index_node = list->head;
    ListNode *index_node_prev = list->head;

    for (int i = 0; i < index - 1; i++)
    {
        index_node_prev = index_node_prev->next;
    }

    for (int i = 0; i < index; i++)
    {
        index_node = index_node->next;
    }
    index_node_prev->next = index_node->next;
    freeListNode(index_node);
    list->size--;
    return list->size;
}

void ListSwap(List *list, int swap_index_1, int swap_index_2)
{
    if (list == NULL || (swap_index_1 == swap_index_2) || isListEmpty(list) || list->head == NULL ||
        swap_index_1 < 0 || swap_index_2 < 0 || swap_index_1 > list->size || swap_index_2 > list->size)
    {
        printf("Invalid inputs to ListSwap\n");
        return;
    }
    if (swap_index_1 > swap_index_2)
    {
        ListSwap(list, swap_index_2, swap_index_1);
        return;
    }
    printf("Swapping index %d and %d!\n", swap_index_1, swap_index_2);
    ListNode *swap_index_1_ptr = list->head;
    ListNode *swap_index_1_prev_ptr = NULL;
    ListNode *swap_index_2_ptr = list->head;
    ListNode *swap_index_2_prev_ptr = NULL;

    for (int i = 0; i < swap_index_1; i++)
    {
        swap_index_1_prev_ptr = swap_index_1_ptr;
        swap_index_1_ptr = swap_index_1_ptr->next;
    }
    for (int i = 0; i < swap_index_2; i++)
    {
        swap_index_2_prev_ptr = swap_index_2_ptr;
        swap_index_2_ptr = swap_index_2_ptr->next;
    }

    if (swap_index_1_ptr == NULL || swap_index_2_ptr == NULL)
    {
        printf("Couldn't located nodes at index in ListSwap\n");
        return;
    }
    // only need to check head for swap_index_1 because
    // swap_index_1 is always less than swap_index_2
    if (swap_index_1_prev_ptr == NULL && swap_index_1_ptr == list->head)
    {
        list->head = swap_index_2_ptr;
    }
    else
    {
        swap_index_1_prev_ptr->next = swap_index_2_ptr;
    }

    swap_index_2_prev_ptr->next = swap_index_1_ptr;
    ListNode *temp = swap_index_1_ptr->next;
    swap_index_1_ptr->next = swap_index_2_ptr->next;
    swap_index_2_ptr->next = temp;
}
