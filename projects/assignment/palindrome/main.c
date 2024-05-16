#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *);

bool isPalindrome(char *str)
{
    int low = 0;
    int high = strlen(str) - 1;

    while (low < high)
    {
        if (str[low] != str[high])
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Need an input string!\n");
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; i++)
    {
        if (isPalindrome(argv[i]))
        {
            printf("%s is a palindrome\n", argv[i]);
        }
        else
        {
            printf("%s is not a palindrome\n", argv[i]);
        }
    }
    return EXIT_SUCCESS;
}
