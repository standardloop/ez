#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUARTER_VAL 25
#define DIME_VAL 10
#define NICKEL_VAL 5
#define PENNY_VAL 1

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("%s requires exactly 1 argument\n", argv[0]);
        return EXIT_FAILURE;
    }

    int amount = atoi(argv[1]);

    if (amount < 0 || amount == 0)
    {
        printf("Please enter an argument that is an integer and is greater than 0\n");
        return EXIT_FAILURE;
    }

    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennies = 0;

    while (amount >= QUARTER_VAL)
    {
        amount -= QUARTER_VAL;
        quarters++;
    }
    while (amount >= DIME_VAL)
    {
        amount -= DIME_VAL;
        dimes++;
    }
    while (amount >= NICKEL_VAL)
    {
        amount -= NICKEL_VAL;
        nickles++;
    }
    while (amount >= PENNY_VAL)
    {
        amount -= PENNY_VAL;
        pennies++;
    }
    if (amount != 0)
    {
        printf("[FATAL]: could not calculate :/%d\n", amount);
        return EXIT_FAILURE;
    }
    printf("Breakdown:\n");
    if (quarters > 0)
    {
        if (quarters == 1)
        {
            printf("%d quarter\n", quarters);
        }
        else
        {
            printf("%d quarters\n", quarters);
        }
    }
    if (dimes > 0)
    {
        if (dimes == 1)
        {
            printf("%d dime\n", dimes);
        }
        else
        {
            printf("%d dimes\n", dimes);
        }
    }
    if (nickles > 0)
    {
        if (nickles == 1)
        {
            printf("%d nickle\n", nickles);
        }
        else
        {
            printf("%d nickles\n", nickles);
        }
    }
    if (pennies > 0)
    {
        if (pennies == 1)
        {
            printf("%d penny\n", pennies);
        }
        else
        {
            printf("%d pennies\n", pennies);
        }
    }
    printf("Total Coins: %d\n", (quarters + dimes + nickles + pennies));
    return EXIT_SUCCESS;
}
