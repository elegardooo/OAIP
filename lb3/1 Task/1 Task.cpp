

#include <stdio.h>

int main()
{
	int a[100], n,choose;
	printf("Enter the size of array: ");
	scanf_s("%d", &n);
	printf("1.User filling\n2.Random filling");
	printf("Choose the type of array filling: ");
	scanf_s("%d", &choose);
	while (choose != 1 || choose != 2)
	{
		printf("Wrong input.\nChoose the type of array filling: ");
		scanf_s("%d", &choose);
	}
	switch (choose)
	{
	case 1: 
		for (int i = 0; i < n; i++)
		{
			printf("%d elemt of array: ", (i + 1);
			scanf_s("%d", &a[i]);
		}
		break;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}