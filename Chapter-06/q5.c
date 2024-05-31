// Write a program to generate all Pythagorean triplets with side length less than or equal to 30.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int side1;
    int side2;
    int side3;
};

bool isPythagoreanTriplet(int side1, int side2, int side3)
{
    return pow(side1, 2) + pow(side2, 2) == pow(side3, 2);
}

bool testFunction(int side1, int side2, int side3)
{
    return isPythagoreanTriplet(side1, side2, side3);
}

void runTests()
{
    struct test tests[] = {
        {3, 4, 5},
        {5, 12, 13},
        {7, 24, 25},
        {8, 15, 17},
        {9, 40, 41},
        {11, 60, 61},
        {12, 35, 37},
        {13, 84, 85},
        {16, 63, 65},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].side1, tests[i].side2, tests[i].side3))
        {
            printf("Test failed: Side1 = %d, Side2 = %d, Side3 = %d\n", tests[i].side1, tests[i].side2, tests[i].side3);
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

}

void printPythagoreanTriplets()
{
    printf("Pythagorean Triplets with side length less than or equal to 30:\n");
    for (int side1 = 1; side1 <= 30; side1++)
    {
        for (int side2 = side1; side2 <= 30; side2++)
        {
            for (int side3 = side2; side3 <= 30; side3++)
            {
                if (isPythagoreanTriplet(side1, side2, side3))
                {
                    printf("%d, %d, %d\n", side1, side2, side3);
                }
            }
        }
    }
}

int main()
{
    runTests();
    printPythagoreanTriplets();
    return 0;
}