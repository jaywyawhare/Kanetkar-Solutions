/*
Write a program to print the multiplication table of the number
entered by the user. The table should get displayed in the following
form:
    29 * 1 = 29
    29 * 2 = 58
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int n;
    int expected[10];
};

void multiplicationTable(int n)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", n, i, n * i);
    }
}

bool testFunction(int n, int expected[])
{
    for (int i = 1; i <= 10; i++)
    {
        if (n * i != expected[i - 1])
        {
            return false;
        }
    }
    return true;
}

void runTests()
{
    struct test tests[] = {
        {29, {29, 58, 87, 116, 145, 174, 203, 232, 261, 290}},
        {5, {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}},
        {7, {7, 14, 21, 28, 35, 42, 49, 56, 63, 70}},
        {9, {9, 18, 27, 36, 45, 54, 63, 72, 81, 90}},
        {3, {3, 6, 9, 12, 15, 18, 21, 24, 27, 30}},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].n, tests[i].expected))
        {
            printf("Test failed: N = %d\n", tests[i].n);
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void printTable()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    multiplicationTable(n);
}
int main()
{
    runTests();
    printTable();
    return 0;
}

