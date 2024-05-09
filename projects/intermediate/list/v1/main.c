#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    struct list *next;
    int value;
} List;

int main(void)
{
    // Create List head
    List *head = NULL;
    head = (List *)malloc(sizeof(List));
    if (head == NULL)
    {
        return EXIT_FAILURE;
    }
    head->value = 0;
    head->next = NULL;

    // Insert at end
    List *current = NULL;
    current = (List *)malloc(sizeof(List));
    if (current == NULL)
    {
        return EXIT_FAILURE;
    }
    current->value = 1;
    current->next = NULL;
    head->next = current;

    // Insert at front
    current = NULL;
    current = (List *)malloc(sizeof(List));
    if (current == NULL)
    {
        return EXIT_FAILURE;
    }
    current->value = -1;
    current->next = head;
    head = current;

    // Print List
    printf("Printing List:\n");
    List *iterator = head;

    while (iterator != NULL)
    {
        printf("%d -> ", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");

    // Free List
    List *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
