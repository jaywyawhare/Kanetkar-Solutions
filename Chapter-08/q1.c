// Any year is entered through the keyboard. Write a function to determine whether the year is a leap year or not.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int year;
    bool expected;
};

bool isLeapYear(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool testFunction(int year, bool expected)
{
    return isLeapYear(year) == expected;
}

void runTests()
{
    struct test tests[] = {
        {2000, true},
        {2004, true},
        {2008, true},
        {2012, true},
        {2016, true},
        {2020, true},
        {2024, true},
        {2028, true},
        {2032, true},
        {2036, true},
        {2040, true},
        {2044, true},
        {2048, true},
        {2100, false},
        {2200, false},
        {2300, false},
        {2400, true},
        {2500, false},
        {2600, false},
        {2700, false},
        {2800, true},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].year, tests[i].expected))
        {
            printf("Test failed: Year = %d, Expected = %s\n", tests[i].year, tests[i].expected ? "true" : "false");
            printf("Got: %s\n", isLeapYear(tests[i].year) ? "true" : "false");
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void checkLeapYear()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (isLeapYear(year))
    {
        printf("%d is a leap year.\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }
}

int main()
{
    runTests();
    checkLeapYear();
    return 0;
}
