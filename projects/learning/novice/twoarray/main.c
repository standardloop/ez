#include <stdio.h>
#include <math.h>

int maxArr(int[], int);
void printArr(int[], int);
int searchArr(int[], int, int);
int minArr(int[], int);

int getFirstArrayElement(int[]);
int getLastArrayElement(int[], int);
void joshTestFunction(int[], int);

void printDivider();

void joshTestFunction(int arr[], int n)
{
    for (int i = 0; i < (n * n); i++)
    {
        printf("%d ", arr[i % n - 1]);
    }
}

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

int commons(int x[], int y[], int size)
{
    int common = 0;
    for (int i = 0; i < size; i++)
    {
        if (x[i] == y[i])
        {
            common++;
        }
    }
    return common;
}

#define ARRAY_SIZE 5

int main(void)
{
    int arr_1[ARRAY_SIZE] = {10, 8, 20, 5, 2};
    int arr_2[ARRAY_SIZE] = {1, 8, 20, 6, 2};

    printf("arrays have: %d common elements\n", commons(arr_1, arr_2, ARRAY_SIZE));

    return 0;
}
