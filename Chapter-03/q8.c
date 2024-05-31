// Given a point (x, y), write a program to find out if it lies on X-axis, Y-axis or origin.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int x;
    int y;
    char expected;
};

char pointPosition(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 'o';
    }
    else if (x == 0)
    {
        return 'y';
    }
    else if (y == 0)
    {
        return 'x';
    }
    else
    {
        return 'n';
    }
}

bool testFunction(int x, int y, char expected)
{
    return pointPosition(x, y) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, 0, 'o'},
        {0, 1, 'y'},
        {1, 0, 'x'},
        {1, 1, 'n'},
        {1, -1, 'n'},
        {-1, 1, 'n'},
        {-1, -1, 'n'},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].x, tests[i].y, tests[i].expected))
        {
            printf("Test failed: X = %d, Y = %d, Expected = %c\n", tests[i].x, tests[i].y, tests[i].expected);
            printf("Got: %c\n", pointPosition(tests[i].x, tests[i].y));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void checkPointPosition()
{
    int x, y;
    printf("Enter the coordinates of the point: ");
    scanf("%d %d", &x, &y);
    char position = pointPosition(x, y);
    if (position == 'o')
    {
        printf("The point lies on origin.\n");
    }
    else if (position == 'x')
    {
        printf("The point lies on X-axis.\n");
    }
    else if (position == 'y')
    {
        printf("The point lies on Y-axis.\n");
    }
    else
    {
        printf("The point does not lie on X-axis, Y-axis or origin.\n");
    }
}

int main()
{
    runTests();
    checkPointPosition();
    return 0;
}