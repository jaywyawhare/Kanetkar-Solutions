// A positive integer is entered through the keyboard. Write a function to obtain the prime factors of this number.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int number;
    int expected[100];
};

void primeFactors(int number, int factors[])
{
    int i = 0;
    while (number % 2 == 0)
    {
        factors[i++] = 2;
        number = number / 2;
    }

    for (int j = 3; j * j <= number; j = j + 2)
    {
        while (number % j == 0)
        {
            factors[i++] = j;
            number = number / j;
        }
    }

    if (number > 2)
    {
        factors[i++] = number;
    }
}

bool testFunction(int number, int expected[])
{
    int factors[100] = {0};
    primeFactors(number, factors);

    for (int i = 0; i < 100; i++)
    {
        if (factors[i] != expected[i])
        {
            return false;
        }
        if (expected[i] == 0)
        {
            break;
        }
    }
    return true;
}

void runTests()
{
    struct test tests[] = {
        {12, {2, 2, 3}},
        {30, {2, 3, 5}},
        {50, {2, 5, 5}},
        {72, {2, 2, 2, 3, 3}},
        {97, {97}},
        {100, {2, 2, 5, 5}},
    };
    
    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        int number = tests[i].number;
        if (!testFunction(number, tests[i].expected))
        {
            printf("Test failed: Number = %d\n", number);
            printf("Expected: ");
            for (int j = 0; j < 100; j++)
            {
                if (tests[i].expected[j] == 0)
                {
                    break;
                }
                printf("%d ", tests[i].expected[j]);
            }
            printf("\n");
            printf("Got: ");
            int factors[100] = {0};
            primeFactors(number, factors);
            for (int j = 0; j < 100; j++)
            {
                if (factors[j] == 0)
                {
                    break;
                }
                printf("%d ", factors[j]);
            }
            printf("\n");
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

}

void checkPrimeFactors()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int factors[100] = {0};
    primeFactors(number, factors);

    printf("Prime factors of %d are: ", number);
    for (int i = 0; i < 100; i++)
    {
        if (factors[i] == 0)
        {
            break;
        }
        printf("%d ", factors[i]);
    }
    printf("\n");
}

int main()
{
    runTests();
    checkPrimeFactors();
    return 0;
}
