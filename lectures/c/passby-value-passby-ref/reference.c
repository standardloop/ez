#include <stdio.h>
#include <stdlib.h>

void swap(int *pFirstVariable, int *pSecondVariable)
{
    int temp;
    temp = *pFirstVariable;
    *pFirstVariable = *pSecondVariable;
    *pSecondVariable = temp;
}

int main(void)
{
    int a = 100;
    int b = 200;

    printf("before swap: value of a: %d \n", a);
    printf("before swap: value of b: %d \n", b);

    swap(&a, &b);

    printf("after swap: value of a: %d \n", a);
    printf("after swap: value of b: %d \n", b);

    return 0;
}
