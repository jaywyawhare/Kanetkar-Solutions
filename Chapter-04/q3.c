/*
A cetain grade of steel is graded according to the following conditions:

    1. Hardness must be greater than 50
    2. Carbon content must be less than 0.7
    3. Tensile strength must be greater than 5600

The grades are as follows:

    - Grade is 10 if all three conditions are met
    - Grade is 9 if conditions 1 and 2 are met
    - Grade is 8 if conditions 2 and 3 are met
    - Grade is 7 if conditions 1 and 3 are met
    - Grade is 6 if only one condition is met
    - Grade is 5 if none of the conditions are met

Write a program, which will require the user to give values of hardness, carbon content and tensile strength of the steel under consideration and output the grade of the steel.
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int hardness;
    double carbonContent;
    int tensileStrength;
    int expected;
};

int gradeOfSteel(int hardness, double carbonContent, int tensileStrength)
{
    if (hardness > 50 && carbonContent < 0.7 && tensileStrength > 5600)
    {
        return 10;
    }
    else if (hardness > 50 && carbonContent < 0.7)
    {
        return 9;
    }
    else if (carbonContent < 0.7 && tensileStrength > 5600)
    {
        return 8;
    }
    else if (hardness > 50 && tensileStrength > 5600)
    {
        return 7;
    }
    else if (hardness > 50 || carbonContent < 0.7 || tensileStrength > 5600)
    {
        return 6;
    }
    else
    {
        return 5;
    }
}

bool testFunction(int hardness, double carbonContent, int tensileStrength, int expected)
{
    return gradeOfSteel(hardness, carbonContent, tensileStrength) == expected;
}

void runTests()
{
    struct test tests[] = {
        {51, 0.6, 5700, 10},
        {51, 0.6, 5500, 9},
        {49, 0.6, 5700, 8},
        {51, 0.8, 5700, 7},
        {51, 0.8, 5500, 6},
        {49, 0.8, 5500, 5},
        {50, 0.7, 5600, 5},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].hardness, tests[i].carbonContent, tests[i].tensileStrength, tests[i].expected))
        {
            printf("Test failed: Hardness = %d, Carbon Content = %f, Tensile Strength = %d, Expected = %d\n", tests[i].hardness, tests[i].carbonContent, tests[i].tensileStrength, tests[i].expected);
            printf("Got: %d\n", gradeOfSteel(tests[i].hardness, tests[i].carbonContent, tests[i].tensileStrength));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}
void printGrade()
{
    int hardness, tensileStrength;
    double carbonContent;
    printf("Enter hardness, carbon content, and tensile strength: ");
    scanf("%d %lf %d", &hardness, &carbonContent, &tensileStrength);
    printf("Grade of steel: %d\n", gradeOfSteel(hardness, carbonContent, tensileStrength));
}

int main()
{
    runTests();
    printGrade();
    return 0;
}


