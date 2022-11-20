#include "array3.h"

void input_rows(int& row)
{

    while ((scanf_s("%d", &row)) != 1 || (getchar() != '\n'))
    {
        printf("Wrong input. Enter the number of rows: ");
        while (getchar() != '\n');
    }
}

void input_columns(int& col)
{
    while ((scanf_s("%d", &col)) != 1 || (getchar() != '\n'))
    {
        printf("Wrong input. Enter the number of columns: ");
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

void array_input(int** mas, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the [%d][%d] element of array: ", (i + 1), (j + 1));
            while ((scanf_s("%d", &mas[i][j]) != 1) || (getchar() != '\n'))
            {
                printf("Wrong input. Enter the [%d][%d] element of array: ", (i + 1), (j + 1));
                while (getchar() != '\n');
            }
        }
    }
}

void rand(int** mas, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mas[i][j] = rand() % 201 - 100;
        }
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

void output_array(int** mas, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printf("\n");
        for (int j = 0; j < col; j++)
        {
                printf("%4d ", (mas[i][j]));
        }
    }
}

void array_change(int** mas, int row, int& col)
{
    int p;
    for (int j = 0; j < col; j++)
    {
        p = 0;
        for (int i = 0; i < row; i++)
        {
            if (mas[i][j] < 0)
                p++;
        }
        if (p == row)
        {
            for (int i = 0; i < row; i++)
            {
                for (int c = j; c < col - 1; c++)
                {
                    mas[i][c] = mas[i][c + 1];
                }
            }
            col--;
            j--;
        }
    }
}

int** memory_realloc(int** mas, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        mas[i] = (int*)realloc(mas[i], col * sizeof(int));
    }
    return mas;
}