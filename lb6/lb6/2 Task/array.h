#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void input_N(int& n);
void input_M(int& m);
int** memory(int n, int m);
void input_choose(int& choose);
void type_of_filling(int** mas, int n, int m, int choose);
void array_input(int** mas, int n, int m);
void rand(int** mas, int n, int m);
void output_array(int** mas, int n, int m);
void sort(int** mas, int n, int m);