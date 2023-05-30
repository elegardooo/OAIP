#include "Header.h"

int compare(const void* x1, const void* x2)
{
    const Words* k = (const Words*)x1;
    const Words* m = (const Words*)x2;
    int s = ((k->size) - (m->size));
    return s;
}

int Is_Word(char letter)
{
    if (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z')
        return 1;
    return 0;
}

int FindWordIndex(const char* name, const Words* words, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(words[i].wordName, name))
            return i;
    }
    return -7;
}

void Marks(const char* str, int i, FILE* file)
{
    switch (str[i])
    {
    case '.':
        fprintf(file, ".");
        break;
    case ',':
        fprintf(file, ",");
        break;
    case ' ':
        fprintf(file, " ");
        break;
    case '-':
        fprintf(file, "-");
        break;
    case ':':
        fprintf(file, ":");
        break;
    case ';':
        fprintf(file, ";");
        break;
    default:
        break;
    }
}

void add_words(int* WordNum, int *WordCount, Words* *words, char* word)
{
    word[*WordNum] = '\0';
    //printf("%d\n", *WordNum);
    *WordNum = FindWordIndex(word, *words, *WordCount);
    if (*WordNum == -7)
    {
        int WordIndex = *WordCount;
        //printf("%d", WordIndex);
        strcpy_s((*words)[WordIndex].wordName, WORD_MAX_LENGTH, word);
        (*words)[WordIndex].count = 1;
        (*words)[WordIndex].size = strlen(word);
        (*words)[WordIndex].Swapped = 0;
        (*words)[WordIndex].lettersnum = strlen(word);
        //printf("%d\n", words[WordIndex].lettersnum);
        WordIndex = WordIndex + 1;
        *WordCount = (*WordCount) + 1;
        *words = (Words*)realloc(*words, (WordIndex + 1) * sizeof(Words));
    }
    else
    {
        (*words)[*WordNum].count = (*words)[*WordNum].count + 1;
        (*words)[*WordNum].lettersnum += strlen(word);
    }
    *WordNum = 0;
}

Words* Words_For_Dictionary(FILE* File_txt, int* WordCount)
{
    Words* words = (Words*)calloc(1, sizeof(Words));
    if (!words)
        exit(1);
    char* word = (char*)calloc(1, sizeof(char));
    if (!word)
        exit(1);
    char* str;
    str = (char*)calloc(4096, sizeof(char));
    int WordNum = 0;
    while (fgets(str, 4096, File_txt) != NULL)
    {
        for (int i = 0; i <= strlen(str); i++)
        {
            if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n' || str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == ':')
            {
                add_words(&WordNum, WordCount, &words, word);
                /*word[WordNum] = '\0';
                WordNum = FindWordIndex(word, words, *WordCount);
                if (WordNum == -7)
                {
                    int WordIndex = *WordCount;
                    strcpy_s(words[WordIndex].wordName, WORD_MAX_LENGTH, word);
                    words[WordIndex].count = 1;
                    words[WordIndex].size = strlen(word);
                    words[WordIndex].Swapped = 0;
                    words[WordIndex].lettersnum = strlen(word);
                    WordIndex = WordIndex + 1;
                    *WordCount = (*WordCount) + 1;
                    words = (Words*)realloc(words, (WordIndex + 1) * sizeof(Words));
                }
                else
                {
                    words[WordNum].count = words[WordNum].count + 1;
                    words[WordNum].lettersnum += strlen(word);
                }
                WordNum = 0;*/
            }
            else
            {
                word[WordNum] = str[i];
                word = (char*)realloc(word, (WordNum + 2) * sizeof(char));
                WordNum++;
            }
        }
    }
    free(str);
    free(word);
    return words;
}

Dictionary* FillDictionary(Words* word, int WordCount, int* DictionaryCount)
{
    Dictionary* dictionary = (Dictionary*)calloc(2048, sizeof(Dictionary));
    for (int i = 0; i < WordCount; i++)
    {
        for (int j = 1; j < WordCount && word[i].Swapped != 1; j++)
        {
            if ((word[j].Swapped != 1) && (word[i].size != 0 && word[i].count > 1 && (word[i].lettersnum + word[j].lettersnum) > ((word[i].size * word[j].count) + (word[j].size * word[i].count))))
            {
                int DictionaryIndex = *DictionaryCount;
                strcpy_s(dictionary[DictionaryIndex].DictionaryWord, WORD_MAX_LENGTH, word[i].wordName);
                strcpy_s(dictionary[DictionaryIndex].TranslationWord, WORD_MAX_LENGTH, word[j].wordName);
                *DictionaryCount = (*DictionaryCount) + 1;
                DictionaryIndex++;
                dictionary = (Dictionary*)realloc(dictionary, (DictionaryIndex + 2) * sizeof(Dictionary));
                word[i].Swapped = 1; word[j].Swapped = 1;
                break;
            }
        }
    }
    return dictionary;
}

void FileCompressor(FILE* File_txt, Dictionary* dictionary, int DictionaryCount)
{
    FILE* CompressedFile_txt;
    char* str, * word;
    str = (char*)calloc(4096, sizeof(char));
    word = (char*)calloc(1, sizeof(char));
    int WordNum = 0, DictionaryIndex = 0;
    fopen_s(&CompressedFile_txt, "CompressedFile.txt", "w");
    if (CompressedFile_txt == NULL)
    {
        perror("File open error");
        exit(1);
    }
    while (fgets(str, 4096, File_txt) != NULL)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n' || str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == ':')
            {
                word[WordNum] = '\0';
                for (DictionaryIndex = 0; DictionaryIndex < DictionaryCount; DictionaryIndex++)
                {
                    if (strcmp(dictionary[DictionaryIndex].DictionaryWord, word) == 0)
                    {
                        fprintf(CompressedFile_txt, "%s", dictionary[DictionaryIndex].TranslationWord);
                        Marks(str, i, CompressedFile_txt);
                        break;
                    }
                    else
                        if (strcmp(dictionary[DictionaryIndex].TranslationWord, word) == 0)
                        {
                            fprintf(CompressedFile_txt, "%s", dictionary[DictionaryIndex].DictionaryWord);
                            Marks(str, i, CompressedFile_txt);
                            break;
                        }
                }
                if (strcmp(dictionary[DictionaryIndex].TranslationWord, word) != 0 && strcmp(dictionary[DictionaryIndex].DictionaryWord, word) != 0)
                {
                    fprintf(CompressedFile_txt, "%s", word);
                    Marks(str, i, CompressedFile_txt);
                }
                WordNum = 0;
            }
            else
            {
                word[WordNum] = str[i];
                word = (char*)realloc(word, (WordNum + 2) * sizeof(char));
                WordNum++;
            }
        }
        fprintf(CompressedFile_txt, "\n");
    }
    fclose(CompressedFile_txt);
    free(word);
    free(str);
}