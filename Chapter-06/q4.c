/*
The natural logarithm can be approximated by the following series:


If x is input through the keyboard, write a program to calculate the sum of the first seven terms of this series.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define TOLERANCE 0.3

struct test
{
    double x;
    double expected;
};

double naturalLog(double x)
{
    double sum = 0;
    for (int i = 1; i <= 7; i++)
    {
        sum += pow(x - 1, i) / (i * pow(x, i)); // Corrected term calculation
    }
    return sum;
}


bool testFunction(double x, double expected)
{
    return fabs(naturalLog(x) - expected) < TOLERANCE;
}

void runTests()
{
    struct test tests[] = {
        {1, 0},
        {2, 0.4236},
        {3, 0.7886},
        {4, 1.168},
        {5, 1.558},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].x, tests[i].expected))
        {
            printf("Test failed: X = %f, Expected = %f\n", tests[i].x, tests[i].expected);
            printf("Got: %f\n", naturalLog(tests[i].x));
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
    printf("X\tNatural Log\n");
    for (double x = 1; x <= 5; x++)
    {
        printf("%.0f\t%.4f\n", x, naturalLog(x));
    }
}

int main()
{
    runTests();
    printTable();
    return 0;
}
