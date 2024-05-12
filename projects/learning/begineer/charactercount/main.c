#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileCharCount(const char *);

int getFileCharCount(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    int char_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch != EOF)
        {
            char_count++;
        }
    }

    fclose(file);
    return char_count;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    int char_count = getFileCharCount(argv[1]);
    if (char_count < 0)
    {
        return EXIT_FAILURE;
    }
    else if (char_count == 1)
    {
        printf("File: %s, contains %d character\n", argv[1], char_count);
    }
    else
    {
        printf("File: %s, contains %d characters\n", argv[1], char_count);
    }
    return EXIT_SUCCESS;
}
