#define _CRT_SECURE_NO_WARNINGS // Для Visual Studio

#include <stdio.h>

int main() {
    FILE *f1 = fopen("result_ex1.dat", "w+t"); // Открытие текстового файла для записи
    if (f1 == NULL) {
        puts("Ошибка открытия файла!");
        return 1;
    }

    int a = 2, b = 3;
    printf("--- Задача 1 (Пример 1) ---\n");
    printf("Результаты вычислений: %d %d %d\n", a, b, a + b);
    
    // Запись в файл
    fprintf(f1, "Результаты вычислений: \n");
    fprintf(f1, "%d %d %d\n", a, b, a + b);
    
    fclose(f1); //

    return 0;
}