#include <cs50.h>
#include <stdio.h>

int check_coins(int input);

int main()
{
    int owed;
    do
    {
        owed = get_int("Change Owed: ");
    }
    while (owed < 0);
    int coins = check_coins(owed);

    printf("Number of coins needed: %i\n", coins);
}

int check_coins(int input)
{
    int coins = 0;
    int remainder;

    coins += input / 25;
    remainder = input % 25;

    coins += remainder / 10;
    remainder = remainder % 10;

    coins += remainder / 5;
    remainder = remainder % 5;

    coins += remainder / 1;

    return coins;
}

// The Algorithm

// coins += owed / 25;
// remainder = owed%25;
// coins += remainder / 10;
// remainder = remainder%10;
// coins += remainder / 5;
// remainder = remainder%5;
// coins += remainder / 1;
