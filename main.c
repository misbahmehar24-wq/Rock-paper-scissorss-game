/*
 * Project: Rock Paper Scissors Game
 * Language: C
 * Description: A console game in which the user plays against the computer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *choice_name(int choice)
{
    switch (choice)
    {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

int main(void)
{
    int user_choice, computer_choice;
    char play_again;

    srand((unsigned int)time(NULL));

    printf("=================================\n");
    printf("     ROCK PAPER SCISSORS GAME    \n");
    printf("=================================\n");

    do
    {
        printf("\nChoose your move:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter choice (1-3): ");

        if (scanf("%d", &user_choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        if (user_choice < 1 || user_choice > 3)
        {
            printf("Invalid choice. Please run the game again and enter 1, 2, or 3.\n");
            return 1;
        }

        computer_choice = (rand() % 3) + 1;

        printf("\nYou chose: %s\n", choice_name(user_choice));
        printf("Computer chose: %s\n", choice_name(computer_choice));

        if (user_choice == computer_choice)
        {
            printf("Result: It's a draw!\n");
        }
        else if ((user_choice == 1 && computer_choice == 3) ||
                 (user_choice == 2 && computer_choice == 1) ||
                 (user_choice == 3 && computer_choice == 2))
        {
            printf("Result: You win!\n");
        }
        else
        {
            printf("Result: Computer wins!\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("\nThank you for playing!\n");
    return 0;
}
