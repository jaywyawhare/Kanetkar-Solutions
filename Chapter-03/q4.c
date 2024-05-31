// Write a program to find the absolute value of a number entered through the keyboard.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int n;
    int expected;
};

int absolute(int n)
{
    return n < 0 ? -n : n;
}

bool testFunction(int n, int expected)
{
    return absolute(n) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, 0},
        {1, 1},
        {-1, 1},
        {100, 100},
        {-100, 100},
        {12345, 12345},
        {-12345, 12345},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].n, tests[i].expected))
        {
            printf("Test failed: N = %d, Expected = %d\n", tests[i].n, tests[i].expected);
            printf("Got: %d\n", absolute(tests[i].n));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void findAbsolute()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Absolute value of %d is %d\n", n, absolute(n));
}

int main()
{
    runTests();
    findAbsolute();
    return 0;
}
