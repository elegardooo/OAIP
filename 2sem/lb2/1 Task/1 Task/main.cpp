#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


int main()
{
    Words *word=(Words*)calloc(1, sizeof(Words)); Dictionary *dictionary=(Dictionary*)calloc(1, sizeof(Dictionary));
    FILE* File_txt, *Dictionary_txt;
    File_txt = fopen("File.txt", "r");
    Dictionary_txt = fopen("1Dictionary.txt", "w");
    //int ErrorFile = fopen_s(&File_txt, "File.txt", "r+"), ErrorDictionary = fopen_s(&Dictionary_txt, "1Dictionary.txt", "w");
    int WordCount = 0, DictionaryCount = 0;
    if (File_txt == NULL)
    {
        perror("File open error");
        exit(1);
    }
    if (Dictionary_txt == NULL)
    {
        perror("File open error");
        exit(1);
    }
    word = Words_For_Dictionary(File_txt, WordCount);
    qsort(word, WordCount, sizeof(word[0]), compare);
    dictionary = FillDictionary(word, WordCount, DictionaryCount);
    for (int i = 0; i < DictionaryCount; i++)
    {
        fprintf(Dictionary_txt, "%s %s\n", dictionary[i].DictionaryWord, dictionary[i].TranslationWord);
    }
    //printf("%d     ", WordCount);
    //printf("%d     ", DictionaryCount);
    //printf("%d        ", word[733].size);
    //printf("1");
    //printf("%d", word[733].pos);
    fclose(File_txt);
    File_txt = fopen("File.txt", "r+");
    if (File_txt == NULL)
    {
        perror("File open error");
        exit(1);
    }
    FileCompressor(File_txt, dictionary, DictionaryCount);
    fclose(File_txt);
    fclose(Dictionary_txt);
    printf("File compressed.");
    free(word);
    free(dictionary);
}


