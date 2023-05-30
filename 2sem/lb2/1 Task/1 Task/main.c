#include "Header.h"

int main()
{
    Words* word = (Words*)calloc(1, sizeof(Words)); 
    if (word == NULL)
        return NULL;
    Dictionary* dictionary = (Dictionary*)calloc(1, sizeof(Dictionary));
    if (dictionary == NULL)
    {
        return NULL;
    }
    FILE* File_txt;
    FILE* Dictionary_txt;
    fopen_s(&File_txt, "File.txt", "r");
    fopen_s(&Dictionary_txt, "1Dictionary.txt", "w");
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
    if (word == NULL && dictionary == NULL)
        return NULL;
    if (word != NULL)
    {
        qsort(word, WordCount, sizeof(word[0]), compare);
    }
    if (dictionary != NULL)
    {
        dictionary = FillDictionary(word, WordCount, &DictionaryCount);
    }
    for (int i = 0; i < DictionaryCount; i++)
    {
        fprintf(Dictionary_txt, "%s %s\n", dictionary[i].DictionaryWord, dictionary[i].TranslationWord);
    }
    fclose(File_txt);
    fopen_s(&File_txt, "File.txt", "r+");
    if (File_txt == NULL)
    { 
        perror("File open error");
        exit(1);
    }
    if(dictionary != NULL)
    {
        FileCompressor(File_txt, dictionary, DictionaryCount);
    }
    fclose(File_txt);
    fclose(Dictionary_txt);
    printf("File compressed.");
    free(word);
    free(dictionary);
}

