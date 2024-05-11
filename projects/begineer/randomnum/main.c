#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Please provide at least 1 argument\n");
        return EXIT_FAILURE;
    }
    int max = atoi(argv[1]);
    max++;

    srand(time(NULL));
    int r = rand() % max;
    printf("%d\n", r);

    return EXIT_SUCCESS;
}
