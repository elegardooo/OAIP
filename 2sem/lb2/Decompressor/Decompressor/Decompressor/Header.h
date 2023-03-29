#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_MAX_LENGTH 50


typedef struct Dictionary
{
	char DictionaryWord[WORD_MAX_LENGTH];
	char TranslationWord[WORD_MAX_LENGTH];
} Dictionary;

void Marks(char* str, int i, FILE* file);
Dictionary* Fill_Structure(FILE* Dictionary_txt, int& DictianoryCount);
void Decompressing(FILE* File_txt, Dictionary* dictionary, int DictionaryCount);
