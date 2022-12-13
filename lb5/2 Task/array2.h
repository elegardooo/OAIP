#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void input_rows(int& row);
void input_col(int& col);
void input_k(int& k);
void input_choose(int& choose);
void array_input(int** mas, int row, int col);
void type_of_filling(int** mas, int row, int col, int choose);
int** memory(int row, int col);
void rand(int** mas, int row, int col);
void output_array(int** mas, int row, int col);
void array_change(int** mas, int row, int col, int k);
int** memory_realloc(int** mas, int row, int col);
void free_mas(int** mas, int row);