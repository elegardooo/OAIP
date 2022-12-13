
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

int str_len(char* s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void input_str(char*** str, int argc, char** argv, int& maxslen)
{
    if (argc == 1)
    {
        printf("There is no string arguments ");
        exit(1);
    }
    (*str) = (char**)malloc(argc * sizeof(char*));
    for (int i = 1; i < argc; i++)
    {
        int length = str_len(argv[i]);
        if (maxslen < length)
            maxslen = length;
        (*str)[i - 1] = (char*)calloc(length, sizeof(char*));
        for (int j = 0; j < length; j++)
        {
            (*str)[i - 1][j] = argv[i][j];
        }
    }
}

/*char*** memory(char*** str, int argc, int maxslen)
{
    for (int i = 0; i < argc; i++)
        (*str)[i] = (char*)realloc(str, maxslen * sizeof(char**));
    return str;
}*/

void output_str(char** str, int argc)
{
    for (int i = 0; i < argc-1; i++)
    {
        printf("%s\n\n", str[i]);
    }
}

int longest_word_len(char* str)
{
    int maxwlen=0, len=0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] != ' ') && (str[i] != '\t'))
        {
            len++;
            if (maxwlen < len)
                maxwlen = len;
        }
        else
            len = 0;
    }
    return maxwlen;
}

void insert_sort(int argc, char*** str, int maxslen)
{
    int value, temp, valuei, k, maxlen, ind;
    for (int i = 1; i < argc-1; i++)
    {
        value = longest_word_len(*str[i]);
        valuei = i;
        for (k = i - 1; k >= 0 && longest_word_len(*str[k]) > value; k--)
        {
            printf("4");
            if (str_len((*str)[k + 1]) > str_len((*str)[k]))
            {
                printf("5");
                ind = 1;
                temp = str_len((*str)[k]);
                (*str)[k] = (char*)realloc(str, str_len((*str)[k + 1]) * sizeof(char));
            }
            else
            {
                ind = 0;
                temp = str_len((*str)[k + 1]);
                (*str)[k + 1] = (char*)realloc(str, str_len((*str)[k]) * sizeof(char));
            }
            for (int j = 0; j < str_len(*str[k + 1]); j++)
            {
                (*str)[k + 1][j] = (*str)[k][j];
                //temp = str[k + 1][j];
                //(*str)[k + 1][j] = (*str)[k][j];
                //str[k][j] = temp;
            }
            if (ind==1)
                (*str)[k + 1] = (char*)realloc(str, temp * sizeof(char));
            else
                (*str)[k] = (char*)realloc(str, temp * sizeof(char));
        }
        printf("3");
        if (str_len((*str)[k + 1]) > str_len((*str)[valuei]))
        {
            ind = 1;
            temp = str_len((*str)[valuei]);
            (*str)[valuei] = (char*)realloc(str, str_len((*str)[k + 1]) * sizeof(char));
        }
        else
        {
            ind = 0;
            temp = str_len((*str)[k + 1]);
            (*str)[k + 1] = (char*)realloc(str, str_len((*str)[valuei]) * sizeof(char));
        }
        for (int j = 0; j < str_len(*str[k + 1]); j++)
        {
            (*str)[k + 1][j] = (*str)[valuei][j];
        }
        if (ind==1)
            (*str)[k + 1] = (char*)realloc(str, temp * sizeof(char));
        else
            (*str)[k] = (char*)realloc(str, temp * sizeof(char));
    }
}

int main(int argc, char** argv)
{
    int row=argc-1, maxslen=0;
    char** string;
    printf("%d\n", row);
    input_str(&string, argc, argv, maxslen);
    printf("%d\n", row);
    //memory(&string, argc, maxslen);
    printf("%d\n", row);
    printf("Strings array:\n");
    output_str(string, argc);
    printf("%d\n", row);
    insert_sort(argc, &string, maxslen);
    printf("%d", longest_word_len(string[0]));
    printf("Sorted strings array:\n");
    output_str(string, argc);
}
