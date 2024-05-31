// Write a program to recieve values of latitude (L1, L2) and longitude (G1, G2) in degrees of two places on the earth and output the distance between them in nautical miles. The formula for distance in nautical miles is:
// Distance = 3963 * arccos(sin(L1) * sin(L2) + cos(L1) * cos(L2) * cos(G2 - G1))

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.14159265358979323846
#define RADIUS 3963

struct test
{
    float L1;
    float L2;
    float G1;
    float G2;
    float expectedDistance;
};

float degreesToRadians(float degrees)
{
    return degrees * PI / 180.0;
}

float calculateDistance(float L1, float L2, float G1, float G2)
{
    L1 = degreesToRadians(L1);
    L2 = degreesToRadians(L2);
    G1 = degreesToRadians(G1);
    G2 = degreesToRadians(G2);

    float distance = RADIUS * acos(sin(L1) * sin(L2) + cos(L1) * cos(L2) * cos(G2 - G1));
    return distance;
}

bool testFunction(float L1, float L2, float G1, float G2, float expectedDistance)
{
    float result = calculateDistance(L1, L2, G1, G2);
    return fabs(result - expectedDistance) < 0.01;
}

void runTests()
{
    struct test tests[] = {
        {0.0, 0.0, 0.0, 90.0, 6225.07},
        {0.0, 0.0, 0.0, 180.0, 12450.13},
        {37.7749, 34.0522, -122.4194, -118.2437, 347.79},
        {51.5074, 40.7128, -0.1278, -74.0060, 3464.89}};

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].L1, tests[i].L2, tests[i].G1, tests[i].G2, tests[i].expectedDistance))
        {
            printf("Test failed for L1 = %.2f, L2 = %.2f, G1 = %.2f, G2 = %.2f, Got: %.2f, Expected: %.2f\n", tests[i].L1, tests[i].L2, tests[i].G1, tests[i].G2, calculateDistance(tests[i].L1, tests[i].L2, tests[i].G1, tests[i].G2), tests[i].expectedDistance);
            allTestsPassed = false;
        }
    }

    if (!allTestsPassed)
    {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void convertAndPrintDistance()
{
    float L1, L2, G1, G2;
    printf("Enter the value of L1: ");
    scanf("%f", &L1);
    printf("Enter the value of L2: ");
    scanf("%f", &L2);
    printf("Enter the value of G1: ");
    scanf("%f", &G1);
    printf("Enter the value of G2: ");
    scanf("%f", &G2);

    float distance = calculateDistance(L1, L2, G1, G2);
    printf("Distance between the two places is %.2f nautical miles\n", distance);
}

int main()
{
    runTests();
    convertAndPrintDistance();
    return 0;
}
