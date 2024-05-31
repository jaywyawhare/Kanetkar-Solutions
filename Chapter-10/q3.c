/*
There are three pegs labeled A, B and C. Four disks are placed on peg A. The bottom-most disk is largest, and disks go on decreasing in size with the topmost disk being smallest. The objective of the game is to move the disks from peg A to peg C, using peg B as an auxiliary peg. The rules of the game are as follows:
    (1) Only one disk may be moved at a time, and it must be the top disk on one of the pegs.
    (2) A larger disk should never be placed on the top of a smaller disk.
Write a program to print out the sequence in which the disks should be moved such that all disks on peg A are finally transferred to peg C.
*/

#include <stdio.h>
#include <stdbool.h>

struct test
{
    int disks;
    int expected;
};

int towerOfHanoi(int disks, char source, char auxiliary, char destination)
{
    if (disks == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return 1;
    }
    int moves = 0;
    moves += towerOfHanoi(disks - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", disks, source, destination);
    moves += 1;
    moves += towerOfHanoi(disks - 1, auxiliary, source, destination);
    return moves;
}

bool testFunction(int disks, int expected)
{
    int actual = towerOfHanoi(disks, 'A', 'B', 'C');
    return actual == expected;
}

void runTests()
{
    struct test tests[] = {
        {1, 1},
        {2, 3},
        {3, 7},
        {4, 15},
        {5, 31},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].disks, tests[i].expected))
        {
            printf("Test failed: Disks = %d, Expected = %d\n", tests[i].disks, tests[i].expected);
            allTestsPassed = false;
        }
    }

    if (allTestsPassed)
    {
        printf("All tests passed.\n");
    }
}

int main()
{
    runTests();
    return 0;
}
