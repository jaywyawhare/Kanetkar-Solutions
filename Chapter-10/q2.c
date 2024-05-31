// Write a recursive function to obtain the sum of first 25 natural numbers.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int n;
    int expected;
};

int sumOfFirstNNumbers(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumOfFirstNNumbers(n - 1);
}

bool testFunction(int n, int expected)
{
    return sumOfFirstNNumbers(n) == expected;
}

void runTests()
{
    struct test tests[] = {
        {1, 1},
        {2, 3},
        {3, 6},
        {4, 10},
        {5, 15},
        {6, 21},
        {7, 28},
        {8, 36},
        {9, 45},
        {10, 55},
        {11, 66},
        {12, 78},
        {13, 91},
        {14, 105},
        {15, 120},
        {16, 136},
        {17, 153},
        {18, 171},
        {19, 190},
        {20, 210},
        {21, 231},
        {22, 253},
        {23, 276},
        {24, 300},
        {25, 325},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].n, tests[i].expected))
        {
            printf("Test failed: N = %d, Expected = %d\n", tests[i].n, tests[i].expected);
            printf("Got: %d\n", sumOfFirstNNumbers(tests[i].n));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

}

int main()
{
    runTests();
    printf("Code is working fine.\n");
    return 0;
}