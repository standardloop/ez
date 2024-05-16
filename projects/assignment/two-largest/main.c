#include <stdio.h>
#include <math.h>

typedef struct
{
    int one;
    int two;
} TwoLarge;

TwoLarge findTwoLargestElements(int[], int);

TwoLarge findTwoLargestElements(int arr[], int n)
{
    TwoLarge answer;

    if (arr[0] >= arr[1])
    {
        answer.one = arr[0];
        answer.two = arr[1];
    }
    else
    {
        answer.one = arr[1];
        answer.two = arr[0];
    }

    if (n != 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > answer.one)
            {
                answer.two = answer.one;
                answer.one = arr[i];
            }
            else if (arr[i] > answer.two)
            {
                answer.two = arr[i];
            }
        }
    }
    return answer;
}

int main(void)
{
    int arr[] = {0, 13, -4, 8, 100, 4, 84, 5, 32, 9, -11, 4, 74};
    int n = sizeof(arr) / sizeof(arr[0]);

    TwoLarge answer = findTwoLargestElements(arr, n);

    printf("Largest: %d, Second Largest: %d\n", answer.one, answer.two);

    return 0;
}
