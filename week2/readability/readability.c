#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letter(string text);
int count_word(string text);
int count_sentence(string text);

int main()
{

     //prompt user for text
    string text = get_string("Enter the text:");

    //count words letters and senteces in the text 
    int letters = count_letter(text);
    int words = count_word(text);
    int sentences =  count_sentence(text);

    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;

    //use the equation to find the index 
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16) {
        printf("Grade: 16+\n");
    } else if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade: %i\n", (int)index);
    }
    //give output grade level based on the index

   // printf("Grade: %s\n", index); 
    
}

int count_letter(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count ++;
        }
    }
    return count;
}

int count_word(string text)
{
    int count = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isblank(text[i]))
            count ++;
    }
    return count;
}

int count_sentence(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count ++;
        }
    }
    if (count < 1)
        count = 1;
    return count;
}
