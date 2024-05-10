#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALWAYS 1

int main(int argc, char *argv[])
{
    while (ALWAYS)
    {
        printf("%s\n", argc > 1 ? argv[1] : "y");
    }
    return EXIT_SUCCESS;
}
