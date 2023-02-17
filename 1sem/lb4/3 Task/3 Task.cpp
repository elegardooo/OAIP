// 3 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void manual_input(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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

void output_array(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

void rand(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 201 - 100;
        }
    }
}

void find_min(int a[][100], int n, int& min)
{
    int ihalf, zn = 0;
    min = a[0][n-1];
    if (n % 2 == 0)
        ihalf = n / 2;
    if (n % 2 != 0)
        ihalf = n / 2 + 1;
    for (int j = n-1; j >= ihalf-1; j--)
    {
        for (int i = zn; i < ihalf; i++)
        {
            if (min > a[i][j])
                min = a[i][j];
            if (min > a[(n-1) - i][j])
                min = a[(n-1) - i][j];
        }
        zn++;
    }
}

void main(void)
{
    int a[100][100], n, choose, min;
    srand(time(NULL));
    printf("Enter the N: ");
    while ((scanf_s("%d", &n) != 1) || (n<1 || n>100) || (getchar() != '\n'))
    {
        printf("Wrong input. Enter the N: ");
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
        manual_input(a, n);
        break;
    case 2:
        rand(a, n);
        break;
    }
    printf("Array:\n");
    output_array(a, n);
    find_min(a, n, min);
    printf("Minimal element in the 2 area is: %d", min);
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
