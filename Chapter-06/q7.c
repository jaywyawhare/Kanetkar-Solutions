// Ramanujan Number (1729) is the smallest number that can be expressed as the sum of two cubes in two different ways - 1729 can be expressed as 1^3 + 12^3 or 9^3 + 10^3. Write a program to find all such numbers up to a reasonable limit n.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int n;
    bool expected;
};

bool isRamanujan(int n, int max, int cube[])
{
    int count = 0;
    for (int i = 1; i < max; i++)
    {
        for (int j = i; j < max; j++)
        {
            if (cube[i] + cube[j] == n)
            {
                count++;
                if (count >= 2) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool testFunction(int n, int max, int cube[], bool expected)
{
    return isRamanujan(n, max, cube) == expected;
}

void runTests()
{
    struct test tests[] = {
        {69, false},
        {420, false},
        {1234, false},
        {1729, true},
        {4104, true},
        {13832, true},
        {65728, true},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        int max = tests[i].n + 1;
        int *cube = (int *)malloc(max * sizeof(int));
        for (int j = 0; j < max; j++)
        {
            cube[j] = j * j * j;
        }
        if (!testFunction(tests[i].n, max, cube, tests[i].expected))
        {
            printf("Test failed: N = %d, Expected = %s\n", tests[i].n, tests[i].expected ? "true" : "false");
            printf("Got: %s\n", isRamanujan(tests[i].n, max, cube) ? "true" : "false");
            allTestsPassed = false;
        }
        free(cube); 
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void printRamanujanNumbers()
{
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    if (n < 1729)
    {
        printf("No Ramanujan numbers below %d\n", n);
        return;
    }
    if (n > 99999)
    {
        printf("Limit too high. Exiting.\n");
        exit(1);
    }

    int max = n + 1;
    int *cube = (int *)malloc(max * sizeof(int));
    for (int i = 0; i < max; i++)
    {
        cube[i] = i * i * i;
    }

    for (int i = 1729; i <= n; i++)
    {
        if (isRamanujan(i, max, cube))
        {
            printf("%d\n", i);
        }
    }

    free(cube); 
}

int main()
{
    runTests();
    printRamanujanNumbers();
    return 0;
}
