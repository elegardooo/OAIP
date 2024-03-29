﻿// 2 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "arrays.h"

void input_rows(int& row)
{

    while ((scanf_s("%d", &row)) != 1 || (getchar() != '\n'))
    {
        printf("Wrong input. Enter the number of rows: ");
        while (getchar() != '\n');
    }
}

void input_col(int& col)
{
    while ((scanf_s("%d", &col) != 1) || (getchar() != '\n'))
    {
        printf("Wrong input. Enther the maximum number of elements in the row: ");
        while (getchar() != '\n');
    }
}

void input_k(int& k)
{
    while ((scanf_s("%d", &k)) != 1 || (k < 1) ||
        (getchar() != '\n'))
    {
        printf("Wrong input. Enter the k: ");
        while (getchar() != '\n');
    }
}

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

void rand(int** mas, int row, int col)
{
    int ncol;
    for (int i = 0; i < row; i++)
    {
        ncol = rand() % col + 1;
        for (int j = 0; j < ncol; j++)
        {
            mas[i][j] = rand() % 201 - 100;
        }
        if (ncol < col)
            mas[i][ncol] = -1;
    }
}

void main(void)
{
    int **mas, row, col, k, choose;
    srand(time(NULL));
    printf("Enter the number of rows: ");
    input_rows(row);
    printf("Enter the maximum number of elements in the row: ");
    input_col(col);
    printf("Enter the k: ");
    input_k(k);
    mas = memory(row, col);
    printf("1.User filling\n2.Random filling\n");
    printf("Choose the type of array filling: ");
    while ((scanf_s("%d", &choose) != 1) || (choose != 1 && choose != 2) || (getchar() != '\n'))
    {
        printf("Wrong input.\nChoose the type of array filling: ");
        while (getchar() != '\n');
    }
    switch (choose)
    {
    case 1:
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
        break;
    case 2:
        rand(mas, row, col);
        break;
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
