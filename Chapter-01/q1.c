// Temperature of a city in Fahrenheit degrees is input through the keyboard. Write a program to convert this temperature into Centigrade degrees.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test {
    float fahrenheit;
    float expected;
};

float convertFahrenheitToCentigrade(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

bool testFunction(float fahrenheit, float expected) {
    float result = convertFahrenheitToCentigrade(fahrenheit);
    return fabs(result - expected) < 0.01; // fabs = float absolute value = |float| 
}

void runTests() {
    struct test tests[] = {
        {32, 0},
        {212, 100},
        {98.6, 37},
        {68, 20},
        {0, -17.78}
    };
    
    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].fahrenheit, tests[i].expected)) {
            allTestsPassed = false;
        }
    }
    
    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void convertAndPrintTemperature() {
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    float centigrade = convertFahrenheitToCentigrade(fahrenheit);
    printf("Temperature in Centigrade: %.2f\n", centigrade);
}

int main() {
    runTests();
    convertAndPrintTemperature();
    return 0;
}