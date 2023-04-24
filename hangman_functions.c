#include <stdlib.h>
#include <stdio.h>
#include "hangman_functions.h"

char enter_input_char()
{
    /*
    This function reads, stores and validates the input char. If the submitted value is valid it
    returns the entered input char, otherwise it will be asked again to repeat the input char value.

    --------
    Returns:
    char output_char
        The validated submitted input char for the hangman.
    */

    char input_char = 0, output_char = '\0';

    while (output_char == '\0')
    {
        printf("Enter your guess!: ");
        scanf("%c", &input_char);
        if ((input_char > 64 && input_char < 91) || (input_char > 96 && input_char < 123))
        // The latter condition checks if the input char is a letter according to the ASCII table.
        {
            if (input_char > 96)
            // This condition checks if the entered letter is a lowercase value accroding to the ASCII table.
            {
                input_char -= 32;
                // Substracting 32 allows to convert any ASCII lowercase letter into its respective uppercase value.
            }
            output_char = input_char;
            printf("You've just entered %c\n", output_char);
        }
        else
        {
            printf("Wrong input '%c', try again\n", input_char);
        }
        fflush(stdin);
    }
    return output_char;
}