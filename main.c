#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lists_methods.h"

int main(int argc, char *argv[])
{
    char test_char = 'D' + 32;
    printf("The test character is %c\n",test_char);
    /*
    To delete!
    */
    char word_to_guess[] = "ROUGE";
    char input_letter = 0;

    printf("The word to guess is %s\n",word_to_guess);
    for (int i = 0; i<3; i++)
    {
        printf("Guess a letter :");
        scanf("%c", &input_letter);
        if ((input_letter > 64 && input_letter < 91) || (input_letter > 96 && input_letter < 123))
        {
            printf("You've just entered %c\n", input_letter);

            char *answer = strchr(word_to_guess, input_letter);
            printf("Yes or no: %s and address %d\n", answer, &answer);
        }
        else
        {
            printf("Wrong input %c, try again\n", input_letter);
            i--;
        }

        fflush(stdin);
    }

    return 0;
}

// gcc main.c lists_methods.c -o main_tables.exe
// ./main_tables.exe