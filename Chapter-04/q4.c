/*
The Body Mass Index (BMI) is defined as ratio of the weight of a person (in kilograms) to the square of the height (in meters). Write a program that receives weight and height, calculates the BMI, and reports the BMI category as per the following table:

    BMI Category                BMI
    Starvation                   < 15
    Anorexic                     15.1 to 17.5
    Underweight                  17.6 to 18.5
    Ideal                        18.6 to 24.9
    Overweight                   25 to 25.9
    Obese                        30 to 30.9
    Morbidly Obese                >= 40
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test
{
    double weight;
    double height;
    char *expected;
};

char *bmiCategory(double weight, double height)
{
    double bmi = weight / (height * height);
    if (bmi < 15)
    {
        return "Starvation";
    }
    else if (bmi >= 15.1 && bmi <= 17.5)
    {
        return "Anorexic";
    }
    else if (bmi >= 17.6 && bmi <= 18.5)
    {
        return "Underweight";
    }
    else if (bmi >= 18.6 && bmi <= 24.9)
    {
        return "Ideal";
    }
    else if (bmi >= 25 && bmi <= 29.9)
    {
        return "Overweight";
    }
    else if (bmi >= 30 && bmi <= 30.9)
    {
        return "Obese";
    }
    else
    {
        return "Morbidly Obese";
    }
}

bool testFunction(double weight, double height, char *expected)
{
    return bmiCategory(weight, height) == expected;
}

void runTests()
{
    struct test tests[] = {
        {20, 1.5, "Starvation"},
        {35, 1.5, "Anorexic"},
        {40, 1.5, "Underweight"},
        {45, 1.5, "Ideal"},
        {55, 1.5, "Ideal"},
        {65, 1.5, "Overweight"},
        {68, 1.5, "Obese"},
        {95, 1.5, "Morbidly Obese"},
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].weight, tests[i].height, tests[i].expected))
        {
            printf("Test failed: Weight = %f, Height = %f, Expected = %s\n", tests[i].weight, tests[i].height, tests[i].expected);
            printf("Got: %s\n", bmiCategory(tests[i].weight, tests[i].height));
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void checkBmiCategory()
{
    double weight, height;
    printf("Enter weight in kg: ");
    scanf("%lf", &weight);
    printf("Enter height in meters: ");
    scanf("%lf", &height);
    printf("BMI Category: %s\n", bmiCategory(weight, height));
}

int main()
{
    runTests();
    checkBmiCategory();
    return 0;
}