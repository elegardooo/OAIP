#include "Header.h"

int main()
{
    Words* word = (Words*)calloc(1, sizeof(Words)); Dictionary* dictionary = (Dictionary*)calloc(1, sizeof(Dictionary));
    FILE* File_txt, * Dictionary_txt;
    File_txt = fopen("File.txt", "r");
    Dictionary_txt = fopen("1Dictionary.txt", "w");
    int WordCount = 0;
    int DictionaryCount = 0;
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
    word = Words_For_Dictionary(File_txt, &WordCount);
    qsort(word, WordCount, sizeof(word[0]), compare);
    dictionary = FillDictionary(word, WordCount, &DictionaryCount);
    for (int i = 0; i < DictionaryCount; i++)
    {
        fprintf(Dictionary_txt, "%s %s\n", dictionary[i].DictionaryWord, dictionary[i].TranslationWord);
    }
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

