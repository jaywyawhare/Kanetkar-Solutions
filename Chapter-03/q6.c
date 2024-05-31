// Given three points (x1, y1), (x2, y2) and (x3, y3), write a program to check if the three points fall on one straight line.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    bool expected;
};

bool arePointsCollinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (x1 == x2 && x2 == x3 && y1 == y2 && y2 == y3)
    {
        return true;
    }
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

bool testFunction(int x1, int y1, int x2, int y2, int x3, int y3, bool expected)
{
    return arePointsCollinear(x1, y1, x2, y2, x3, y3) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, 0, 1, 1, 2, 2, true},
        {0, 0, 1, 1, 2, 3, false},
        {0, 0, 1, 1, 1, 1, true}, 
        {0, 0, 1, 1, 1, 2, false},
        {0, 0, 1, 2, 2, 4, true}, 
        {0, 0, 1, 2, 2, 5, false},
        {1, 1, 2, 2, 3, 3, true}, 
        {1, 1, 2, 2, 3, 4, false}
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].x1, tests[i].y1, tests[i].x2, tests[i].y2, tests[i].x3, tests[i].y3, tests[i].expected))
        {
            printf("Test failed: x1 = %d, y1 = %d, x2 = %d, y2 = %d, x3 = %d, y3 = %d, Expected = %s\n", tests[i].x1, tests[i].y1, tests[i].x2, tests[i].y2, tests[i].x3, tests[i].y3, tests[i].expected ? "true" : "false");
            printf("Got: %s\n", arePointsCollinear(tests[i].x1, tests[i].y1, tests[i].x2, tests[i].y2, tests[i].x3, tests[i].y3) ? "true" : "false");
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

}

void checkCollinearity()
{
    int x1, y1, x2, y2, x3, y3;
    printf("Enter three points (x1, y1), (x2, y2) and (x3, y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (arePointsCollinear(x1, y1, x2, y2, x3, y3))
    {
        printf("Points are collinear.\n");
    }
    else
    {
        printf("Points are not collinear.\n");
    }
}

int main()
{
    runTests();
    checkCollinearity();
    return 0;
}

