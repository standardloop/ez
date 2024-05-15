#include <stdio.h>

int maxArr(int[], int);
void printArr(int[], int);
int searchArr(int[], int, int);
int minArr(int[], int);

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchArr(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int maxArr(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int minArr(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = searchArr(arr, n, x);
    result != -1 ? printf("Element is present at index %d\n", result) : printf("Element is not present in array\n");
    result = searchArr(arr, n, -3);
    result != -1 ? printf("Element is present at index %d\n", result) : printf("Element is not present in array\n");
    printf("maxArr element is: %d\n", maxArr(arr, n));
    printf("minArr element is: %d\n", minArr(arr, n));

    return 0;
}
