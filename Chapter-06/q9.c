/*
Write a program to print the following pattern:
            1
        2       3
    4       5       6
7       8       9       10

*/

#include <stdio.h>

int main() {
    int rows = 4; 

    for (int i = 1, number = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf("   ");
        }

        for (int j = 1; j <= i; j++) {
            printf("%6d", number++);
        }

        printf("\n");
    }
    return 0;
}