#define _CRT_SECURE_NO_WARNINGS // Для Visual Studio
#include <stdio.h>

int main() {
    FILE *f2 = fopen("result_ex2.dat", "w+t");
    if (f2 == NULL) {
        puts("Ошибка открытия файла!");
        return 1;
    }

    int mas[10];
    for(int i = 0; i < 10; i++) mas[i] = 2 * i + 1;

    printf("\n--- Задача 1 (Пример 2) ---\n");
    printf("Массив записан в файл result_ex2.dat\n");
    
    fprintf(f2, "Массив целых чисел: \n");
    for(int i = 0; i < 10; i++) {
        fprintf(f2, "%d\n", mas[i]); //
    }

    fclose(f2);
    return 0;
}