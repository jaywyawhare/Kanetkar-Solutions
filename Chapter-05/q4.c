// Write a program to enter numbers till the user wants. At the end it should display the count of positive, negative and zeros entered.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test {
    int numbers[10];
    int size;
    int expectedPositive;
    int expectedNegative;
    int expectedZero;
};

void countNumbersInteractive(int *positive, int *negative, int *zero)
{
    int n;
    char choice;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &n);

        if (n > 0)
        {
            (*positive)++;
        }
        else if (n < 0)
        {
            (*negative)++;
        }
        else
        {
            (*zero)++;
        }

        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');
}

void countNumbersFromList(int numbers[], int size, int *positive, int *negative, int *zero)
{
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > 0)
        {
            (*positive)++;
        }
        else if (numbers[i] < 0)
        {
            (*negative)++;
        }
        else
        {
            (*zero)++;
        }
    }
}

bool testFunction(int numbers[], int size, int expectedPositive, int expectedNegative, int expectedZero)
{
    int positive = 0, negative = 0, zero = 0;
    countNumbersFromList(numbers, size, &positive, &negative, &zero);
    return positive == expectedPositive && negative == expectedNegative && zero == expectedZero;
}

void runTests()
{
    struct test tests[] =  {
        {{0}, 1, 0, 0, 1},
        {{1}, 1, 1, 0, 0},
        {{-1}, 1, 0, 1, 0},
        {{100}, 1, 1, 0, 0},
        {{-100}, 1, 0, 1, 0},
        {{0, 1, -1, 2, -2, 0}, 6, 2, 2, 2},
        {{12345, -12345, 0, 1, -1}, 5, 2, 2, 1},
    };
    

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].numbers, tests[i].size, tests[i].expectedPositive, tests[i].expectedNegative, tests[i].expectedZero))
        {
            printf("Test failed: Expected Positive = %d, Expected Negative = %d, Expected Zero = %d\n", tests[i].expectedPositive, tests[i].expectedNegative, tests[i].expectedZero);
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    } else {
        printf("All tests passed.\n");
    }
}

int main()
{
    runTests();
    int positive = 0, negative = 0, zero = 0;
    countNumbersInteractive(&positive, &negative, &zero);
    printf("Positive: %d, Negative: %d, Zero: %d\n", positive, negative, zero);
    return 0;
}
