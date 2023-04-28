#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman_functions.h"

#define True 1
#define False 0

int main(int argc, char *argv[])
{
    int allowed_input = False, default_lives = True;
    User_Game default_profile;

    // The following statement is meant to parse and validate the command-line arguments
    // For creating the user profile (number of lives and the word to guess) -> User_Game struct
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"-help") == 0)
        {
            // This command-line argument is used to show the user how to execute
            // the program and what is the purpose of the very same.
            printf("This program is a hangman game....\n");
            exit (0);
        }
        else if (strcmp(argv[i],"-w") == 0 || strcmp(argv[i],"-word") == 0)
        {
            // This command-line argument is used to specify the word to guess
            strcpy(default_profile.word_to_guess, (argv[i + 1]));
            allowed_input = True;
        }
        else if (strcmp(argv[i],"-l") == 0 || strcmp(argv[i],"-lifes") == 0)
        {
            // If the number of lives is specified from the command-line,
            // the input value after the "-l" or "-lifes" command is set.
            default_profile.lives = atoi(argv[i + 1]);
            default_lives = False;
        }
        else
        {
            // If the number of lives is not specified from the command-line,
            // the following default is set.
            if (default_lives == True) default_profile.lives = 5;
        }
    }
    if (allowed_input == False)
    {
        printf("Wrong input or missing commands, try again using: -l #Number_of_lives -w \"Word_to_guess\" or -h to display help\n");
        exit(0);
    }
    printf("Size %d\n",strlen(default_profile.word_to_guess));
    string_to_uppercase(default_profile.word_to_guess);

    /*
    The following statements call the functions of hangman_function.c and hangman_function.h files
    to esecute the hangman game
    */

    printf("The user profile for this game is:\n");
    printf("Lives: %d \nWord to guess: \"%s\"\n",default_profile.lives,default_profile.word_to_guess);
    
    guess_input_word(default_profile.word_to_guess, &default_profile.lives);


    printf("Program ended with exit code: 0");
    return 0;
}

// gcc main.c hangman_functions.c -o game_test.exe
// ./game_test.exe