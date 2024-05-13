#include <stdio.h>
#include <stdlib.h>

#include "./list.h"

int main(void)
{
    List *list = ListInit(20);
    if (list == NULL)
    {
        printf("Could not allocate memory for list!\n");
        return EXIT_FAILURE;
    }
    int list_size;
    list_size = ListAddToEnd(list, -1);

    (void)printf("List Size is now: %d\n", list_size);
    (void)ListPrint(list);

    for (int i = 0; i < 11; i++)
    {
        (void)ListAddToEnd(list, i);
    }
    (void)ListPrint(list);

    printf("Deleting First and Last!\n");
    (void)ListDelete(list, 0);
    (void)ListDelete(list, list->size - 1);

    (void)ListPrint(list);

    (void)ListSwap(list, 0, 1);
    (void)ListSwap(list, 1, 0);
    (void)ListSwap(list, 0, list->size - 1);
    (void)ListSwap(list, 8, 0);
    (void)ListSwap(list, 8, 9);
    (void)ListSwap(list, 1, 3);

    (void)ListPrint(list);
    (void)ListFree(list);

    return EXIT_SUCCESS;
}
