#ifndef hangman_functions
#define hangman_functions

typedef struct User_Game User_Game;
struct User_Game
{
    int lives;
    char word_to_guess[];
};

char enter_input_char();
/*
This function reads, stores and validates the input char. If the submitted value is valid it
returns the entered input char, otherwise it will be asked again to repeat the input char value.

--------
Returns:
char output_char
    The validated submitted input char for the hangman.

*/

void evaluate_input_char(char input_char);
/*

*/




#endif