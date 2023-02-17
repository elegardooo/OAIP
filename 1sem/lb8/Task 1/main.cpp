#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

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
