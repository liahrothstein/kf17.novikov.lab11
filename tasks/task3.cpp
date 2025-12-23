#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

#include "../utils/sort.h"
#include "../utils/print_arr.h"
#include "../utils/gen_rand_int.h"

int main() {
    // Открытие файла для записи протокола
    FILE *f = fopen("task3_out.txt", "w");
    if (f == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    int numbers = 13;
    int arr[13]; // Фиксированный размер, так как в Си нельзя int arr[numbers] без VLA (в старых стандартах)
    int A = 20, B = 60; 

    printf("Программа выполняет генерацию и сортировку массива с записью в файл.\n");
    printf("Исполнитель: Новиков Д. А.\nВариант: 14\n");
    
    fprintf(f, "Отчет по задаче 3.\nИсполнитель: Новиков Д. А.\n");

    srand((unsigned int)time(NULL));

    generateRandIntArr(numbers, arr, A, B);

    printf("\n\nСгенерированный массив: ");
    fprintf(f, "Сгенерированный массив: ");
    printArray(arr, numbers, f);
    
    printf("\n\nПроцесс сортировки:\n");
    fprintf(f, "\n\nПроцесс сортировки:\n");
    
    // Передаем файл в функцию сортировки, чтобы писать туда промежуточные шаги
    shiftSort(arr, numbers, f);

    printf("\nИтоговый массив: ");
    fprintf(f, "\nИтоговый массив: ");
    printArray(arr, numbers, f);
    printf("\n");
    fprintf(f, "\n");

    fclose(f); // Закрываем файл
    printf("\nПолный протокол сортировки сохранен в 'task3_out.txt'\n");

    return 0;
}