# Домашнее задание к работе 9

## Условие задач

Задача А. Написать программу, выводящую на экран заданную геометрическую фигуру, нарисованную с помощью заданного символа символов, условия формирования фигуры и задаваемые параметры фигуры в таблице (остальные можно взять константные)

<img width="1272" height="256" alt="image" src="https://github.com/user-attachments/assets/15f28dfa-f084-4a7d-b799-d97fc57f94bf" />


## 1. Алгоритм и блок-схема.

### Алгоритм

1. **Начало**
2. **Организация цикла повторения (`do-while`):**
   - Запуск бесконечного цикла, который прерывается по желанию пользователя.
3. **Ввод исходных данных:**
   - Считать символ для построения (`sym`).
   - Считать стороны `a` и `b`, а также углы `phi1` и `phi2` в градусах.
4. **Вычисления:**
   - Перевести углы из градусов в радианы (`rad1`, `rad2`).
   - Рассчитать высоту верхней и нижней частей фигуры (`h_top`, `h_bot`) и максимальную ширину (`max_width`).
5. **Вывод фигуры:**
   - Вывести верхнюю часть фигуры с помощью вложенных циклов с расчетом пробелов и символов.
   - Вывести нижнюю часть фигуры.
6. **Проверка повторения:**
   - Запросить у пользователя продолжение работы. Если введено `0`, выйти из цикла.
7. **Конец**

### Блок-схема

<img width="1343" height="1369" alt="image" src="https://github.com/user-attachments/assets/e4e28e15-ffea-44fd-a323-4d24d7979138" />


## 2. Реализация программы

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592653589793
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Russian");

    char povtor;

    do {
        char sym;
        double a, b, phi1, phi2;

        printf("Введите символ из которого будет строиться фигура:\n");
        scanf(" %c", &sym);

        printf("Введите сторону a (верхняя часть):\n");
        scanf("%lf", &a);

        printf("Введите сторону b (нижняя часть):\n");
        scanf("%lf", &b);

        printf("Введите угол phi1 (в градусах):\n");
        scanf("%lf", &phi1);

        printf("Введите угол phi2 (в градусах):\n");
        scanf("%lf", &phi2);

        double rad1 = phi1 * PI / 180.0;
        double rad2 = phi2 * PI / 180.0;

        int h_top = (int)(a * sin(rad1 / 2.0) + 0.5);
        if (h_top < 1) h_top = 1;

        int h_bot = (int)(b * sin(rad2 / 2.0) + 0.5);
        if (h_bot < 1) h_bot = 1;

        int max_width = (int)(2.0 * a * sin(rad1 / 2.0) + 0.5);
        if (max_width < 3) max_width = 3;
        if (max_width % 2 == 0) max_width++;

        printf("\nРомбоид:\n");

        for (int i = 0; i < h_top; i++) {
            int spaces_left = max_width / 2 - i;
            for (int s = 0; s < spaces_left; s++) {
                printf(" ");
            }
            if (i == 0) {
                printf("%c", sym);
            }
            else {
                printf("%c", sym);
                int inner_spaces = 2 * i - 1;
                for (int s = 0; s < inner_spaces; s++) {
                    printf(" ");
                }
                printf("%c", sym);
            }
            printf("\n");
        }

        for (int i = 1; i <= h_bot; i++) {
            int spaces_left = (max_width / 2) - h_top + i;
            for (int s = 0; s < spaces_left; s++) {
                printf(" ");
            }
            int current_width = max_width - 2 * spaces_left;
            if (current_width <= 1) {
                printf("%c\n", sym);
                break;
            }
            else {
                printf("%c", sym);
                for (int s = 0; s < current_width - 2; s++) {
                    printf(" ");
                }
                printf("%c\n", sym);
            }
        }

        printf("\nПродолжить ? (Да - введите любое число, Нет - введите 0)\n");
        scanf(" %c", &povtor);
        if (povtor == '0') {
            break;
        }
        povtor = 'y';

    } while (1);

    return 0;
}

## 3. Результаты работы программы

<img width="1172" height="1206" alt="image" src="https://github.com/user-attachments/assets/80468512-5d62-44ef-9a79-4f548198a69a" />


## 4. Информация о разработчике

Плахута Александр Андреевич, бТИИ-262
