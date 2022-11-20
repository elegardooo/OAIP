#include "array2.h"

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

void input_choose(int& choose)
{
    while ((scanf_s("%d", &choose) != 1) || (choose != 1 && choose != 2) || (getchar() != '\n'))
    {
        printf("Wrong input.\nChoose the type of array filling: ");
        while (getchar() != '\n');
    }
}

void array_input(int** mas, int row, int col)
{
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
}

void type_of_filling(int** mas, int row, int col, int choose)
{
    switch (choose)
    {
    case 1:
        array_input(mas, row, col);
        break;
    case 2:
        rand(mas, row, col);
        break;
    }
}

int** memory(int row, int col)
{
    int** mas;
    mas = (int**)calloc(row, sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        mas[i] = (int*)calloc(col, sizeof(int));
    }
    return mas;
}

void rand(int** mas, int row, int col)
{
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

void array_change(int** mas, int row, int col, int k)
{
    int zn, n, p = 0;
    for (int i = 0; i < row; i++)
    {
        n = 0;
        p = 0;
        for (int j = 0; j < col; j++)
        {
            if ((mas[i][j]) == -1)
                j = col;
            else
                n++;
        }
        if (n % k == 0)
            p = 1;
        for (int j = k; j < n;)
        {
            zn = j;
            while (j < n)
            {
                if ((mas[i][j]) == -1)
                    j = n;
                else
                {
                    mas[i][j - 1] = mas[i][j];
                    j++;
                }
            }
            mas[i][n - 1] = -1;
            j = zn + k - 1;
            n--;
        }
        if (p == 1)
            mas[i][n - 1] = -1;
    }
}

int** memory_realloc(int** mas, int row, int col)
{
    int n;
    for (int i = 0; i < row; i++)
    {
        n = 0;
        for (int j = 0; j < col; j++)
        {
            if (mas[i][j] == -1)
                j = col;
            else
                n++;
        }
        mas[i] = (int*)realloc(mas[i], n * sizeof(int));
    }
    return mas;
}