// Population of a town today is 100000. The population has increased steadily at the rate of 10% per year for the last 10 years. Write a program to determine the population at the end of each year in the last decade.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    int population;
    int years;
    int expected[10];
};

void populationGrowth(int population, int years, int expected[])
{
    for (int i = 0; i < years; i++)
    {
        population += population * 0.1;
        expected[i] = population;
    }
}

bool testFunction(int population, int years, int expected[])
{
    int result[10];
    populationGrowth(population, years, result);
    for (int i = 0; i < years; i++)
    {
        if (result[i] != expected[i])
        {
            return false;
        }
    }
    return true;
}

void runTests()
{
    struct test tests[] = {
        {100000, 10, {110000, 121000, 133100, 146410, 161051, 177156, 194871, 214358, 235793, 259372}},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].population, tests[i].years, tests[i].expected))
        {
            printf("Test failed: Population = %d, Years = %d\n", tests[i].population, tests[i].years);
            printf("Expected: ");
            for (int j = 0; j < tests[i].years; j++)
            {
                printf("%d ", tests[i].expected[j]);
            }
            printf("\n");
            printf("Got: ");
            int result[10];
            populationGrowth(tests[i].population, tests[i].years, result);
            for (int j = 0; j < tests[i].years; j++)
            {
                printf("%d ", result[j]);
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

void printPopulationGrowth()
{
    int population = 100000;
    for (int i = 0; i < 10; i++)
    {
        population += population * 0.1;
        printf("%d\n", population);
    }
}

int main()
{
    runTests();
    printPopulationGrowth();
    return 0;
}