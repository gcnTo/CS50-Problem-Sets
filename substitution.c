#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//./substitution zyxwvutsrqpomnlkjihgfedcba

int main(int argc, string argv[])
{
    char *alphabet = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
    char *alphabetlower = "abcdefghijklnmopqrstuvwxyz";
    string text = get_string("Enter text: \n");
    char *sub = argv[1];
    char *loc;
    int index;

    for ( int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            printf(" ");
        }

        else if ( strchr(alphabet, text[i]) )
        {
            loc = strchr( alphabet, text[i] );
            index = (int) (loc - alphabet);
            text[i] = sub[index];
            printf("%c", text[i]);
        }
        
        else if ( strchr(alphabetlower, text[i]) )
        {
            loc = strchr( alphabetlower, text[i] );
            index = (int) (loc - alphabetlower);
            text[i] = tolower(sub[index]);
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
