#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main()
{

    srand(time(NULL));
    int r = rand();

    // even number
    if (r % 2 == 0)
    {
        printf("Heads!\n");
    }
    else
    {
        printf("Tails!\n");
    }
    return EXIT_SUCCESS;
}
