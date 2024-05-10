#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // printf("argc: %d\n", argc);

    if (argc != 2)
    {
        printf("%s requires exactly 1 argument\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *s = argv[1];
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
    printf("%s\n", s);
    return EXIT_SUCCESS;
}
