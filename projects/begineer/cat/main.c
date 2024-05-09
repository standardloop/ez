#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(const char *);

void printFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    (void)printFile(argv[1]);
    return EXIT_SUCCESS;
}
