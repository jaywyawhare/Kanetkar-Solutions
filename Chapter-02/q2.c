// Write a program to recieve a Caresian co-ordinate (x, y) of a point and convert them into polar co-ordinates (r, θ).
// Hint : r = sqrt(x^2 + y^2) and θ = tan^-1(y/x)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

struct test {
    float x;
    float y;
    float expectedR;
    float expectedTheta;
};

struct polarCoordinate {
    float r;
    float theta;
};

struct polarCoordinate convertToPolarCoordinate(float x, float y) {
    struct polarCoordinate polarCoordinate;
    polarCoordinate.r = sqrt(x * x + y * y);
    if(x == 0) {
        if(y > 0) {
            polarCoordinate.theta = PI / 2;
        } else if(y < 0) {
            polarCoordinate.theta = -PI / 2;
        } else {
            polarCoordinate.theta = 0;
        }
    } else {
        polarCoordinate.theta = atan(y / x);
    }
    return polarCoordinate;
}

bool testFunction(float x, float y, float expectedR, float expectedTheta) {
    struct polarCoordinate result = convertToPolarCoordinate(x, y);
    return fabs(result.r - expectedR) < 0.01 && fabs(result.theta - expectedTheta) < 0.01;
}

void runTests() {
    struct test tests[] = {
        {1, 1, 1.41, 0.79},
        {3, 4, 5, 0.93},
        {5, 12, 13, 1.18},
        {0, 0, 0, 0}
    };
    
    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].x, tests[i].y, tests[i].expectedR, tests[i].expectedTheta)) {
            printf("Test failed for x = %.2f, y = %.2f\n", tests[i].x, tests[i].y);
            allTestsPassed = false;
        }
    }
    
    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void convertAndPrintPolarCoordinate() {
    float x, y;
    printf("Enter Cartesian coordinates (x, y): ");
    scanf("%f %f", &x, &y);
    struct polarCoordinate polarCoordinate = convertToPolarCoordinate(x, y);
    printf("Polar coordinates (r, theta): %.2f, %.2f\n", polarCoordinate.r, polarCoordinate.theta);
}

int main() {
    runTests();
    convertAndPrintPolarCoordinate();
    return 0;
}