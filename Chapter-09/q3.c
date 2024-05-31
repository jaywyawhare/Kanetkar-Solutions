// Define a function to compute the distance between two points and use it to develop another function that will compute the area of the triangle whose vertices are A(x1, y1), B(x2, y2), and C(x3, y3). Use these functions to develop a function which returns a value 1 if the point (x, y) lines inside the triangle ABC, otherwise returns a value 0. Would you get any advantage if you develop these functions to work on call be reference principle?

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

struct test
{
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int x;
    int y;
    bool expected;
};

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool isInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
    double totalArea = area(x1, y1, x2, y2, x3, y3);
    double subArea1 = area(x1, y1, x2, y2, x, y);
    double subArea2 = area(x2, y2, x3, y3, x, y);
    double subArea3 = area(x3, y3, x1, y1, x, y);
    return fabs(totalArea - (subArea1 + subArea2 + subArea3)) < 0.0001;
}


bool testFunction(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y, bool expected)
{
    return isInsideTriangle(x1, y1, x2, y2, x3, y3, x, y) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, 0, 1, 1, 2, 2, 1, 1, true},
        {0, 0, 1, 1, 2, 2, 0, 1, false},
        {0, 0, 1, 1, 2, 2, 1, 0, false},
        {0, 0, 1, 1, 2, 2, 2, 1, false},
        {0, 0, 1, 1, 2, 2, 1, 2, false},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].x1, tests[i].y1, tests[i].x2, tests[i].y2, tests[i].x3, tests[i].y3, tests[i].x, tests[i].y, tests[i].expected))
        {
            printf("Test failed: x1 = %d, y1 = %d, x2 = %d, y2 = %d, x3 = %d, y3 = %d, x = %d, y = %d, Expected = %s\n", tests[i].x1, tests[i].y1, tests[i].x2, tests[i].y2, tests[i].x3, tests[i].y3, tests[i].x, tests[i].y, tests[i].expected ? "true" : "false");
            printf("Got: %s\n", isInsideTriangle(tests[i].x1, tests[i].y1, tests[i].x2, tests[i].y2, tests[i].x3, tests[i].y3, tests[i].x, tests[i].y) ?
                     "true" : "false");
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
    int x1, y1, x2, y2, x3, y3, x, y;
    printf("Enter the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point: ");
    scanf("%d %d", &x3, &y3);
    printf("Enter the coordinates of the point to check: ");
    scanf("%d %d", &x, &y);
    if (isInsideTriangle(x1, y1, x2, y2, x3, y3, x, y))
    {
        printf("The point (%d, %d) lies inside the triangle with vertices (%d, %d), (%d, %d), and (%d, %d).\n", x, y, x1, y1, x2, y2, x3, y3);
    }
    else
    {
        printf("The point (%d, %d) does not lie inside the triangle with vertices (%d, %d), (%d, %d), and (%d, %d).\n", x, y, x1, y1, x2, y2, x3, y3);
    }
}

int main()
{
    runTests();
    checkCollinearity();
    return 0;
}