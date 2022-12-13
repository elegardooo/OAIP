#include "array.h"

void input_size(int& n)
{
	while (((scanf_s("%d", &n)) != 1) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the size of array: ");
		while (getchar() != '\n');
	}
}

int* memory(int n)
{
	int* temp;
	temp = (int*)calloc(n, sizeof(int));
	return temp;
}

void input_choose(int& choose)
{
	while (((scanf_s("%d", &choose)) != 1) || ((choose != 1) && (choose != 2)) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the type of array filling: ");
		while (getchar() != '\n');
	}
}

void type_of_filling(int* mas, int n, int choose)
{
	switch (choose)
	{
	case 1:
		array_input(mas, n);
		break;
	case 2:
		rand(mas, n);
		break;
	}
}

void array_input(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter the %d element of array: ", (i + 1));
		while (((scanf_s("%d", &mas[i])) != 1) || (getchar() != '\n'))
		{
			printf("Wrong input. Enter the %d element of array: ", (i + 1));
			while (getchar() != '\n');
		}
	}
}

void rand(int* mas, int n)
{
	int d = 0;
	for (int i = n; i > 0; i--)
	{
			mas[d] = i-n;
			d++;
	}
	/*for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 201 - 100;
	}*/
}

void output_array(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", mas[i]);
	}
}

void sort(int* mas, int n)
{
	int i1, temp, flg;
	/*for (int i = 0; i < n; i++)
	{
		i1 = i;
		if (mas[i1]<0)
		for (int j = i + 1; j < n; j++)
			if ((mas[i1] > mas[j]) && (mas[j] < 0))
			i1 = j;
		temp = mas[i];
		mas[i] = mas[i1];
		mas[i1] = temp;
	}*/
	
	for(int i=0; i<n;i++)
		for (int j = 0; j < n - 1; j++)
		{
			if(mas[j]<0)
			if ((mas[j] > mas[j + 1]) && (mas[j+1]<0))
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
}

