// Given three variables x, y, z, write a function to circularly shift their values to right. In other words, if x = 5, y = 8, z = 10, after circular shift y = 5, z = 8, x =10. Call the function with variables a, b, c to circularly shift values.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int x;
    int y;
    int z;
    int expectedX;
    int expectedY;
    int expectedZ;
};

void circularShift(int *x, int *y, int *z)
{
    int temp = *z;
    *z = *y;
    *y = *x;
    *x = temp;
}

bool testFunction(int x, int y, int z, int expectedX, int expectedY, int expectedZ)
{
    circularShift(&x, &y, &z);
    return x == expectedX && y == expectedY && z == expectedZ;
}

void runTests()
{
    struct test tests[] = {
        {5, 8, 10, 10, 5, 8},
        {1, 2, 3, 3, 1, 2},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0, 0},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].x, tests[i].y, tests[i].z, tests[i].expectedX, tests[i].expectedY, tests[i].expectedZ))
        {
            printf("Test failed: X = %d, Y = %d, Z = %d, Expected = %d %d %d\n", tests[i].x, tests[i].y, tests[i].z, tests[i].expectedX, tests[i].expectedY, tests[i].expectedZ);
            printf("Got: %d %d %d\n", tests[i].x, tests[i].y, tests[i].z);
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void circularShiftValues(){
    int a, b, c;
    printf("Enter three values: ");
    scanf("%d %d %d", &a, &b, &c);
    circularShift(&a, &b, &c);
    printf("After circular shift: %d %d %d\n", a, b, c);
}

int main()
{
    runTests();
    circularShiftValues();
    return 0;
}