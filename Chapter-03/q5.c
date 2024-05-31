// Given the length and breadth of a rectangle, write a program to find whether the area of the rectangle is greater than its perimeter. For example, the area of the rectangle with length = 5 and breadth = 4 is greater than its perimeter.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test {
    float length;
    float breadth;
    bool expected;
};

bool isAreaGreaterThanPerimeter(float length, float breadth) {
    return length * breadth > 2 * (length + breadth);
}

bool testFunction(float length, float breadth, bool expected) {
    return isAreaGreaterThanPerimeter(length, breadth) == expected;
}

void runTests() {
    struct test tests[] = {
        {5, 4, true},
        {3, 3, false},
        {1, 1, false},
        {0, 0, false}
    };
    
    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].length, tests[i].breadth, tests[i].expected)) {
            printf("Test failed: Length = %.2f, Breadth = %.2f, Expected = %s\n", tests[i].length, tests[i].breadth, tests[i].expected ? "true" : "false");
            printf("Got: %s\n", isAreaGreaterThanPerimeter(tests[i].length, tests[i].breadth) ? "true" : "false");
            allTestsPassed = false;
        }
    }
    
    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void findAreaGreaterThanPerimeter() {
    float length, breadth;
    printf("Enter length and breadth of the rectangle: ");
    scanf("%f %f", &length, &breadth);
    if (isAreaGreaterThanPerimeter(length, breadth)) {
        printf("Area of the rectangle with length = %.2f and breadth = %.2f is greater than its perimeter.\n", length, breadth);
    } else {
        printf("Area of the rectangle with length = %.2f and breadth = %.2f is not greater than its perimeter.\n", length, breadth);
    }
}

int main() {
    runTests();
    findAreaGreaterThanPerimeter();
    return 0;
}