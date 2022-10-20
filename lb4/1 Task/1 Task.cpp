// 1 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void manual_input(int a[][100], int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("Enter the [%d][%d] element of array: ", (i + 1), (j + 1));
            while ((scanf_s("%d", &a[i][j]) != 1) || (getchar() != '\n'))
            {
                printf("Wrong input. Enter the [%d][%d] element of array: ", (i + 1), (j + 1));
                while (getchar() != '\n');
            }
        }
    }
}

void output_array(int a[][100], int col, int row)
{
    printf("Array:\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void rand(int a[][100], int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            a[i][j] = rand() % 201 - 100;
        }
    }
}

void charact(int a[][100], int sum[], int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < row; j++)
        {
            if ((a[i][j] % 2 == 0) && (a[i][j] > 0))
                sum[i] = sum[i] + a[i][j];
        }
    }
}

void output_charact(int sum[], int col, int row)
{
    printf("Charact array:\n");
    for (int i = 0; i < col; i++)
    {
        printf("%d ", sum[i]);
        printf("\n");
    }
}
void main(void)
{
    int a[100][100], sum[100], col, row, choose;
    srand(time(NULL));
    printf("Enter amount of columns in the array: ");
    while ((scanf_s("%d", &col) != 1) || (getchar() != '\n'))
    {
        printf("Wrong input. Enter amount of columns in the array: ");
        while (getchar() != '\n');
    }
    printf("Enter amount of rows in the array: ");
    while ((scanf_s("%d", &row) != 1) || (getchar() != '\n'))
    {
        printf("Wrong input. Enter amount of rows in the array: ");
        while (getchar() != '\n');
    }
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
        manual_input(a, col, row);
        break;
    case 2:
        rand(a, col, row);
        break;
    }
    charact(a, sum, col, row);
    output_array(a, col, row);
    output_charact(sum, col, row);
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
