// Write a program to print 24 hours of a day with suitable suffixes like AM, PM, Noon, Midnight.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int hour;
    char *expected;
};

char *timeOfDay(int hour)
{
    if (hour == 0)
    {
        return "Midnight";
    }
    else if (hour == 12)
    {
        return "Noon";
    }
    else if (hour < 12)
    {
        return "AM";
    }
    else
    {
        return "PM";
    }
}

bool testFunction(int hour, char *expected)
{
    return timeOfDay(hour) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, "Midnight"},
        {1, "AM"},
        {11, "AM"},
        {12, "Noon"},
        {13, "PM"},
        {23, "PM"},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].hour, tests[i].expected))
        {
            printf("Test failed: Hour = %d, Expected = %s\n", tests[i].hour, tests[i].expected);
            printf("Got: %s\n", timeOfDay(tests[i].hour));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void printTimeOfDay()
{
    printf("Hour\tTime of Day\n");
    for (int hour = 0; hour < 24; hour++)
    {
        printf("%d\t%s\n", hour, timeOfDay(hour));
    }
}

int main()
{
    runTests();
    printTimeOfDay();
    return 0;
}