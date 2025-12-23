#include <stdio.h>

// Функция вывода массива
void printArray(const int array[], int length, FILE *f) {
    // Вывод на экран
    printf("[");
    for (int i = 0; i < length; i++) {
        if (i != length - 1) printf("%d, ", array[i]);
        else printf("%d", array[i]);
    }
    printf("]");

    // Вывод в файл (если файл открыт)
    if (f != NULL) {
        fprintf(f, "[");
        for (int i = 0; i < length; i++) {
            if (i != length - 1) fprintf(f, "%d, ", array[i]);
            else fprintf(f, "%d", array[i]);
        }
        fprintf(f, "]");
    }
}