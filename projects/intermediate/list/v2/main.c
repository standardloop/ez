#include <stdio.h>
#include <stdlib.h>

#include "./list.h"

int main(void)
{
    List *example = ListInit(20);
    if (example == NULL)
    {
        printf("Could not allocate memory for list!\n");
        return EXIT_FAILURE;
    }
    int list_size;
    list_size = ListAddToEnd(example, 0);

    (void)printf("List Size is now: %d\n", list_size);
    (void)ListPrint(example);
    (void)ListAddToEnd(example, 1);
    (void)ListAddToEnd(example, 2);
    (void)ListAddToEnd(example, 3);
    (void)ListAddToEnd(example, 4);
    (void)ListAddToEnd(example, 5);
    (void)ListAddToEnd(example, 6);
    (void)ListAddToEnd(example, 7);
    (void)ListAddToEnd(example, 8);
    (void)ListAddToFront(example, -1);
    (void)ListAddToEnd(example, 9);
    (void)ListAddToEnd(example, 10);
    (void)ListAddToFront(example, -2);

    (void)ListPrint(example);

    (void)ListFree(example);

    return EXIT_SUCCESS;
}
