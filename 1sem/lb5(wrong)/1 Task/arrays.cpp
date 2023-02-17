#include "arrays.h"

void array_change(int* mas, int& n)
{
	for (int i = n - 1; i >= 0; i--) {
		mas[i * 2 + 1] = mas[i] * mas[i];
		mas[i * 2] = mas[i];
	}
	n = n * 2;
}

void input_n(int& n)
{
	while ((scanf_s("%d", &n) != 1) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the size of array: ");
		while (getchar() != '\n');
	}
}

int* memory_alloc(int n)
{
	int* temp = (int*)calloc(n * 2, sizeof(int));
	return temp;
}

void output_array(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(mas + i));
	}
}