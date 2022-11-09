// 2 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void manual_input(int a[][100], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
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
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

void rand(int a[][100], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            a[i][j] = rand() % 201 - 100;
        }
    }
}

void check(int a[][100], int col, int row, int& number)
{
    number = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] < 0)
            {
                number = a[i][j];
                int numberi = i;
                int numberj = j;
                printf("Number position: [%d][%d]\n", (numberi + 1), (numberj + 1));
                for (int i = 0; i < col; i++)
                {
                    a[i][j] = a[i][j] / 2;
                }
                goto label;
            }
        }
    }
label:;
}
void main(void)
{
    int a[100][100], col, row, choose, number;
    srand(time(NULL));
    printf("Enter amount of columns in the array: ");
    while ((scanf_s("%d", &col) != 1) || (col < 1 || col > 100) || (getchar() != '\n'))
    {
        printf("Wrong input. Enter amount of columns in the array: ");
        while (getchar() != '\n');
    }
    printf("Enter amount of rows in the array: ");
    while ((scanf_s("%d", &row) != 1) || (row < 1 || row > 100) || (getchar() != '\n'))
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
    printf("Array:\n");
    output_array(a, col, row);
    check(a, col, row, number);
    if (number == 0)
        printf("There is no negative element.");
    else
    {
    printf("Changed array:\n");
    output_array(a, col, row);
    }
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
