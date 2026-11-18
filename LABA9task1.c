#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", 20 + i - j);
        }
        printf("\n");
    }

    return 0;
}