#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    char povtor;

    do {
        long long n;
        long long temp;
        int sum = 0;

        printf("Введите целое число: ");
        scanf("%lld", &n);

        temp = n;
        if (temp < 0) {
            temp = -temp;
        }

        if (temp == 0) {
            if (0 >= 7) {
                sum += 0;
            }
        }
        else {
            while (temp > 0) {
                int digit = temp % 10;
                if (digit >= 7) {
                    sum += digit;
                }
                temp /= 10;
            }
        }

        printf("Сумма цифр, которые больше или равны 7: %d\n\n", sum);

        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &povtor);
        printf("\n");

    } while (povtor == 'y' || povtor == 'Y');

    return 0;
}