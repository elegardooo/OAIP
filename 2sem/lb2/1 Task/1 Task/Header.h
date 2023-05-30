#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_MAX_LENGTH 50

typedef struct Words
{
    char wordName[WORD_MAX_LENGTH];
    int count;
    int size;
    int lettersnum;
    int Swapped;
} Words;

typedef struct Dictionary
{
    char DictionaryWord[WORD_MAX_LENGTH];
    char TranslationWord[WORD_MAX_LENGTH];
} Dictionary;

typedef struct Dictionary_Nums
{
    int WordNum;
    int DictionaryIndex;
} Dictionary_Nums;

int compare(const void* x1, const void* x2);
int Is_Word(char letter);
int FindWordIndex(char* name, Words* words, int n);
void Marks(char* str, int i, FILE* file);
void add_words(int* WordNum, int* WordCount, Words** words, char* word);
Words* Words_For_Dictionary(FILE* File_txt, int *WordCount);
Dictionary* FillDictionary(Words* word, int WordCount, int *DictionaryCount);
void add_dictionary(Dictionary_Nums* Numbers, int DictionaryCount, Dictionary** dictionary, char* word, FILE* CompressedFile_txt, char* str, int i);
void FileCompressor(FILE* File_txt, Dictionary* dictionary, int DictionaryCount);

