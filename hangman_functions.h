#ifndef hangman_functions
#define hangman_functions

#define True 1
#define False 0

typedef struct User_Game User_Game;
struct User_Game
{
    int lives;
    char word_to_guess[20];
};

void clear_input_buffer();
/*
This functions clears the input buffer.
*/


char char_to_uppercase(char input_char);
/*
To define! 😍😍😍😍😍😍😍😍😍
*/

void string_to_uppercase(char *input_string);
/*
To define! 😍😍😍😍😍😍😍😍😍
*/

char enter_input_char();
/*
This function reads, stores and validates the input char. If the submitted value is valid it
returns the entered input char, otherwise it will be asked again to repeat the input char value.

--------
Returns:
char output_char
    The validated submitted input char for the hangman.

*/

void guess_input_word(char *input_string, int *remaining_lives);
/*

*/




#endif