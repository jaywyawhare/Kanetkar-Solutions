// Given the coordinates (x, y) of center of a circle and its radius, writ a program that will determine whether a point lies inside the circle on the circle or outside the circle. (Hint: Use sqrt() and pow()  functions)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int x;
    int y;
    int radius;
    int pointX;
    int pointY;
    char expected;
};

char pointPosition(int x, int y, int radius, int pointX, int pointY)
{
    int dx = pointX - x;
    int dy = pointY - y;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSquared = radius * radius;

    if (distanceSquared < radiusSquared)
    {
        return 'i';
    }
    else if (distanceSquared == radiusSquared)
    {
        return 'o'; 
    }
    else
    {
        return 'u'; 
    }
}

bool testFunction(int x, int y, int radius, int pointX, int pointY, char expected)
{
    return pointPosition(x, y, radius, pointX, pointY) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, 0, 5, 0, 0, 'i'}, 
        {0, 0, 5, 0, 5, 'o'}, 
        {0, 0, 5, 0, 6, 'u'}, 
        {0, 0, 5, 3, 4, 'o'}, 
        {0, 0, 5, 5, 0, 'o'}, 
        {0, 0, 5, -3, 4, 'o'}, 
        {0, 0, 5, -5, 0, 'o'}, 
        {0, 0, 5, 0, -5, 'o'}, 
        {0, 0, 5, 5, 5, 'u'}, 
        {0, 0, 5, 0, -6, 'u'}, 
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].x, tests[i].y, tests[i].radius, tests[i].pointX, tests[i].pointY, tests[i].expected))
        {
            printf("Test failed: X = %d, Y = %d, Radius = %d, PointX = %d, PointY = %d, Expected = %c\n", tests[i].x, tests[i].y, tests[i].radius, tests[i].pointX, tests[i].pointY, tests[i].expected);
            printf("Got: %c\n", pointPosition(tests[i].x, tests[i].y, tests[i].radius, tests[i].pointX, tests[i].pointY));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

    printf("All tests passed.\n");
}

void checkPointPosition()
{
    int x, y, radius, pointX, pointY;
    printf("Enter the coordinates of the center of the circle and its radius: ");
    scanf("%d %d %d", &x, &y, &radius);
    printf("Enter the coordinates of the point: ");
    scanf("%d %d", &pointX, &pointY);
    char position = pointPosition(x, y, radius, pointX, pointY);
    if (position == 'i')
    {
        printf("The point lies inside the circle.\n");
    }
    else if (position == 'o')
    {
        printf("The point lies on the circle.\n");
    }
    else
    {
        printf("The point lies outside the circle.\n");
    }
}

int main()
{
    runTests();
    checkPointPosition();
    return 0;
}
