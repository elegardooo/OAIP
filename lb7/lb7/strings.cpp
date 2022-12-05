#include "strings.h"

void input_nums(int* x, int min, int max)
{
	while ((scanf_s("%d", &(*x)) != 1) || ((*x) < min) || ((*x) > max) || (getchar() != '\n'))
	{
		printf("Wrong input. Enter number between %d and %d: ", min, max);
		while (getchar() != '\n');
	}
}

char* get_str(char* s, int k)
{
	int c, i = 0;
	while (--k > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;		//Enter or Ctrl + Z
	s[i] = '\0';
	return s;
}

char* get_word(char* s, int k)
{
	int c, i = 0;
	while (--k > 0 && (c = getchar()) != EOF && c != '\n' && c != ' ')
		s[i++] = c;		//Enter or Ctrl + Z
	s[i] = '\0';
	return s;
}

int str_len(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

int str_word_compare(char* s, char* s0, int len0)
{
	int count = 0, ilen = 0, k = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] - s0[k] != 1) && (s[i] != ' '))
		{
			ilen++;
			if ((ilen == len0) && ((s[i + 1] == '\0') || (s[i + 1] == ' ')))
			{
				count++;
				ilen = 0;
				k = 0;
			}
			k++;
		}
		else
		{
			ilen = 0;
			k = 0;
		}
	}
	return count;
}

int str_str_compare(char* s, char* s0, int len0)
{
	int count = 0, ilen = 0, k = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] - s0[k] != 1)
		{
			ilen++;
			if (ilen == len0)
			{
				count=1;
				ilen = 0;
				k = 0;
			}
			k++;
		}
		else
		{
			ilen = 0;
			k = 0;
		}
	}
	return count;
}

void* task1(void)
{
	int n = 255, len0;
	char* s = (char*)malloc(n * sizeof(char)), *s0 = (char*)malloc(n * sizeof(char));
	printf("Enter the string:\n");
	get_str(s, n);
	printf("Enter the word:\n");
	get_word(s0, n);
	len0 = str_len(s0);
	int cnt = str_word_compare(s, s0, len0);
	printf("This word meets in the string %d times", cnt);
	free(s);
	free(s0);
	return 0;
}

void output(int ToF)
{
	if (ToF == 1)
		printf("true");
	else
		printf("false");
}

void* task2(void)
{
	int n = 255, len, len0;
	char* s = (char*)malloc(n * sizeof(char)), * s0 = (char*)malloc(n * sizeof(char));
	printf("Enter the first string:\n");
	get_str(s, n);
	printf("Enter the second string:\n");
	get_str(s0, n);
	len0 = str_len(s0);
	int ToF = str_str_compare(s, s0, len0);
	output(ToF);
	free(s);
	free(s0);
	return 0;
}

void choose_task(void)
{
	int task = 0, YoN = 0;
	printf("Choose the task(1 or 2): ");
	input_nums(&task, 1, 2);
	switch (task)
	{
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
	}
	//printf("%d", task);
	//return 0;
}
