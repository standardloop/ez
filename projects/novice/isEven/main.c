#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Please provide at least 1 argument\n");
        return EXIT_FAILURE;
    }
    int num = atoi(argv[1]);

    if (num % 2 == 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }

    return EXIT_SUCCESS;
}
