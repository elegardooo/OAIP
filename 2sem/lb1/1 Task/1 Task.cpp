
#include <stdio.h>
#include <stdlib.h>

typedef struct computer
{
    char* name;
    int Matrix_frequency, RAM, Memory;
} computer;

int input_nums()
{
    int number;
    while ((scanf_s("%d", &number) != 1) || (number <= 0) || (getchar() != '\n'))
    {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    return number;
}

char* name_input(char** string)
{
    int max_size = 255, length=0, c;
    (*string) = (char*)calloc(max_size, sizeof(char));
    while (--max_size > 0 && (c = getchar()) != EOF && c != '\n')
        (*string)[length++] = c;
    (*string)[length]= '\0';
    return *string;
}

computer* struct_memory(int array_size)
{
    computer* laptops= (computer*)calloc(array_size, sizeof(computer));
    return laptops;
}

computer struct_filling(computer** laptops, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("Enter the info about %d laptop.", i+1);
        printf("Name: ");
        name_input(&(*laptops)[i].name);
        printf("Matrix frequency: ");
        (*laptops)[i].Matrix_frequency = input_nums();
        printf("RAM(gb): ");
        (*laptops)[i].RAM = input_nums();
        printf("Memory(mb): ");
        (*laptops)[i].Memory = input_nums();
    }
    return **laptops;
}

int main()
{
    int array_size;
    printf("Input size of array: ");
    array_size = input_nums();
    computer* laptops = struct_memory(array_size);
    *laptops = struct_filling(&laptops, array_size);
    printf("%d\n", array_size);
    //printf("%s", laptops[0].name);
    return 0;
}
