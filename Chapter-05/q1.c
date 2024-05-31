// Write a program to print all the ASCII values and their equivalent characters using a while loop. The ASCII values vary from 0 to 255.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int n;
    char expected;
};

char ascii(int n)
{
    return n;
}

bool testFunction(int n, char expected)
{
    return ascii(n) == expected;
}

void runTests()
{
    struct test tests[] = {
        {0, '\0'},
        {65, 'A'},
        {97, 'a'},
        {255, '\xFF'}
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].n, tests[i].expected))
        {
            printf("Test failed: ASCII = %d, Expected = %c, Got = %c\n", tests[i].n, tests[i].expected, ascii(tests[i].n));
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

void printAsciiValues()
{
    int i = 0;
    while (i <= 255)
    {
        printf("ASCII value of %d = %c\n", i, ascii(i));
        i++;
    }
}

int main()
{
    runTests();
    printAsciiValues();
    return 0;
}
