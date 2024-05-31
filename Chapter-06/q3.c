/*
When interest compounds q times per year at an annual rate of r % for n years, the principal p compounds to an amount a as per the following formula:
  
    A = p * (1 + r/q)^(n*q) 

Write a program to read 10 sets of p, r, n, and q, and calculate the corresponding a. 
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define TOLERANCE 0.00001

struct test
{
    double p;
    double r;
    int n;
    int q;
    double expected;
};

double compoundInterest(double p, double r, int n, int q)
{
    return p * pow(1 + r / q, n * q);
}

bool testFunction(double p, double r, int n, int q, double expected)
{
    return fabs(compoundInterest(p, r, n, q) - expected) < TOLERANCE;
}

void runTests()
{
    struct test tests[] = {
        {1000, 0.1, 1, 1, 1100},
        {1000, 0.1, 2, 1, 1210},
        {1000, 0.1, 1, 2, 1102.5},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].p, tests[i].r, tests[i].n, tests[i].q, tests[i].expected))
        {
            printf("Test failed: P = %f, R = %f, N = %d, Q = %d, Expected = %f\n", tests[i].p, tests[i].r, tests[i].n, tests[i].q, tests[i].expected);
            printf("Got: %f\n", compoundInterest(tests[i].p, tests[i].r, tests[i].n, tests[i].q));
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
    printf("P\tR\tN\tQ\tA\n");
    for (int i = 0; i < 10; i++)
    {
        double p, r;
        int n, q;
        printf("Enter P, R, N, Q: ");
        scanf("%lf %lf %d %d", &p, &r, &n, &q);
        printf("%f\t%f\t%d\t%d\t%f\n", p, r, n, q, compoundInterest(p, r, n, q));
    }
}

int main()
{
    runTests();
    printTable();
    return 0;
}
