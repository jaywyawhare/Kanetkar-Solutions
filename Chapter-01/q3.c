// Paper of size A0 has dimensions 1189 mm x 841 mm. Each subsequent size A(n) is defined as A(n-1) cut in half, parallel to its shorter sides. Thus, paper of size A1 would have dimensions 841 mm x 594 mm. Write a program to calculate and print paper sizes A0, A1, A2, … A8.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test {
    int n;
    int expectedWidth;
    int expectedHeight;
};

struct paperSize {
    int width;
    int height;
};

struct paperSize calculatePaperSize(int n) {
    struct paperSize paperSizes[] = {
        {1189, 841},
        {841, 594},
        {594, 420},
        {420, 297},
        {297, 210},
        {210, 148},
        {148, 105},
        {105, 74},
        {74, 52}
    };
    return paperSizes[n];
}

bool testFunction(int n, int expectedWidth, int expectedHeight) {
    struct paperSize result = calculatePaperSize(n);
    return result.width == expectedWidth && result.height == expectedHeight;
}

void runTests() {
    struct test tests[] = {
        {0, 1189, 841},
        {1, 841, 594},
        {2, 594, 420},
        {3, 420, 297},
        {4, 297, 210},
        {5, 210, 148},
        {6, 148, 105},
        {7, 105, 74},
        {8, 74, 52}
    };
    
    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].n, tests[i].expectedWidth, tests[i].expectedHeight)) {
            allTestsPassed = false;
        }
    }
    
    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void calculateAndPrintPaperSizes() {
    for (int i = 0; i < 9; i++) {
        struct paperSize paperSize = calculatePaperSize(i);
        printf("A%d: %d mm x %d mm\n", i, paperSize.width, paperSize.height);
    }
}

int main() {
    runTests();
    calculateAndPrintPaperSizes();
    return 0;
}