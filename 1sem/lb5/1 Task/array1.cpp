#include "array1.h"

void input_array(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter the [%d] element of array: ", (i + 1));
		while ((scanf_s("%d", (mas + i)) != 1) || (getchar() != '\n'))
		{
			printf("Wrong input. Enter the [%d] element of array: ", i);
			while (getchar() != '\n');
		}
	}
}

void array_change(int* mas, int& n)
{
	for (int i = n - 1; i >= 0; i--) {
		mas[i * 2 + 1] = mas[i] * mas[i];
		mas[i * 2] = mas[i];
	}
	n = n * 2;
}

void output_array(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(mas + i));
	}
}

int* memory_alloc(int n)
{
	int* temp = (int*)calloc(n * 2, sizeof(int));
	return temp;
}

void input_n(int& n)
{
	while ((scanf_s("%d", &n) != 1) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the size of array: ");
		while (getchar() != '\n');
	}
}
