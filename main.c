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
    printf("%c\n", char_to_uppercase('m'));

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);

        if (strcmp(argv[i],"-w") == 0 || strcmp(argv[i],"-word") == 0)
        {
            // If the number of lives is specified from the command-line,
            // the input value after the "-l" or "-lifes" command is set.
            strcpy(default_profile.word_to_guess, (argv[i + 1]));
            printf("Yes yass\n");
            allowed_input = True;
        }
        else if (strcmp(argv[i],"-l") == 0 || strcmp(argv[i],"-lifes") == 0)
        {
            // If the number of lives is specified from the command-line,
            // the input value after the "-l" or "-lifes" command is set.
            default_profile.lives = atoi(argv[i + 1]);
            default_lives = False;
            printf("Yes\n");
        }
        else
        {
            // If the number of lives is not specified from the command-line,
            // the following default is set.
            if (default_lives == True)
            {
                default_profile.lives = 5;
            }
        }
    }
    if (allowed_input == False)
    {
        printf("Wrong input or missing commands, try again using: -l #Number_of_lives -w \"Word_to_guess\"\n");
        exit(0);
    }


    printf("%s Ese ess %d\n",default_profile.word_to_guess,default_profile.lives);
    
    return 0;
}

// gcc main.c hangman_functions.c -o game_test.exe
// ./game_test.exe