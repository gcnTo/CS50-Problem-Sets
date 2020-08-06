#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    long checkodd = 0;
    long checkeven = 0;
    long card = get_long("\nEnter your card number: \n");
    char card_string[30];
    sprintf(card_string, "%ld", card);

    if (strlen(card_string) < 12)
    {
        printf("NOT VALID\n");
        return 1;
    }

    //Adds up all the other numbers starting from index position -2. Which is the one before the last index
    for (long i = strlen(card_string) - 1; i > 0; i -= 2)
    {
        checkodd += (long) card_string[i] * 2;
        //Adds up all the other numbers starting from the last index. Index position -1
        for (long j = strlen(card_string); j > 0; j -= 2)
        {
            checkeven += (long) card_string[i];
        }
    }
    //Checks whether or not the last digit of the sum of checkodd + checkeven is 0
    if ((checkodd + checkeven) % 10 == 0)
    {
        if (((long) strlen(card_string) == 15 && (int) card_string[0] - 48 == 3) && ((int) card_string[1] - 48 == 4 
                || (int) card_string[1] - 48 == 7))
        {
            printf("This is an AMEX card. \n");
        }
        else if (((long) strlen(card_string) == 16 && (int) card_string[0] - 48 == 5) && ((int) card_string[1] - 48 == 1 
                 || (int) card_string[1] - 48 == 2 || (int) card_string[1] - 48 == 3 || (int) card_string[1] - 48 == 4 
                 || (int) card_string[1] - 48 == 5))
        {
            printf("This is a MasterCard.\n");
        }
        else if (((long) strlen(card_string) == 13 || (long) strlen(card_string) == 16) && ((int) card_string[0] - 48 == 4))
        {
            printf("This is a VISA card.\n");
        }
        else
        {
            printf("This is nor AMEX, MasterCard, VISA.\n");
        }
    }
    else
    {
        printf("NOT VALID\n");
    }
}
