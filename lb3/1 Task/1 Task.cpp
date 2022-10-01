// 1 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main()
{
	int a[100], sum=0, n, choose, number, max;
	printf("Enter the size of array: ");
	scanf_s("%d", &n);
	srand(time(NULL));
	while (n < 1 || n>100)
	{
		printf("Wrong input.\nEnter the size of array: ");
		scanf_s("%d", &n);
	}
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
			printf("Element number %d: ", (i + 1));
			scanf_s("%d", &a[i]);
		}
		break;
	case 2:
		for (int i = 0; i < n; i++)
		{
			a[i] = rand()%61-30;
			printf("Element number %d: %d\n", (i + 1),a[i]);
		}
		break;
	}
	printf("Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	max = a[0];
	number = 1;
	for (int i=1;i<n; i++)
		if (abs(a[i])>abs(max))
		{
			max = a[i];
			number = i+1;
		}
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
		{
			while (i < n)
			{
				sum = sum + a[i];
				i++;
			}
			break;
		}
	printf("\nNumber of the maximum modulo element of the array is: %d\nThe sum of the array elements after the first positive element: %d",number,sum);
	return 0;
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
