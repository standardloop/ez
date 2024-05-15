#include <stdio.h>

int maxArr(int[], int);
void printArr(int[], int);
int searchArr(int[], int, int);
int minArr(int[], int);

int getFirstArrayElement(int[]);
int getLastArrayElement(int[], int);

void printDivider();

void printArr(int arr[], int n)
{
    printf("Printing Array:\n");
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d]\n", arr[i]);
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
}

int searchArr(int arr[], int n, int x)
{
    printf("Searching for %d ...\n", x);
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

int getFirstArrayElement(int arr[])
{
    return arr[0];
}

int getLastArrayElement(int arr[], int n)
{
    return arr[n - 1];
}

void printDivider()
{
    printf("-------------------------------------------\n");
}

int main(void)
{
    printDivider();
    int arr[] = {2, 12323, 3, 4, 123213, 10, 40, 877672, 42, 1, 6023, 88832};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, n);
    printDivider();

    int result = searchArr(arr, n, x);
    result != -1 ? printf("Element is present at index %d\n", result) : printf("Element is not present in array\n");
    printDivider();
    result = searchArr(arr, n, -3);
    result != -1 ? printf("Element is present at index %d\n", result) : printf("Element is not present in array\n");
    printDivider();
    printf("maxArr element is: %d\n", maxArr(arr, n));
    printDivider();
    printf("minArr element is: %d\n", minArr(arr, n));
    printDivider();
    printf("[0]'th (First) Element %d\n", getFirstArrayElement(arr));
    printDivider();
    printf("[n-1]'th (Last) Element %d\n", getLastArrayElement(arr, n));

    return 0;
}
