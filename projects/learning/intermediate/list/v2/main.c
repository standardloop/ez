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
    list_size = ListAddToEnd(list, 0);

    (void)printf("List Size is now: %d\n", list_size);
    (void)ListPrint(list);
    (void)ListAddToEnd(list, 1);
    (void)ListAddToEnd(list, 2);
    (void)ListAddToEnd(list, 3);
    (void)ListAddToEnd(list, 4);
    (void)ListAddToEnd(list, 5);
    (void)ListAddToEnd(list, 6);
    (void)ListAddToEnd(list, 7);
    (void)ListAddToEnd(list, 8);
    (void)ListAddToFront(list, -1);
    (void)ListAddToEnd(list, 9);
    (void)ListAddToEnd(list, 10);
    (void)ListAddToFront(list, -2);
    (void)ListPrint(list);

    (void)ListDelete(list, 0);
    (void)ListDelete(list, list->size - 1);

    (void)ListPrint(list);

    (void)ListSwap(list, 0, 1);
    (void)ListPrint(list);

    // (void)ListSwap(list, 8, 0);
    // (void)ListPrint(list);

    // (void)ListSwap(list, 8, 9);
    // (void)ListPrint(list);

    // (void)ListSwap(list, 1, 3);

    (void)ListFree(list);
    return EXIT_SUCCESS;
}
