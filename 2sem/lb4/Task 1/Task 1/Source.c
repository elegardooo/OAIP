#include "Header.h"

char* trim_start(char* str)
{
    int i = 0, j;
    while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v'))
        i++;
    if (i > 0)
    {
        while (i > 0)
        {
            for (j = 0; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
            }
            i--;
        }
        str[j] = '\0';
    }
    return str;
}

char* trim_end(char* str)
{
    if (str == NULL)
        return NULL;
    int length = strlen(str);
    while (length > 0 && isspace(str[length - 1]))
        length--;
    str[length] = '\0';
    return str;
}

Tree* deserialize_tree(FILE* Input)
{
    Tree* Node = (Tree*)malloc(sizeof(Tree));
    if (fgets(Node->Word, STR_MAX_VALUE, Input) == NULL)
        return NULL;
    //printf("%s", Node->Word);
    trim_end(Node->Word);
    if (strcmp(Node->Word, MARKER) == 0)
    {
        free(Node);
        return NULL;
    }
    Node->Left = deserialize_tree(Input);
    Node->Right = deserialize_tree(Input);
    //printf("%s", Node->Word);
    return Node;
}

void serialize_tree(Tree* Root, FILE* Output)
{
    if (Root == NULL)
    {
        fprintf(Output, "%s\n", MARKER);
        return;
    }
    fprintf(Output, "%s\n", Root);
    serialize_tree(Root->Left, Output);
    serialize_tree(Root->Right, Output);
}

Tree* create_node(Tree* Left, Tree* Right, char* str)
{
    Tree* Node = (Tree*)malloc(sizeof(Tree));
    strcpy_s(Node->Word, STR_MAX_VALUE, str);
    Node->Left = Left;
    Node->Right = Right;
    return Node;
}

void edit_tree(Tree* Root)
{
    char New_Answer[STR_MAX_VALUE], New_Question[STR_MAX_VALUE];
    printf("What was that?\n");
    fgets(New_Answer, STR_MAX_VALUE, stdin);
    trim_start(New_Answer);
    trim_end(New_Answer);
    printf("How does it differ from my guess?\n");
    fgets(New_Question, STR_MAX_VALUE, stdin);
    trim_start(New_Question);
    trim_end(New_Question);
    Root->Left = create_node(NULL, NULL, Root->Word);
    Root->Right = create_node(NULL, NULL, New_Answer);
    strcpy_s(Root->Word, STR_MAX_VALUE, New_Question);
}

void akinator(Tree* Root)
{
    int choose;
    printf("Question - %s?\n", Root->Word);
    printf("1.Yes  2.No\nChoose: ");
    while ((scanf_s("%d", &choose) != 1) || (getchar() != '\n') || choose < 1 || choose > 2)
    {
        printf("Wrong input. Try again\n1.Yes  2.No\nChoose: ");
        rewind(stdin);
    }
    if (Root->Left == NULL && Root->Right == NULL)
    {
        if (choose == 2)
            edit_tree(Root);
        if (choose == 1)
            printf("End of the Akinator game. Exiting the programm...");
    }
    else
    {
        if (choose == 2)
            akinator(Root->Left);
        if (choose == 1)
            akinator(Root->Right);
    }
}

void free_memory(Tree* Root)
{
    if (Root->Left == NULL && Root->Right == NULL)
    {
        free(Root->Word);
    }
    else
    {
        free_memory(Root->Left);
        free_memory(Root->Right);
    }
}