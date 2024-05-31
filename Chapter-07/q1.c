/*
Write a program to find the grace marks for a student using switch. The user should enter the class obtained by the student and the number of subjects he has failed in. Use the following logic:
    - If the student gets first class and he fails in more than 3 subjects, he does not get any grace. Otherwise, he gets a grace of 5 marks per subject.
    - If the student gets second class and he fails in more than 2 subjects, he does not get any grace. Otherwise, he gets a grace of 4 marks per subject.
    - If the student gets third class and he fails in more than 1 subject, then he does not get any grace. Otherwise, he gets a grace of 5 marks.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int class;
    int failedSubjects;
    int expected;
};

int graceMarks(int class, int failed, int expected)
{
    switch (class)
    {
    case 1:
        return failed > 3 ? 0 : failed * 5;
    case 2:
        return failed > 2 ? 0 : failed * 4;
    case 3:
        return failed > 1 ? 0 : 5;
    default:
        return -1;
    }
}

bool testFunction(int class, int failed, int expected)
{
    return graceMarks(class, failed, expected) == expected;
}

void runTests()
{
    struct test tests[] = {
        {1, 4, 0},
        {1, 3, 15},
        {1, 2, 10},
        {1, 1, 5},
        {1, 0, 0},
        {2, 3, 0},
        {2, 2, 8},
        {2, 1, 4},
        {2, 0, 0},
        {3, 2, 0},
        {3, 1, 5},
        {3, 0, 5},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].class, tests[i].failedSubjects, tests[i].expected))
        {
            printf("Test failed: Class = %d, Failed = %d, Expected = %d\n", tests[i].class, tests[i].failedSubjects, tests[i].expected);
            printf("Got: %d\n", graceMarks(tests[i].class, tests[i].failedSubjects, tests[i].expected));
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
    printf("Class\tFailed\tGrace\n");
    for (int class = 1; class <= 3; class++)
    {
        for (int failed = 0; failed <= 4; failed++)
        {
            printf("%d\t%d\t%d\n", class, failed, graceMarks(class, failed, 0));
        }
    }
}

int main()
{
    runTests();
    printTable();
    return 0;
}