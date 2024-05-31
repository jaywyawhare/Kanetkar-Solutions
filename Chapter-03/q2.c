// If ages of Ram, Shyam and Ajay are input through the keyboard, write a program to determine the youngest of the three.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int ram;
    int shyam;
    int ajay;
    int expected;
};

int youngest(int ram, int shyam, int ajay)
{
    if (ram < shyam && ram < ajay)
    {
        return ram;
    }
    else if (shyam < ram && shyam < ajay)
    {
        return shyam;
    }
    else
    {
        return ajay;
    }
}

bool testFunction(int ram, int shyam, int ajay, int expected)
{
    return youngest(ram, shyam, ajay) == expected;
}

void runTests()
{
    struct test tests[] = {
        {1, 2, 3, 1},
        {3, 2, 1, 1},
        {2, 1, 3, 1},
        {3, 1, 2, 1},
        {1, 3, 2, 1},
        {2, 3, 1, 1},
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].ram, tests[i].shyam, tests[i].ajay, tests[i].expected))
        {
            printf("Test failed: Ram = %d, Shyam = %d, Ajay = %d, Expected = %d\n", tests[i].ram, tests[i].shyam, tests[i].ajay, tests[i].expected);
            printf("Got: %d\n", youngest(tests[i].ram, tests[i].shyam, tests[i].ajay));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void determineYoungest()
{
    int ram, shyam, ajay;
    printf("Enter ages of Ram, Shyam and Ajay: ");
    scanf("%d %d %d", &ram, &shyam, &ajay);
    int youngestAge = youngest(ram, shyam, ajay);
    printf("Youngest of the three is %d\n", youngestAge);
}

int main()
{
    runTests();
    determineYoungest();
    return 0;
}