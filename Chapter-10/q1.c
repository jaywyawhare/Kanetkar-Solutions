/*
A positive integer is entered through the keyboard, write a function to find the binary equivalent of this number:
    (1) Without using recursion
    (2) Using recursion
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int number;
    int expected;
};

int binaryEquivalentWithoutRecursion(int number)
{
    int binary = 0, i = 1;
    while (number > 0)
    {
        binary += (number % 2) * i;
        number /= 2;
        i *= 10;
    }
    return binary;
}

int binaryEquivalentUsingRecursion(int number)
{
    if (number == 0)
    {
        return 0;
    }
    return (number % 2) + 10 * binaryEquivalentUsingRecursion(number / 2);
}

bool testFunction(int number, int expected)
{
    return binaryEquivalentWithoutRecursion(number) == expected && binaryEquivalentUsingRecursion(number) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, 0},
        {1, 1},
        {10, 1010},
        {25, 11001},
        {100, 1100100}
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].number, tests[i].expected))
        {
            printf("Test failed: Number = %d, Expected = %d\n", tests[i].number, tests[i].expected);
            printf("Got: %d, %d\n", binaryEquivalentWithoutRecursion(tests[i].number), binaryEquivalentUsingRecursion(tests[i].number));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

}

void printBinaryEquivalent()
{
    int input = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &input);
    printf("Binary equivalent of %d without recursion: %d\n", input, binaryEquivalentWithoutRecursion(input));
    printf("Binary equivalent of %d using recursion: %d\n", input, binaryEquivalentUsingRecursion(input));
}

int main()
{
    runTests();
    printBinaryEquivalent();
    return 0;
}