// Two numbers are input through the keyboard into two locations C and D. Write a program to interchange the contents of C and D.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int c;
    int d;
    int expectedC;
    int expectedD;
};

void swap(int *c, int *d)
{
    int temp = *c;
    *c = *d;
    *d = temp;
}

bool testFunction(int c, int d, int expectedC, int expectedD)
{
    swap(&c, &d);
    return c == expectedC && d == expectedD;
}

void runTests()
{
    struct test tests[] = {
        {1, 2, 2, 1},
        {0, 0, 0, 0},
        {100, 200, 200, 100},
        {123, 456, 456, 123},
        {999, 999, 999, 999},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].c, tests[i].d, tests[i].expectedC, tests[i].expectedD))
        {
            printf("Test failed: C = %d, D = %d, Expected C = %d, Expected D = %d\n", tests[i].c, tests[i].d, tests[i].expectedC, tests[i].expectedD);
            printf("Got: C = %d, D = %d\n", tests[i].c, tests[i].d);

            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void swapAndPrint()
{
    int c, d;
    printf("Enter two numbers: ");
    scanf("%d %d", &c, &d);
    swap(&c, &d);
    printf("After swapping: C = %d, D = %d\n", c, d);
}

int main()
{
    runTests();
    swapAndPrint();
    return 0;
}