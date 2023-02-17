#pragma once
#include <stdio.h>
#include <stdlib.h>

int str_len(char* s);
char** memory(int argc);
void input_str(char** str, int argc, char** argv);
int longest_word_len(char* str);
void output_str(char** str, int argc);
void insert_sort(int argc, char** str);
void freee(char** string, int argc, char** argv);