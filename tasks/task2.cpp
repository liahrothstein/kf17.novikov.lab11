#define _CRT_SECURE_NO_WARNINGS // Для работы в Visual Studio
#include <stdio.h>

#include "../utils/calc_y.h"

int main() {
    double a, b;
    int N;
    double x, y, h;
    double maxY, minY;
    double xAtMax, xAtMin;

    // 1. Открытие файла для записи (текстовый режим)
    FILE *f = fopen("task2_out.txt", "w"); 
    if (f == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    printf("Программа вычисляет таблицу значений функции Y(x) при разбиении области [a, b] изменения аргумента на N шагов, показывает результат и записывает его в файл");
    printf("\nY(x)=1/(x^2+x+1)");
    printf("\n\nИсполнитель: Новиков Д. А.");
    printf("\nВариант: 14\n");

    // Запись шапки в файл
    fprintf(f, "Отчет по задаче 2.\nИсполнитель: Новиков Д. А., Вариант 14\n");
    fprintf(f, "Функция: Y(x)=1/(x^2+x+1)\n\n");

    printf("\nВведите пожалуйста а: ");
    scanf("%lf", &a);
    printf("Введите пожалуйста b: ");
    scanf("%lf", &b);
    printf("Введите пожалуйста N: ");
    scanf("%d", &N);

    // Запись входных данных в файл
    fprintf(f, "Параметры: a=%.2lf, b=%.2lf, N=%d\n", a, b, N);

    h = (b - a) / N; /* Вычисление шага */

    /* Заголовки таблицы (на экран и в файл) */
    printf("\n------------------------------------\n");
    printf("  No  |      x      |      Y(x)     \n");
    printf("------------------------------------\n");

    fprintf(f, "\n------------------------------------\n");
    fprintf(f, "  No  |      x      |      Y(x)     \n");
    fprintf(f, "------------------------------------\n");

    for (int i = 0; i <= N; ++i) { /* Цикл расчета */
        x = a + i * h; 
        y = calculateY(x); 

        /* Вывод строки таблицы на экран */
        printf(" %4d | %11.4lf | %11.4lf \n", i, x, y);
        
        /* Вывод строки таблицы в файл  */
        fprintf(f, " %4d | %11.4lf | %11.4lf \n", i, x, y);

        if (i == 0) { /* Поиск минимума и максимума */
            maxY = minY = y;
            xAtMax = xAtMin = x;
        } else {
            if (y > maxY) {
                maxY = y;
                xAtMax = x;
            }
            if (y < minY) {
                minY = y;
                xAtMin = x;
            }
        }
    }
    
    printf("------------------------------------\n");
    fprintf(f, "------------------------------------\n");

    /* Вывод результатов */
    printf("\nРезультат:\n");
    printf("Max Y = %.4lf при x = %.4lf\n", maxY, xAtMax);
    printf("Min Y = %.4lf при x = %.4lf\n", minY, xAtMin);

    fprintf(f, "\nРезультат:\n");
    fprintf(f, "Max Y = %.4lf при x = %.4lf\n", maxY, xAtMax);
    fprintf(f, "Min Y = %.4lf при x = %.4lf\n", minY, xAtMin);

    printf("\nДанные успешно записаны в файл 'task2_out.txt'\n");

    // 2. Закрытие файла
    fclose(f); 

    return 0;
}