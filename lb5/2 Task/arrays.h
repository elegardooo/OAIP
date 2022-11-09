#pragma once
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