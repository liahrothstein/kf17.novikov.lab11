#include <stdlib.h>

void generateRandIntArr(int numbers, int arr[], int A, int B) {
    for (int i = 0; i < numbers; i++) {
        arr[i] = A + rand() % (B - A + 1);
    }
}