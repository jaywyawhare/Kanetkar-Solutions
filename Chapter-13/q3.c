/*

Implement the Insertion Sort algorithm shown in Figure 13.3 on a set of 25 numbers.

Iteration-1 Iteration-2 Iteration-3 Iteration-4 Result
    44           33         33          22          0-11
    33           44         44          33          1-22
    55           55         55          44          2-33
    22           22         22          55          3-44
    11           11         11          11          4-55

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct test{
    int numbers[25];
    int size;
    int expected[25];
};

void insertionSort(int numbers[], int size){
    for(int i = 1; i < size; i++){
        int key = numbers[i];
        int j = i - 1;
        while(j >= 0 && numbers[j] > key){
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

bool testFunction(int numbers[], int size, int expected[]){
    insertionSort(numbers, size);
    for(int i = 0; i < size; i++){
        if(numbers[i] != expected[i]){
            return false;
        }
    }
    return true;
}

void runTests() {
    struct test tests[] = {
        {{44, 33, 55, 22, 11}, 5, {11, 22, 33, 44, 55}},
        {{5, 4, 3, 2, 1}, 5, {1, 2, 3, 4, 5}},
        {{1, 2, 3, 4, 5}, 5, {1, 2, 3, 4, 5}},
        {{1, 1, 1, 1, 1}, 5, {1, 1, 1, 1, 1}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}}
    };

    bool allTestsPassed = true;

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (!testFunction(tests[i].numbers, tests[i].size, tests[i].expected)) {
            printf("Test failed: Array = {");
            for (int j = 0; j < tests[i].size; j++) {
                printf("%d, ", tests[i].numbers[j]);
            }
            printf("}, Size = %d, Expected = {", tests[i].size);

            for (int j = 0; j < tests[i].size; j++) {
                printf("%d, ", tests[i].expected[j]);
            }

            printf("}\n");

            allTestsPassed = false;

        }

    }

    if (!allTestsPassed) {
        printf("Some tests failed. Exiting.\n");
        exit(1);
    }

}

int main() {
    runTests();
    printf("Code is working fine\n");
    return 0;
}