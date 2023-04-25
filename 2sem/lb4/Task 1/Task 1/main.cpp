#include "Header.h"

int main()
{
    FILE* Input = fopen("akinator.txt", "r");
    if (Input == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    Tree* Root = deserialize_tree(Input);
    fclose(Input);
    akinator(Root);
    FILE* Output = fopen("akinator.txt", "w");
    if (Output == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    serialize_tree(Root, Output);
    return 0;
}
