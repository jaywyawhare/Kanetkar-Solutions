// Angle is is taken as input from keyboard. Write a program to calculate the trigonometric ratios (sin, cos, tan, cosec, sec, cot) of the angle.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265358979323846
#define TOLERANCE 1e-6

struct test
{
    float angle;
    float expectedSin;
    float expectedCos;
    float expectedTan;
    float expectedCosec;
    float expectedSec;
    float expectedCot;
};

float degreesToRadians(float degrees)
{
    return degrees * PI / 180.0;
}

void calculateTrigonometricRatios(float angle)
{
    float radians = degreesToRadians(angle);
    float sinValue = sin(radians);
    float cosValue = cos(radians);
    float tanValue, cosecValue, secValue, cotValue;

    if (fabs(cosValue) < TOLERANCE)
    {
        cosValue = 0.0;
    }

    if (cosValue == 0.0)
    {
        tanValue = INFINITY;
        secValue = INFINITY;
    }
    else
    {
        tanValue = tan(radians);
        secValue = 1 / cosValue;
    }

    if (sinValue == 0.0)
    {
        cosecValue = INFINITY;
        cotValue = INFINITY;
    }
    else
    {
        cosecValue = 1 / sinValue;
        cotValue = 1 / tanValue;
    }

    printf("Sin: %.2f\n", sinValue);
    printf("Cos: %.2f\n", cosValue);
    printf("Tan: %.2f\n", tanValue);
    printf("Cosec: %.2f\n", cosecValue);
    printf("Sec: %.2f\n", secValue);
    printf("Cot: %.2f\n", cotValue);
}

bool testFunction(float angle, float expectedSin, float expectedCos, float expectedTan, float expectedCosec, float expectedSec, float expectedCot)
{
    float radians = degreesToRadians(angle);
    float sinValue = sin(radians);
    float cosValue = cos(radians);
    float tanValue, cosecValue, secValue, cotValue;

    if (fabs(cosValue) < TOLERANCE)
    {
        cosValue = 0.0;
    }

    if (cosValue == 0.0)
    {
        tanValue = INFINITY;
        secValue = INFINITY;
    }
    else
    {
        tanValue = tan(radians);
        secValue = 1 / cosValue;
    }

    if (sinValue == 0.0)
    {
        cosecValue = INFINITY;
        cotValue = INFINITY;
    }
    else
    {
        cosecValue = 1 / sinValue;
        cotValue = 1 / tanValue;
    }

    return fabs(sinValue - expectedSin) < 0.01 &&
           fabs(cosValue - expectedCos) < 0.01 &&
           (isinf(expectedTan) ? isinf(tanValue) : fabs(tanValue - expectedTan) < 0.01) &&
           (isinf(expectedCosec) ? isinf(cosecValue) : fabs(cosecValue - expectedCosec) < 0.01) &&
           (isinf(expectedSec) ? isinf(secValue) : fabs(secValue - expectedSec) < 0.01) &&
           (isinf(expectedCot) ? isinf(cotValue) : fabs(cotValue - expectedCot) < 0.01);
}

void runTests()
{
    struct test tests[] = {
        {0, 0, 1, 0, INFINITY, 1, INFINITY},
        {30, 0.5, 0.866, 0.577, 2, 1.155, 1.732},
        {45, 0.707, 0.707, 1, 1.414, 1.414, 1},
        {60, 0.866, 0.5, 1.732, 1.155, 2, 0.577},
        {90, 1, 0, INFINITY, 1, INFINITY, 0}};

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].angle, tests[i].expectedSin, tests[i].expectedCos, tests[i].expectedTan, tests[i].expectedCosec, tests[i].expectedSec, tests[i].expectedCot))
        {
            printf("Test failed for angle = %.2f\n", tests[i].angle);
            printf("Got: Sin: %.2f, Cos: %.2f, Tan: %.2f, Cosec: %.2f, Sec: %.2f, Cot: %.2f\n",
                   sin(degreesToRadians(tests[i].angle)), cos(degreesToRadians(tests[i].angle)),
                   tan(degreesToRadians(tests[i].angle)), sin(degreesToRadians(tests[i].angle)) != 0 ? 1 / sin(degreesToRadians(tests[i].angle)) : INFINITY,
                   cos(degreesToRadians(tests[i].angle)) != 0 ? 1 / cos(degreesToRadians(tests[i].angle)) : INFINITY,
                   tan(degreesToRadians(tests[i].angle)) != 0 ? 1 / tan(degreesToRadians(tests[i].angle)) : INFINITY);
            printf("Expected: Sin: %.2f, Cos: %.2f, Tan: %.2f, Cosec: %.2f, Sec: %.2f, Cot: %.2f\n",
                   tests[i].expectedSin, tests[i].expectedCos, tests[i].expectedTan,
                   tests[i].expectedCosec, tests[i].expectedSec, tests[i].expectedCot);
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
    else
    {
        printf("All tests passed successfully.\n");
    }
}

void calculateAndPrintTrigonometricRatios()
{
    float angle;
    printf("Enter angle: ");
    scanf("%f", &angle);
    calculateTrigonometricRatios(angle);
}

int main()
{
    runTests();
    calculateAndPrintTrigonometricRatios();
    return 0;
}
