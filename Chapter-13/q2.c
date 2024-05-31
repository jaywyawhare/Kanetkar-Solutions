// If an array arr contains n elements, then write a program to check if arr[ 0 ] = arr[ n - 1 ], arr[ 1 ] = arr[ n - 2 ] and so on.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int arr[10];
    int n;
    bool expected;
};

bool checkArray(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool testFunction(int arr[], int n, bool expected)
{
    return checkArray(arr, n) == expected;
}

void runTests()
{
    struct test tests[] = {
        {{1, 2, 3, 2, 1}, 5, true},
        {{1, 2, 3, 4, 5}, 5, false}
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].arr, tests[i].n, tests[i].expected))
        {
            printf("Test failed: Array = {");
            for (int j = 0; j < tests[i].n; j++)
            {
                printf("%d, ", tests[i].arr[j]);
            }
            printf("}, N = %d, Expected = %s\n", tests[i].n, tests[i].expected ? "true" : "false");
            printf("Got: %s\n", checkArray(tests[i].arr, tests[i].n) ? "true" : "false");
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void input(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (checkArray(arr, n))
    {
        printf("The array is symmetric.\n");
    }
    else
    {
        printf("The array is not symmetric.\n");
    }
}

int main()
{
    runTests();
    input();
    return 0;
}
