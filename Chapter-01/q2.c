// The length and breadth of a rectangle and radius of a circle are input through the keyboard. Write a program to calculate the area and perimeter of the rectangle, and the area and circumference of the circle.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159

struct test {
    float length;
    float breadth;
    float radius;
    float expectedRectangleArea;
    float expectedRectanglePerimeter;
    float expectedCircleArea;
    float expectedCircleCircumference;
};

float calculateRectangleArea(float length, float breadth) {
    return length * breadth;
}

float calculateRectanglePerimeter(float length, float breadth) {
    return 2 * (length + breadth);
}

float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

float calculateCircleCircumference(float radius) {
    return 2 * PI * radius;
}

bool testFunction(float length, float breadth, float radius, float expectedRectangleArea, float expectedRectanglePerimeter, float expectedCircleArea, float expectedCircleCircumference) {
    float resultRectangleArea = calculateRectangleArea(length, breadth);
    float resultRectanglePerimeter = calculateRectanglePerimeter(length, breadth);
    float resultCircleArea = calculateCircleArea(radius);
    float resultCircleCircumference = calculateCircleCircumference(radius);
    return fabs(resultRectangleArea - expectedRectangleArea) < 0.01 && fabs(resultRectanglePerimeter - expectedRectanglePerimeter) < 0.01 && fabs(resultCircleArea - expectedCircleArea) < 0.01 && fabs(resultCircleCircumference - expectedCircleCircumference) < 0.01;
}

void runTests() {
    struct test tests[] = {
        {2, 3, 4, 6, 10, 50.27, 25.13},
        {5, 5, 5, 25, 20, 78.54, 31.42},
        {1, 1, 1, 1, 4, 3.14, 6.28},
        {0, 0, 0, 0, 0, 0, 0}
    };
    
    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].length, tests[i].breadth, tests[i].radius, tests[i].expectedRectangleArea, tests[i].expectedRectanglePerimeter, tests[i].expectedCircleArea, tests[i].expectedCircleCircumference)) {
            allTestsPassed = false;
        }
    }
    
    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void calculateAndPrintRectangle() {
    float length, breadth;
    printf("Enter length of rectangle: ");
    scanf("%f", &length);
    printf("Enter breadth of rectangle: ");
    scanf("%f", &breadth);
    float area = calculateRectangleArea(length, breadth);
    float perimeter = calculateRectanglePerimeter(length, breadth);
    printf("Area of rectangle: %.2f\n", area);
    printf("Perimeter of rectangle: %.2f\n", perimeter);
}

void calculateAndPrintCircle() {
    float radius;
    printf("Enter radius of circle: ");
    scanf("%f", &radius);
    float area = calculateCircleArea(radius);
    float circumference = calculateCircleCircumference(radius);
    printf("Area of circle: %.2f\n", area);
    printf("Circumference of circle: %.2f\n", circumference);
}

int main() {
    runTests();
    calculateAndPrintRectangle();
    calculateAndPrintCircle();
    return 0;
}

