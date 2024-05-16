#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_CHAR ' '

int getFileWordCount(const char *);

int getFileWordCount(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    int word_count = 1;
    int char_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch != EOF)
        {
            char_count++;
        }
        if (ch == SPACE_CHAR)
        {
            word_count++;
        }
    }
    if (char_count == 0)
    {
        word_count--;
    }

    fclose(file);
    return word_count;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    int word_count = getFileWordCount(argv[1]);
    if (word_count < 0)
    {
        return EXIT_FAILURE;
    }
    else if (word_count == 0)
    {
        printf("File: %s, does not contain any words\n", argv[1]);
    }
    else if (word_count == 1)
    {
        printf("File: %s, contains %d word\n", argv[1], word_count);
    }
    else
    {
        printf("File: %s, contains %d words\n", argv[1], word_count);
    }
    return EXIT_SUCCESS;
}
