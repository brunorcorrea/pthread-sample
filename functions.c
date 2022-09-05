#include "functions.h"

int sumNumbers(int a, int b) {
    return a + b;
}

int sumArrays(int* a, int* b, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i] + b[i];
    }
    return sum;
}