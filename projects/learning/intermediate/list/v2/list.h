#ifndef LIST_H
#define LIST_H

#define LIST_ERROR -1

typedef struct listNode
{
    struct listNode *next;
    int value;
} ListNode;

typedef struct
{
    ListNode *head;
    int size;
    int max;
} List;

List *ListInit(int);

int ListAddToEnd(List *, int);
int ListAddToFront(List *, int);
void ListPrint(List *);
void ListFree(List *);

#endif
