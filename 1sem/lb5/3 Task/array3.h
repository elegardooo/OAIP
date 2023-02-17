#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

void input_rows(int& row);
void input_columns(int& col);
void input_choose(int& choose);
void type_of_filling(int** mas, int row, int col, int choose);
void array_input(int** mas, int row, int col);
void rand(int** mas, int row, int col);
int** memory(int row, int col);
void output_array(int** mas, int row, int col);
void array_change(int** mas, int row, int& col);
int** memory_realloc(int** mas, int row, int col);
void free_mas(int** mas, int row);