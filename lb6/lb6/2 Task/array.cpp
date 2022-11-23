#include "array.h"

void input_N(int& n)
{
	while (((scanf_s("%d", &n)) != 1) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the N: ");
		while (getchar() != '\n');
	}
}

void input_M(int& m)
{
	while (((scanf_s("%d", &m)) != 1) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the M: ");
		while (getchar() != '\n');
	}
}

int** memory(int n, int m)
{
	int** mas;
	mas = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		mas[i] = (int*)calloc(m, sizeof(int));
	}
	return mas;
}

void input_choose(int& choose)
{
	while (((scanf_s("%d", &choose)) != 1) || ((choose != 1) && (choose != 2)) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the type of array filling: ");
		while (getchar() != '\n');
	}
}

void type_of_filling(int** mas, int n, int m, int choose)
{
	switch (choose)
	{
	case 1:
		array_input(mas, n, m);
		break;
	case 2:
		rand(mas, n, m);
		break;
	}
}

void array_input(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < m; j++)
		{
			printf("Enter the [%d][%d] element of array: ", (i + 1), (j + 1));
			while (((scanf_s("%d", &mas[i][j])) != 1) || (getchar() != '\n'))
			{
				printf("Wrong input. Enter the [%d][%d] element of array: ", (i + 1), (j + 1));
				while (getchar() != '\n');
			}
		}
	}
}

void rand(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 201 - 100;
		}
}

void output_array(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < m; j++)
		{
			printf("%4d ", mas[i][j]);
		}
	}
}

void sort(int** mas, int n, int m)
{
	int sum1, sum2, s, flg;
	for(int gap=n/2; gap>0; gap/=2)
		do {
			flg = 0;
			for (int d = 0, h = gap; h < n; d++, h++)
			{
				sum1 = 0; sum2 = 0;
				for (int j = 1; j < m; j=j+2)
				{
					sum1 = sum1 + mas[d][j];
					sum2 = sum2 + mas[h][j];
				}
				if (sum1 < sum2)
				{
					for (int j = 0; j < m; j++)
					{
						s = mas[d][j];
						mas[d][j] = mas[h][j];
						mas[h][j] = s;
					}
				}
			}
		} while (flg);
}
