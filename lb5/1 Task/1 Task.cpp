// 1 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>

int* memory_alloc(int n)
{
	int* temp = (int*)calloc(n, sizeof(int));
	return temp;
}

void output_array(int* mas, int n)
{
	printf("Array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(mas + i));
	}
}

void array_change(int* mas, int& n)
{
	int per;
	per = 1;
	realloc(mas, sizeof(int) * (n));
	for (int i = n * 2; i > per;)
	{
		n++;
		realloc(mas, sizeof(int) * (n));
		for (int i = n - 1; i > per; i--)
		{
			mas[i + 1] = mas[i];
		}
		mas[per + 1] = mas[per] * mas[per];
		per = per + 2;
	}

}

void main(void)
{
	int *mas, n;
	printf("Enter the size of array: ");
	while ((scanf_s("%d", &n) != 1) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter the size of array: ");
		while (getchar() != '\n');
	}
	mas = memory_alloc(n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter the [%d] element of array: ", (i + 1));
		while ((scanf_s("%d", (mas + i)) != 1) || (getchar() != '\n'))
		{
			printf("Wrong input. Enter the [%d] element of array: ", i);
			while (getchar() != '\n');
		}
	}
	output_array(mas, n);
	array_change(mas, n);
	output_array(mas, n);
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
