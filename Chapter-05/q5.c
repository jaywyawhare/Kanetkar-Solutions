// Write a program to receive an integer and find its octal equivalent. (Hint: To obtain octal equivalent of an integer, divide it continuously by 8 till dividend doesn't become zero, then write the remainders obtained in reverse direction.)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int n;
    int expected;
};

int octal(int n)
{
    int octal = 0, i = 1;
    while (n != 0)
    {
        octal += (n % 8) * i;
        n /= 8;
        i *= 10;
    }
    return octal;
}

bool testFunction(int n, int expected)
{
    return octal(n) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, 0},
        {1, 1},
        {8, 10},
        {10, 12},
        {100, 144},
        {12345, 30071},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].n, tests[i].expected))
        {
            printf("Test failed: N = %d, Expected = %d\n", tests[i].n, tests[i].expected);
            printf("Got: %d\n", octal(tests[i].n));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void findOctal()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Octal value of %d is %d\n", n, octal(n));
}

int main()
{
    runTests();
    findOctal();
    return 0;
}