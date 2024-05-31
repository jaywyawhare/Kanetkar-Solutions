// If a five-digit number is input through the keyboard, write a program to calculate the sum of its digits.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test {
    int n;
    int expected;
};

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool testFunction(int n, int expected) {
    return sumOfDigits(n) == expected;
}

void runTests() {
    struct test tests[] = {
        {12345, 15},
        {11111, 5},
        {54321, 15},
        {10000, 1},
        {0, 0}
    };
    
    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].n, tests[i].expected)) {
            allTestsPassed = false;
        }
    }
    
    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }
}

void calculateAndPrintSumOfDigits() {
    int n;
    printf("Enter a five-digit number: ");
    scanf("%d", &n);
    if (n < 10000 || n > 99999) {
        printf("Please enter a five-digit number.\n");
        return;
    }
    int sum = sumOfDigits(n);
    printf("Sum of digits: %d\n", sum);
}

int main() {
    runTests();
    calculateAndPrintSumOfDigits();
    return 0;
}