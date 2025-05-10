#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to get computer's choice
char getComputerChoice() {
    int num = rand() % 3;  // generates 0, 1, or 2
    if (num == 0) return 's';  // Snake
    else if (num == 1) return 'w';  // Water
    else return 'g';  // Gun
}

// Function to determine winner
int determineWinner(char player, char computer) {
    // Return 1 if player wins, -1 if computer wins, 0 if draw
    if (player == computer) return 0;

    if ((player == 's' && computer == 'w') ||
        (player == 'w' && computer == 'g') ||
        (player == 'g' && computer == 's')) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    char playerChoice, computerChoice;
    int result;

    // Seed random number generator
    srand(time(0));

    printf("Welcome to Snake, Water & Gun Game!\n");
    printf("Enter 's' for Snake, 'w' for Water, and 'g' for Gun:\n");
    printf("Your choice: ");
    scanf(" %c", &playerChoice);

    // Validate input
    if (playerChoice != 's' && playerChoice != 'w' && playerChoice != 'g') {
        printf("Invalid input! Please enter 's', 'w' or 'g'.\n");
        return 1;
    }

    computerChoice = getComputerChoice();
    printf("Computer chose: %c\n", computerChoice);

    result = determineWinner(playerChoice, computerChoice);

    if (result == 0)
        printf("It's a draw!\n");
    else if (result == 1)
        printf("You win!\n");
    else
        printf("Computer wins!\n");

    return 0;
}
