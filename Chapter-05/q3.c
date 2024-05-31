/*
Write a program for a matchstick game being played between the computer and a user. Your program should ensure that the computer always wins. Rules for the game are as follows:
    - There are 21 matchsticks.
    - The computer asks the player to pick 1, 2, 3, or 4 matchsticks.
    - After the person picks, the computer does its picking.
    - Whoever is forced to pick up the last matchstick loses the game.
*/ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test {
    int userPick;
    int expectedComputerPick;
};

int getComputerPick(int userPick) {
    return 5 - userPick;
}

bool testFunction(int userPick, int expectedComputerPick) {
    return getComputerPick(userPick) == expectedComputerPick;
}

void runTests() {
    struct test tests[] = {
        {1, 4},
        {2, 3},
        {3, 2},
        {4, 1}
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].userPick, tests[i].expectedComputerPick)) {
            printf("Test failed: User pick = %d, Expected computer pick = %d\n", tests[i].userPick, tests[i].expectedComputerPick);
            printf("Got: %d\n", getComputerPick(tests[i].userPick));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
    printf("All tests passed.\n");
}

void playMatchstickGame() {
    int matchsticks = 21;
    int userPick, computerPick;

    printf("Matchstick Game: You vs. Computer\n");
    printf("Rules: You can pick 1, 2, 3, or 4 matchsticks. Whoever is forced to pick the last matchstick loses.\n");

    while (matchsticks > 1) {
        printf("\nThere are %d matchsticks left.\n", matchsticks);
        printf("Pick 1, 2, 3, or 4 matchsticks: ");
        scanf("%d", &userPick);

        if (userPick < 1 || userPick > 4) {
            printf("Invalid pick. Please pick 1, 2, 3, or 4 matchsticks.\n");
            continue;
        }

        computerPick = getComputerPick(userPick);
        printf("Computer picks %d matchsticks.\n", computerPick);

        matchsticks -= userPick + computerPick;

        if (matchsticks == 1) {
            printf("There is 1 matchstick left.\n");
            printf("You are forced to pick the last matchstick. You lose!\n");
            return;
        }
    }
}

int main() {
    runTests();
    playMatchstickGame();
    return 0;
}
