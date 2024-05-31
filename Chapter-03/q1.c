// A five-digit number is entered through the keyboard. Write a program to obtain the reversed number and to determine whether the original and reversed numbers are equal or not.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int n;
    int expectedReversed;
    bool expectedEqual;
    bool isFiveDigit;
};

int reverseNumber(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

bool testFunction(int n, int expectedReversed, bool expectedEqual, bool isFiveDigit)
{
    int reversed = reverseNumber(n);
    bool equal = n == reversed;
    return reversed == expectedReversed && equal == expectedEqual;
}

void runTests()
{
    struct test tests[] = {
        {12345, 54321, false, true},
        {11111, 11111, true, true},
        {54321, 12345, false, true},
        {10000, 1, false, true},
        {0, 0, true, false}};

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].n, tests[i].expectedReversed, tests[i].expectedEqual, tests[i].isFiveDigit))
        {
            printf("Test failed: N = %d, Expected Reversed = %d, Expected Equal = %d\n", tests[i].n, tests[i].expectedReversed, tests[i].expectedEqual);
            printf("Got: Reversed = %d, Equal = %d\n", reverseNumber(tests[i].n), tests[i].n == reverseNumber(tests[i].n));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void reverseAndPrint()
{
    int n;
    printf("Enter a five-digit number: ");
    scanf("%d", &n);
    if (n < 10000 || n > 99999)
    {
        printf("Please enter a five-digit number.\n");
        return;
    }
    int reversed = reverseNumber(n);
    printf("Reversed number: %d\n", reversed);
    if (n == reversed)
    {
        printf("The original and reversed numbers are equal.\n");
    }
    else
    {
        printf("The original and reversed numbers are not equal.\n");
    }
}

int main()
{
    runTests();
    reverseAndPrint();
    return 0;
}