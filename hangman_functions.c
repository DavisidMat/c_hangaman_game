#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hangman_functions.h"

void clear_input_buffer()
{
    /*
    This functions clears the input buffer.
    */
    int buffer_char;
    while ((buffer_char = getchar()) != '\n' && buffer_char != EOF);
}

char char_to_uppercase(char input_char)
{
    if ((input_char > 64 && input_char < 91) || (input_char > 96 && input_char < 123))
        // The latter condition checks if the input char is a letter according to the ASCII table.
        {
            if (input_char > 96)
            // This condition checks if the entered letter is a lowercase value accroding to the ASCII table.
            {
                input_char -= 32;
                // Substracting 32 allows to convert any ASCII lowercase letter into its respective uppercase value.
            }
        }
    return input_char;
}

void string_to_uppercase(char *input_string)
{
    for (int i = 0; i < strlen(input_string); i++)
    {
        // This statement replaces each character of the string with its
        // respective uppercase value.
        input_string[i] = char_to_uppercase(input_string[i]);
    }
}

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
        // The following statement is meant to clear the input buffer
        clear_input_buffer();
    }
    return output_char;
}

void guess_input_word(char *input_string, int *remaining_lives)
{
    int word_guessed = False, remaining_chars, previous_guess_state = strlen(input_string);

    char *guess_status = malloc((strlen(input_string) + 1) * sizeof(char));
    if (guess_status == NULL) exit(0);

    // The following statement is meant to save a string that will display the progress of the guess
    for (int i = 0; i < strlen(input_string); i++) guess_status[i] = '-' ;

    while (word_guessed == False)
    {
        if (*remaining_lives == 0)
        {
            printf("You don't have more remaining lives, you losed! :(");
            exit(0);
        }

        remaining_chars = strlen(guess_status);
        char input_char = enter_input_char();
        for (int i = 0; i < strlen(input_string); i++)
        {
            if (input_char == input_string[i]) guess_status[i] = input_char;
            
            if (guess_status[i] != '-') remaining_chars--;
        }
        if (remaining_chars == previous_guess_state)
        {
            *remaining_lives--;
            printf("You missed!, you have %d lives remaining\n", *remaining_lives);
        }
        previous_guess_state = remaining_chars;

        printf("The status of the word to guess is: %s\n",guess_status);

        if (remaining_chars == 0) word_guessed = True;
    }
    printf("Well done, you guessed it, the word is %s\n",guess_status);
    free(guess_status);
}