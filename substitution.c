#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Example: ./substitution zyxwvutsrqpomnlkjihgfedcba

int main(int argc, string argv[])
{
    char *alphabet = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
    char *alphabetlower = "abcdefghijklnmopqrstuvwxyz";
    string text = get_string("Enter text: \n");
    char *sub = argv[1];
    char *loc;
    int index;

    for (int i = 0; i < strlen(text); i++)
    {
        // If input includes a blank space, it remains as a blank space
        if (text[i] == ' ')
        {
            printf(" ");
        }

        // If input is in uppercase alphabet. Change it with new alphabet. Keep as uppercase.
        else if (strchr(alphabet, text[i]))
        {
            //Finds out which index position of the uppercase alphabet resides the 'i'th char.
            loc = strchr(alphabet, text[i]);
            index = (int)(loc - alphabet);
            
            text[i] = toupper(sub[index]);
            printf("%c", text[i]);
        }

        // If the input is in lowercase alphabet. Change it with new alphabet. Keep as lowercase.
        else if (strchr(alphabetlower, text[i]))
        {
            //Finds out which index position of the lowercase alphabet resides the 'i'th char.
            loc = strchr(alphabetlower, text[i]);
            index = (int)(loc - alphabetlower);
            text[i] = tolower(sub[index]);
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
