#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)

#include <iostream>
#include <stdio.h>

using namespace std;

struct Line {
    double a;
    double b;
};

int main() {
    setlocale(LC_ALL, "ru");
    FILE* file;
    if (fopen_s(&file, "Rezultat.txt", "w") != 0) {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    Line lines[100];
    int i = 0;
    double a, b;

    do {
        printf("Введите коэффициент a: ");
        scanf_s("%lf", &a);
        printf("Введите коэффициент b: ");
        scanf_s("%lf", &b);
        lines[i++] = { a, b };
    } while (a != 0 || b != 0);

    for (int j = 0; j < i; ++j) {
        fprintf(file, "y = %.2lfx + %.2lf\n", lines[j].a, lines[j].b);
    }

    printf("Уравнения записаны в файл Rezultat.txt\n");

    fclose(file);
    return 0;
}