// Write a program to print out all Armstrong numbers between 1 and 500. If sum of cubes of each digit of the number is equal to the number itself, then the number is called an Armstrong number. For example, 153 = ( 1 * 1 * 1 ) + ( 5 * 5 * 5 ) + ( 3 * 3 * 3 ).

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int n;
    bool expected;
};

bool isArmstrong(int n, int cube[])
{
    int originalNum = n;
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += cube[digit];
        n /= 10;
    }
    return sum == originalNum;
}

bool testFunction(int n, bool expected)
{
    int cube[10];
    for (int i = 0; i < 10; i++) {
        cube[i] = i * i * i;
    }
    return isArmstrong(n, cube) == expected;
}

void runTests()
{
    struct test tests[] = {
        {1, true},
        {153, true},
        {370, true},
        {371, true},
        {407, true},
        {0, true},
        {2, false},
        {123, false},
        {100, false},
        {500, false},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].n, tests[i].expected))
        {
            printf("Test failed: N = %d, Expected = %s\n", tests[i].n, tests[i].expected ? "true" : "false");
            printf("Got: %s\n", isArmstrong(tests[i].n, (int[]){0, 1, 8, 27, 64, 125, 216, 343, 512, 729}) ? "true" : "false");
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void printArmstrongNumbers()
{
    int cube[10];
    for (int i = 0; i < 10; i++) {
        cube[i] = i * i * i;
    }
    for (int i = 1; i <= 500; i++)
    {
        if (isArmstrong(i, cube))
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    runTests();
    printArmstrongNumbers();
    return 0;
}

