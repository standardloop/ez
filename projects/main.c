#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a character: ");
    char c = getchar();

    if (c == 'y' || c == 'Y')
    {
        printf("Agreed!\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not Agreed!\n");
    }
    else
    {
        printf("[DEBUG]: %c\n", (char)c);
        printf("[DEBUG]: %d\n", (int)c);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
