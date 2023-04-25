#include "Header.h"

int compare(const void* x1, const void* x2)   // ������� ��������� ��������� �������
{
    const Words* k = (const Words*)x1;
    const Words* m = (const Words*)x2;
    int s = ((k->size) - (m->size));              // ���� ��������� ��������� ����� 0, �� ����� �����, < 0: x1 < x2; > 0: x1 > x2
    return s;
}

int Is_Word(char letter)
{
    if (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z')
        return 1;
    return 0;
}

int FindWordIndex(char* name, Words* words, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(words[i].wordName, name))
            return i;
    }
    return -7;
}

void Marks(char* str, int i, FILE* file)
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
    case ':':
        fprintf(file, ":");
        break;
    case ';':
        fprintf(file, ";");
        break;
    }
}


Words* Words_For_Dictionary(FILE* File_txt, int& WordCount)
{
    Words* words = (Words*)calloc(1, sizeof(Words));
    char* word = (char*)calloc(1, sizeof(char));
    char* str;
    str = (char*)calloc(4096, sizeof(char));
    int WordNum = 0;
    while (fgets(str, 4096, File_txt) != NULL)
    {
        for (int i = 0; i <= strlen(str); i++)
        {
            if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n' || str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == ':')
            {
                word[WordNum] = '\0';
                WordNum = FindWordIndex(word, words, WordCount);
                if (WordNum == -7)
                {
                    int WordIndex = WordCount;
                    strcpy(words[WordIndex].wordName, word);
                    words[WordIndex].count = 1;
                    words[WordIndex].size = strlen(word);
                    words[WordIndex].Swapped = 0;
                    words[WordIndex].lettersnum = strlen(word);
                    WordIndex = WordIndex + 1;
                    WordCount = WordCount + 1;
                    words = (Words*)realloc(words, (WordIndex + 1) * sizeof(Words));
                    //printf("%s", word);
                    //printf("%d", words[2].size);
                }
                else
                {
                    //printf("%s", word);
                    words[WordNum].count = words[WordNum].count + 1;
                    words[WordNum].lettersnum += strlen(word);
                }
                WordNum = 0;
                //printf("%d", WordCount);
            }
            else
            {
                word[WordNum] = str[i];
                word = (char*)realloc(word, (WordNum + 2) * sizeof(char));
                WordNum++;
                //printf("%d", WordNum);
            }
            //printf("%d", words[0].pos);
            //printf("%d", WordNum);
            //printf("%c", str[i]);
            //printf(" %d ", WordNum);
        }
    }
    //printf("%d", WordCount);
    /*for (int i = 0; i < WordCount; i++)
    {
        printf("  %d  ", words[i].count);
    }*/
    free(str);
    return words;
}

Dictionary* FillDictionary(Words* word, int WordCount, int& DictionaryCount)
{
    Dictionary* dictionary = (Dictionary*)calloc(2048, sizeof(Dictionary));
    for (int i = 0; i < WordCount; i++)
    {
        if (word[i].Swapped != 1) //continue;

            for (int j = 1; j < WordCount; j++)
            {
                if (word[j].Swapped != 1) //continue;

                    if (word[i].size != 0 && word[i].count > 1 && (word[i].lettersnum + word[j].lettersnum) > ((word[i].size * word[j].count) + (word[j].size * word[i].count)))
                    {
                        int DictionaryIndex = DictionaryCount;
                        strcpy(dictionary[DictionaryIndex].DictionaryWord, word[i].wordName);
                        strcpy(dictionary[DictionaryIndex].TranslationWord, word[j].wordName);
                        DictionaryCount = DictionaryCount + 1;
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
    CompressedFile_txt = fopen("CompressedFile.txt", "w");
    while (fgets(str, 4096, File_txt) != NULL)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n' || str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == ':')
            {
                word[WordNum] = '\0';
                //printf("%d", DictionaryCount);
                for (DictionaryIndex = 0; DictionaryIndex < DictionaryCount; DictionaryIndex++)
                {
                    if (strcmp(dictionary[DictionaryIndex].DictionaryWord, word) == 0)
                    {
                        fprintf(CompressedFile_txt, "%s", dictionary[DictionaryIndex].TranslationWord);
                        Marks(str, i, CompressedFile_txt);
                        break;
                    }
                    else
                    {
                        if (strcmp(dictionary[DictionaryIndex].TranslationWord, word) == 0)
                        {
                            fprintf(CompressedFile_txt, "%s", dictionary[DictionaryIndex].DictionaryWord);
                            Marks(str, i, CompressedFile_txt);
                            break;
                        }
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
                //if (word == NULL) break;
                word = (char*)realloc(word, (WordNum + 2) * sizeof(char));
                WordNum++;
            }
        }
        fprintf(CompressedFile_txt, "\n");
    }
    fclose(CompressedFile_txt);
    free(str);
}