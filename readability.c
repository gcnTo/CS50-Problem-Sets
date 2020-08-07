#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Write the text you want to learn the level of: \n\n");
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        //Increments the variable letters if an index position inside of the string is in the alphabet.
        if (isalpha(text[i]))
        {
            letters++;

            //Increments the variable words if there's a space after a char or if there's the last character of the string after a char.
            if ((isspace(text[i + 1]) || text[i + 1] == text[strlen(text) - 1]) || text[i + 1] == '.' || text[i + 1] == '!'
                || text[i + 1] == '?')
            {
                words++;
            }
        }

        //Increments the variable sentences if an index position of the string is a "." or "!" or "?"
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

        if (sentences > words)
        {
            sentences = words;
        }
    }

    printf("%i letter(s).\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);

    float l = (float) letters / (float) words * 100;
    float s = (float) sentences / (float) words * 100;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
