// 3 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main()
{
	int a[100], b[100], c[100], choose, n = 30, zn=0;
	srand(time(NULL));
	zn = 0;
	printf("1.User filling\n2.Random filling\n");
	printf("Choose the type of array filling: ");
	scanf_s("%d", &choose);
	while (choose != 1 && choose != 2)
	{
		printf("Wrong input.\nChoose the type of array filling: ");
		scanf_s("%d", &choose);
	}
	switch (choose)
	{
	case 1:
		for (int i = 0; i < n; i++)
		{
			printf("1 array element number %d: ", (i + 1));
			scanf_s("%d", &a[i]);
			while (a[i] < 0 || a[i]>9)
			{
				printf("Wrong input.\n1 array element number %d: ", (i + 1));
				scanf_s("%d", &a[i]);
			}
		}
		for (int i =0; i<n; i++)
		{
			printf("2 array element number %d: ", (i + 1));
			scanf_s("%d", &b[i]);
			while (b[i] < 0 || b[i]>9)
			{
				printf("Wrong input.\n2 array element number %d: ", (i + 1));
				scanf_s("%d", &b[i]);
			}
		}
		break;
	case 2:
		a[0] = rand() % 9 + 1;
		b[0] = rand() % 9 + 1;
		printf("1 array element number 1: %d	2 array element number 1: %d\n", a[0], b[0]);
		for (int i = 1; i < n; i++)
		{
			a[i] = rand() % 10;
			b[i] = rand() % 10;
			printf("1 array element number %d: %d	2 array element number %d: %d\n", (i + 1), a[i], (i+1), b[i]);
		}
		break;
	}
	printf("Number 1: ");
	for (int i = 0; i < n; i++)
		printf("%d", a[i]);
	printf("\nNumber 2: ");
	for (int i = 0; i < n; i++)
		printf("%d", b[i]);
	for (int i = 0; i < n; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < b[i] && a[i]!=b[i])
		{
		zn = 1;
		break;
		}
		break;
	}
	if (zn == 0)
	{
		for (int i = n ; i > 0; i--)
		{
			c[i] = c[i] + a[i] - b[i];
			if (c[i] < 0)
			{
				c[i] = c[i] + 10;
				c[i - 1] = -1;;
			}
		}
		c[0] = c[0] + a[0] - b[0];
		c[n - 1]++;
	}
	else
	{
		for (int i = n ; i > 0; i--)
		{
			c[i] = c[i] + b[i] - a[i];
			if (c[i] < 0)
			{
				c[i] = c[i] + 10;
				c[i - 1] = -1;;
			}
		}
		c[0] = (c[0] + b[0] - a[0])*(-1);
		c[n-1]++;
	}
	printf("\nEqual: ");
		for (int i = 0; i < n; i++)
			printf("%d", c[i]);
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
