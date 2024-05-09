#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createNewFile(const char *);

void createNewFile(const char *filename)
{

    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        printf("File %s already exists!\n", filename);
        fclose(file);
        return;
    }
    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Unable to create file %s\n", filename);
        return;
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    createNewFile(argv[1]);

    return EXIT_SUCCESS;
}
