// According to Gregorian calendar, it was Monday on the date 01/01/01. If any year is input through the keyboard write a program to find out what is the day on 1st January of this year.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int year;
    char expected;
};

char dayOnFirstJanuary(int year)
{
    int q = 1; 
    int m = 13; 
    int K = (year - 1) % 100; 
    int J = (year - 1) / 100; 

    int h = (q + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    
    switch (h)
    {
        case 0:
            return 's'; 
        case 1:
            return 'u'; 
        case 2:
            return 'm'; 
        case 3:
            return 't'; 
        case 4:
            return 'w'; 
        case 5:
            return 'r'; 
        case 6:
            return 'f'; 
        default:
            return 'n'; 
    }
}

bool testFunction(int year, char expected)
{
    return dayOnFirstJanuary(year) == expected;
}

void runTests()
{
    struct test tests[] = {
        {2000, 's'},
        {2001, 'm'},
        {1900, 'm'},
        {2100, 'f'},
        {2400, 's'},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].year, tests[i].expected))
        {
            printf("Test failed: Year = %d, Expected = %c, Got = %c\n", tests[i].year, tests[i].expected, dayOnFirstJanuary(tests[i].year));
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

void checkDayOnFirstJanuary()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    char day = dayOnFirstJanuary(year);
    switch (day)
    {
        case 's':
            printf("The day on 1st January %d is Saturday.\n", year);
            break;
        case 'u':
            printf("The day on 1st January %d is Sunday.\n", year);
            break;
        case 'm':
            printf("The day on 1st January %d is Monday.\n", year);
            break;
        case 't':
            printf("The day on 1st January %d is Tuesday.\n", year);
            break;
        case 'w':
            printf("The day on 1st January %d is Wednesday.\n", year);
            break;
        case 'r':
            printf("The day on 1st January %d is Thursday.\n", year);
            break;
        case 'f':
            printf("The day on 1st January %d is Friday.\n", year);
            break;
        default:
            printf("Error determining the day.\n");
            break;
    }
}

int main()
{
    runTests();
    checkDayOnFirstJanuary();
    return 0;
}
