// 2 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int** memory(int row, int col)
{
    int **mas;
    mas = (int**)calloc(row, sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        mas[i] = (int*)calloc(col, sizeof(int));
    }
    return mas;
}

void output_array(int** mas, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printf("\n");
        for (int j = 0; j < col; j++)
        {
            if ((mas[i][j]) == -1)
                j = col;
            else
                printf("%d ", (mas[i][j]));
        }
    }
}

void main(void)
{
    int **mas, row, col, k;
    printf("Enter the number of rows: ");
    while ((scanf_s("%d", &row)) != 1 || (getchar() != '\n'))
    {
        printf("Wrong input. Enter the number of rows: ");
        while (getchar() != '\n');
    }
    printf("Enter the maximum number of elements in the row: ");
    while ((scanf_s("%d", &col) != 1) || (getchar() != '\n'))
    {
        printf("Wrong input. Enther the maximum number of elements in the row: ");
        while (getchar() != '\n');
    }
    printf("Enter the k: ");
    while ((scanf_s("%d", &k)) != 1 || (k < 1) ||
        (getchar() != '\n'))
    {
        printf("Wrong input. Enter the k: ");
        while (getchar() != '\n');
    }
    mas = memory(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the positive [%d][%d] element of array: ", (i + 1), (j + 1));
            while ((scanf_s("%d", &mas[i][j]) != 1) || (mas[i][j] < -1) || (mas[i][j] == 0) || (mas[i][0] == -1) || (getchar() != '\n'))
            {
                printf("Wrong input. Enter the positive [%d][%d] element of array: ", (i + 1), (j + 1));
                while (getchar() != '\n');
            }
            if (mas[i][j] == -1)
                j = col;
        }
    }
    printf("Array: ");
    output_array(mas, row, col);
    array_change(mas, row, col, k);
    printf("\nChanged array: ");
    output_array(mas, row, col);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
