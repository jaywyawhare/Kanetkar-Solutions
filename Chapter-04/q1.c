// If the lengths of three sides of a triangle are input through the keyboard, write a program to check whether the triangle is isosceles, equilateral, scalene or right angled triangle.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct test {
    int a, b, c;
    char expected[20];
};

char *triangleType(int a, int b, int c) {
    if (a == b && b == c) {
        return "Equilateral";
    } else if (a == b || b == c || c == a) {
        return "Isosceles";
    } else if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
        return "Right Angled";
    } else {
        return "Scalene";
    }
}

bool testFunction(int a, int b, int c, char *expected) {
    return strcmp(triangleType(a, b, c), expected) == 0;
}

void runTests() {
    struct test tests[] = {
        {3, 3, 3, "Equilateral"},
        {3, 3, 4, "Isosceles"},
        {3, 4, 5, "Right Angled"},
        {3, 4, 6, "Scalene"},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].a, tests[i].b, tests[i].c, tests[i].expected)) {
            printf("Test failed: A = %d, B = %d, C = %d, Expected = %s\n", tests[i].a, tests[i].b, tests[i].c, tests[i].expected);
            printf("Got: %s\n", triangleType(tests[i].a, tests[i].b, tests[i].c));
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        printf("All tests passed\n");
    }
}

void printTriangleType() {
    int a, b, c;
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("The triangle is %s\n", triangleType(a, b, c));
}

int main() {
    runTests();
    printTriangleType();
    return 0;
}