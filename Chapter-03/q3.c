// Write a program to check whether a triangle is valid or not, if three angles of the triangle are entered through the keyboard. A triangle is valid if the sum of all the three angles is equal to 180 degrees.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int a;
    int b;
    int c;
    bool expected;
};

bool isTriangleValid(int a, int b, int c)
{
    return a + b + c == 180;
}

bool testFunction(int a, int b, int c, bool expected)
{
    return isTriangleValid(a, b, c) == expected;
}

void runTests()
{
    struct test tests[] = {
        {60, 60, 60, true},
        {90, 45, 45, true},
        {45, 45, 90, true},
        {45, 90, 45, true},
        {90, 90, 0, true},
        {90, 90, 90, false}};

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].a, tests[i].b, tests[i].c, tests[i].expected))
        {
            printf("Test failed: A = %d, B = %d, C = %d, Expected = %d\n", tests[i].a, tests[i].b, tests[i].c, tests[i].expected);
            printf("Got: %d\n", isTriangleValid(tests[i].a, tests[i].b, tests[i].c));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void checkTriangle()
{
    int a, b, c;
    printf("Enter three angles of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    if (isTriangleValid(a, b, c))
    {
        printf("Triangle is valid.\n");
    }
    else
    {
        printf("Triangle is not valid.\n");
    }
}

int main()
{
    runTests();
    checkTriangle();
    return 0;
}

