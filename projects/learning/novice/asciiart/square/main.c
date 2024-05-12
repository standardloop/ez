#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // printf("argc: %d\n", argc);

    if (argc != 3)
    {
        printf("%s requires exactly 2 argument\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *art = argv[1];
    int art_size = atoi(argv[2]);
    for (int i = 0; i < art_size; i++)
    {
        for (int j = 0; j < art_size; j++)
        {
            printf("%s ", art);
        }
        printf("\n");
    }
    // printf("\n");
    return EXIT_SUCCESS;
}
