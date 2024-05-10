#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Please provide at least 1 argument\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        (void)printf("%s\n", argv[i]);
    }
    return EXIT_SUCCESS;
}
