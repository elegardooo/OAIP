#include "array3.h"

void main(void)
{
    int** mas, row, col, choose;
    srand(time(NULL));
    printf("Enter the number of rows: ");
    input_rows(row);
    printf("Enter the number of columns: ");
    input_columns(col);
    mas = memory(row, col);
    printf("1.User filling\n2.Random filling\n");
    printf("Choose the type of array filling: ");
    input_choose(choose);
    type_of_filling(mas, row, col, choose);
    printf("Array: ");
    output_array(mas, row, col);
    array_change(mas, row, col);
    memory_realloc(mas, row, col);
    printf("\nChanged array: ");
    output_array(mas, row, col);
    free_mas(mas, row);
}