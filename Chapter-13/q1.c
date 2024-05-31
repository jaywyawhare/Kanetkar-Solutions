// Twenty-five numbers are entered from the keyboard into an array. Write a program to find out how many of them are positive, how many are negative, how many are even and how many odd.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int numbers[25];
    int size;
    int expectedPositive;
    int expectedNegative;
    int expectedEven;
    int expectedOdd;
};

void countNumbers(int numbers[], int size, int *positive, int *negative, int *even, int *odd)
{
    *positive = 0;
    *negative = 0;
    *even = 0;
    *odd = 0;

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

        if (numbers[i] % 2 == 0)
        {
            (*even)++;
        }
        else
        {
            (*odd)++;
        }
    }
}

bool testFunction(int numbers[], int size, int expectedPositive, int expectedNegative, int expectedEven, int expectedOdd)
{
    int positive, negative, even, odd;
    countNumbers(numbers, size, &positive, &negative, &even, &odd);
    return positive == expectedPositive && negative == expectedNegative && even == expectedEven && odd == expectedOdd;
}

void runTests()
{
    struct test tests[] = {
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10, 0, 5, 5},
        {{-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, 10, 0, 10, 5, 5},
        {{1, -2, 3, -4, 5, -6, 7, -8, 9, -10}, 10, 5, 5, 5, 5},
        {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 10, 0, 0, 10, 0},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, 20, 10, 10, 10, 10}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    bool allTestsPassed = true;

    for (int i = 0; i < numTests; i++)
    {
        if (!testFunction(tests[i].numbers, tests[i].size, tests[i].expectedPositive, tests[i].expectedNegative, tests[i].expectedEven, tests[i].expectedOdd))
        {
            allTestsPassed = false;
            printf("Test Failed\n");
            printf("Input: {");
            for (int j = 0; j < tests[i].size; j++)
            {
                printf("%d", tests[i].numbers[j]);
                if (j != tests[i].size - 1)
                {
                    printf(", ");
                }
            }
            printf("}\n");
            printf("Expected: %d positive, %d negative, %d even, %d odd\n", tests[i].expectedPositive, tests[i].expectedNegative, tests[i].expectedEven, tests[i].expectedOdd);
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed\n");
        exit(1);
    }

}

void getInput(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
}

void printResults(){
    int numbers[25];
    int size = 25;
    int positive, negative, even, odd;

    getInput(numbers, size);
    countNumbers(numbers, size, &positive, &negative, &even, &odd);

    printf("Positive numbers: %d\n", positive);
    printf("Negative numbers: %d\n", negative);
    printf("Even numbers: %d\n", even);
    printf("Odd numbers: %d\n", odd);
}

int main()
{
    runTests();
    printResults();
    return 0;
}