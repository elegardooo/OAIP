#pragma once
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