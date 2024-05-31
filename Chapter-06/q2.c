/*
According to a study, the approximate level of intelligence of a person can be calculated using the following formula:

    i = 2 + (y + 0.5x)

Write a program that will produce a table of values of i, y, and x where y varies from 1 to 6, and, for each value of y, x varies from 5.5 to 12.5 in steps of 0.5.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int y;
    double x;
    double expected;
};

double intelligence(int y, double x)
{
    return 2 + (y + 0.5 * x);
}

bool testFunction(int y, double x, double expected)
{
    return intelligence(y, x) == expected;
}

void runTests()
{
    struct test tests[] = {
        {1, 5.5, 5.75},
        {1, 6, 6},
        {1, 6.5, 6.25},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].y, tests[i].x, tests[i].expected))
        {
            printf("Test failed: Y = %d, X = %f, Expected = %f\n", tests[i].y, tests[i].x, tests[i].expected);
            printf("Got: %f\n", intelligence(tests[i].y, tests[i].x));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

}

void printTable()
{
    printf("Y\tX\tI\n");
    for (int y = 1; y <= 6; y++)
    {
        for (double x = 5.5; x <= 12.5; x += 0.5)
        {
            printf("%d\t%.1f\t%.2f\n", y, x, intelligence(y, x));
        }
    }
}

int main()
{
    runTests();
    printTable();
    return 0;
}
