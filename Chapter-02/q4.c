// Wind-chill factor is the felt air temperature on exposed skin due to wind. The wind chill temperature is always lower than the air temperature, and is calculated as per the following formula:
// wcf = 35.74 + 0.6215t + (0.4275t - 35.75) * v^0.16
// where t is the temperature and v is the wind velocity. Write a program to receive values of temperature and wind velocity and calculate the wind-chill factor.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct test
{
    float temperature;
    float windVelocity;
    float expectedWindChillFactor;
};

float calculateWindChillFactor(float temperature, float windVelocity)
{
    return 35.74 + 0.6215 * temperature + (0.4275 * temperature - 35.75) * pow(windVelocity, 0.16);
}

bool testFunction(float temperature, float windVelocity, float expectedWindChillFactor)
{
    float result = calculateWindChillFactor(temperature, windVelocity);
    return fabs(result - expectedWindChillFactor) < 0.01;
}

void runTests()
{
    struct test tests[] = {
        {30.0, 10.0, 21.25},  
        {25.0, 20.0, 10.80},
        {10.0, 15.0, -6.59},
        {0.0, 25.0, -24.09},
        {-10.0, 30.0, -39.45}
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].temperature, tests[i].windVelocity, tests[i].expectedWindChillFactor))
        {
            printf("Test failed for temperature = %.2f, windVelocity = %.2f, Got: %.2f, Expected: %.2f\n", tests[i].temperature, tests[i].windVelocity, calculateWindChillFactor(tests[i].temperature, tests[i].windVelocity), tests[i].expectedWindChillFactor);
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void calculateAndPrintWindChillFactor()
{
    float temperature, windVelocity;
    printf("Enter temperature: ");
    scanf("%f", &temperature);
    printf("Enter wind velocity: ");
    scanf("%f", &windVelocity);
    float windChillFactor = calculateWindChillFactor(temperature, windVelocity);
    printf("Wind chill factor: %.2f\n", windChillFactor);
}

int main()
{
    runTests();
    calculateAndPrintWindChillFactor();
    return 0;
}