// Write a program to find the range of a set of numbers entered through the keyboard. Range is the difference between the smallest and biggest number in the list.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int numbers[12];
    int size;
    int expectedRange;
};

int range(int numbers[], int size)
{
    int min = numbers[0], max = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max - min;
}

bool testFunction(int numbers[], int size, int expectedRange)
{
    return range(numbers, size) == expectedRange;
}

void runTests()
{
    struct test tests[] = {
        {{1, 2, 3, 4, 5}, 5, 4},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 9},
        {{-1, -2, -3, -4, -5}, 5, 4},
        {{-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, 10, 9},
        {{1, 2, 3, 4, 5, -1, -2, -3, -4, -5}, 10, 10},
        {{1, 2, 3, 4, 5, -1, -2, -3, -4, -5, 0}, 11, 10},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].numbers, tests[i].size, tests[i].expectedRange))
        {
            printf("Test failed: Numbers = {");
            for (int j = 0; j < tests[i].size; j++)
            {
                printf("%d, ", tests[i].numbers[j]);
            }
            printf("}, Expected Range = %d\n", tests[i].expectedRange);
            printf("Got: %d\n", range(tests[i].numbers, tests[i].size));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void findRange()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int numbers[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("Range: %d\n", range(numbers, n));
}

int main()
{
    runTests();
    findRange();
    return 0;
}