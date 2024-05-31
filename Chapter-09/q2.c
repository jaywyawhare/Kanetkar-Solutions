// Define a function that receives weight of a commodity in Kilograms and returns the equivalent weight in Grams, Tons and Pounds. Call this function from main( ) and print the results in main( ).

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define TOLERANCE 0.0001

struct test
{
    double weight;
    double expected[3];
};

void weightConversion(double weight, double *grams, double *tons, double *pounds)
{
    *grams = weight * 1000;
    *tons = weight / 1000;
    *pounds = weight * 2.20462;
}

bool testFunction(double weight, double expected[])
{
    double grams, tons, pounds;
    weightConversion(weight, &grams, &tons, &pounds);
    return fabs(grams - expected[0]) < TOLERANCE && fabs(tons - expected[1]) < TOLERANCE && fabs(pounds - expected[2]) < TOLERANCE;
}

void runTests()
{
    struct test tests[] = {
        {1, {1000, 0.001, 2.20462}},
        {2, {2000, 0.002, 4.40924}},
        {3, {3000, 0.003, 6.61386}},
        {4, {4000, 0.004, 8.81848}},
        {5, {5000, 0.005, 11.0231}},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].weight, tests[i].expected))
        {
            printf("Test failed: Weight = %f, Expected = %f grams, %f tons, %f pounds\n", tests[i].weight, tests[i].expected[0], tests[i].expected[1], tests[i].expected[2]);
            double grams, tons, pounds;
            weightConversion(tests[i].weight, &grams, &tons, &pounds);
            printf("Got: %f grams, %f tons, %f pounds\n", grams, tons, pounds);
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
    double kilograms;
    printf("Enter weight in Kilograms: ");
    scanf("%lf", &kilograms);
    double grams, tons, pounds;

    weightConversion(kilograms, &grams, &tons, &pounds);

    printf("Weight in Grams: %f\n", grams);
    printf("Weight in Tons: %f\n", tons);
    printf("Weight in Pounds: %f\n", pounds);
}

int main()
{
    runTests();
    printTable();
    return 0;
}