
#include <stdio.h>
#include <stdlib.h>

int str_len(char* s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char** memory(int argc)
{
    int n = 256;
    char** str;
    str = (char**)calloc((argc-1), sizeof(char*));
    for (int i = 0; i < argc-1; i++)
    {
        str[i] = (char*)calloc(n, sizeof(char));
    }
    return str;
}

void input_str(char** str, int argc, char** argv)
{
    if (argc == 1)
    {
        printf("There is no string arguments ");
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        int length = str_len(argv[i])
        for (int j = 0; j < length; j++)
        {
            (str)[i - 1][j] = argv[i][j];
        }
        (str)[i - 1][length] = '\0';
    }
}

int longest_word_len(char* str)
{
    int maxwlen = 0, len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] != ' ') && (str[i] != '\t'))
        {
            len++;
            if (len > maxwlen)
                maxwlen = len;
        }
        else
            len = 0;
    }
    return maxwlen;
}

void output_str(char** str, int argc)
{
    for (int i = 0; i < argc-1; i++)
    {
        printf("%s\n", str[i]);
    }
}

void insert_sort(int argc, char** str)
{
    int value, k, maxlen;;
    for (int i = 1; i < argc - 1; i++)
    {
        value = longest_word_len((str)[i]);
        (str)[argc] = (str)[i];
        for (k = i - 1; k >= 0 && longest_word_len((str)[k]) < value; k--)
        {
            (str)[k + 1] = (str)[k];
        }
        (str)[k + 1] = (str)[argc];
    }
}

void freee(char** string, int argc, char** argv)
{
    for (int i = 0; i < argc-1; i++)
    {
        free(string[i]);
    }
    free(string);
}

int main(int argc, char** argv)
{
    char** string;
    string = memory(argc);
    input_str(string, argc, argv);
    printf("Strings array:\n");
    output_str(string, argc);
    insert_sort(argc, string);
    printf("Sorted strings array:\n");
    output_str(string, argc);
    freee(string, argc, argv);
}
