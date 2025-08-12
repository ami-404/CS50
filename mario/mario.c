#include <stdio.h>
#include <cs50.h>

int height;
int k = 1;

int main(void)
{
    do
    {
        height = get_int("What is the Height(1-8)? \n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i ++)
    {
        for (int i = 0; i < (height - k); i ++)
        {
            printf(" ");
        }
        for (int i = 0; i < k; i ++)
        {
            printf("#");
        }
        printf ("  ");
        for (int i = 0; i < k; i++)
        {
            printf ("#");
        }
        printf("\n");
        k++;

    }
}
