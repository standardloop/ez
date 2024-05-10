#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int r;
    for (int i = 1; i <= 100; i++)
    {
        fflush(stdout);
        printf("\rProgress ... %d ", i);
        if (i < 20)
        {
            r = rand() % 30;
        }
        else if (i >= 70)
        {
            r = rand() % 6;
        }
        else if (i >= 90)
        {
            r = rand() % 3;
        }
        else
        {
            r = rand() % 10;
        }
        usleep(10000 * r); /* Sleep 100000 micro seconds = 100 ms, etc. */
    }
    printf("\nDONE!\n");
    return EXIT_SUCCESS;
}
