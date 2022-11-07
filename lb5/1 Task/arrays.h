#pragma once
void array_change(int* mas, int& n)
{
	for (int i = n - 1; i >= 0; i--) {
		mas[i * 2 + 1] = mas[i] * mas[i];
		mas[i * 2] = mas[i];
	}
	n = n * 2;
}