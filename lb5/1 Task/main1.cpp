#include "array1.h"

void main(void)
{
	int* mas, n;
	printf("Enter the size of array: ");
	input_n(n);
	mas = memory_alloc(n);
	input_array(mas, n);
	printf("Array: ");
	output_array(mas, n);
	array_change(mas, n);
	printf("\nChanged array: ");
	output_array(mas, n);
}