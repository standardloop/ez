#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEWLINE_CHAR '\n'

int getFileLineCount(const char *);

int getFileLineCount(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    int line_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == NEWLINE_CHAR)
        {
            line_count++;
        }
    }

    fclose(file);
    return line_count;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    int line_count = getFileLineCount(argv[1]);
    if (line_count < 0)
    {
        return EXIT_FAILURE;
    }
    else if (line_count == 1)
    {
        printf("File: %s, is %d line long\n", argv[1], line_count);
    }
    else
    {
        printf("File: %s, is %d lines long\n", argv[1], line_count);
    }
    return EXIT_SUCCESS;
}
