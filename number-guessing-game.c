#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int choice, max, maxAttempts;
    int secret, guess, attempts;
    char playAgain;

    srand((unsigned int)time(NULL));

    do {
        printf("\n==============================\n");
        printf("   NUMBER GUESSING GAME\n");
        printf("==============================\n");
        printf("Select a level:\n");
        printf("  1. Easy   (1-10,   5 attempts)\n");
        printf("  2. Medium (1-50,   7 attempts)\n");
        printf("  3. Hard   (1-100, 10 attempts)\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');   /* clear invalid input */
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: max = 10;  maxAttempts = 5;  break;
            case 2: max = 50;  maxAttempts = 7;  break;
            case 3: max = 100; maxAttempts = 10; break;
            default:
                printf("Invalid level! Choose 1, 2 or 3.\n");
                continue;
        }

        secret = rand() % max + 1;
        attempts = 0;

        printf("\nI'm thinking of a number between 1 and %d.\n", max);
        printf("You have %d attempts. Good luck!\n\n", maxAttempts);

        while (attempts < maxAttempts) {
            printf("Attempt %d/%d - Enter your guess: ", attempts + 1, maxAttempts);

            if (scanf("%d", &guess) != 1) {
                while (getchar() != '\n');
                printf("Invalid input! Try again.\n");
                continue;
            }

            if (guess < 1 || guess > max) {
                printf("Please guess between 1 and %d.\n", max);
                continue;
            }

            attempts++;

            if (guess == secret) {
                printf("\n*** Congratulations! You guessed it in %d attempt(s)! ***\n", attempts);
                break;
            } else if (guess < secret) {
                printf("Too low!\n");
            } else {
                printf("Too high!\n");
            }

            if (attempts == maxAttempts) {
                printf("\nGame over! The number was %d.\n", secret);
            }
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing. Goodbye!\n");
    return 0;
}