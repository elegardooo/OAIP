
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print_structure(computer* laptops, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("\nName: %s", (laptops)[i].name);
        printf("\nMatrix_frequency: %d", laptops[i].Matrix_frequency);
        printf("\nRAM: %d", laptops[i].RAM);
        printf("\nMemory: %d\n", laptops[i].Memory);
    }
}

void input_sort_choice(int& sort_choice)
{
    while (scanf_s("%d", &sort_choice) != 1 || sort_choice < 1 || sort_choice > 4 || getchar() != '\n')
    {
        printf("Wrong input. Try again.\n");
        while (getchar() != '\n');
    }
}

void create_structure(computer* &laptops, int& array_size)
{
    //int array_size;
    printf("Input size of array: ");
    array_size = input_nums();
    laptops = struct_memory(array_size);
    *laptops = struct_filling(&laptops, array_size);
}

void name_sort(computer* laptops, int array_size)
{
    int temp; char* tempc;
    for (int i = 1; i < array_size; i++)
    {
        for (int j = 0; j < array_size-1; j++)
        {
            if (strcmp((laptops[j].name), (laptops[j + 1].name)) > 0)
            {
                tempc = laptops[j].name; laptops[j].name = laptops[j + 1].name; laptops[j + 1].name = tempc;
                temp = laptops[j].Matrix_frequency; laptops[j].Matrix_frequency = laptops[j + 1].Matrix_frequency; laptops[j + 1].Matrix_frequency = temp;
                temp = laptops[j].RAM; laptops[j].RAM = laptops[j + 1].RAM; laptops[j + 1].RAM = temp;
                temp = laptops[j].Memory; laptops[j].Memory = laptops[j + 1].Memory; laptops[j + 1].Memory = temp;
            }
        }
    }
}

void Matrix_frequency_sort(computer* laptops, int array_size)
{
    int temp; char* tempc;
    for (int i = 1; i < array_size; i++)
    {
        for (int j = 0; j < array_size - 1; j++)
        {
            if ((laptops[j].Matrix_frequency) > (laptops[j + 1].Matrix_frequency))
            {
                tempc = laptops[j].name; laptops[j].name = laptops[j + 1].name; laptops[j + 1].name = tempc;
                temp = laptops[j].Matrix_frequency; laptops[j].Matrix_frequency = laptops[j + 1].Matrix_frequency; laptops[j + 1].Matrix_frequency = temp;
                temp = laptops[j].RAM; laptops[j].RAM = laptops[j + 1].RAM; laptops[j + 1].RAM = temp;
                temp = laptops[j].Memory; laptops[j].Memory = laptops[j + 1].Memory; laptops[j + 1].Memory = temp;
            }
        }
    }
}

void RAM_sort(computer* laptops, int array_size)
{
    int temp; char* tempc;
    for (int i = 1; i < array_size; i++)
    {
        for (int j = 0; j < array_size - 1; j++)
        {
            if ((laptops[j].RAM) > (laptops[j + 1].RAM))
            {
                tempc = laptops[j].name; laptops[j].name = laptops[j + 1].name; laptops[j + 1].name = tempc;
                temp = laptops[j].Matrix_frequency; laptops[j].Matrix_frequency = laptops[j + 1].Matrix_frequency; laptops[j + 1].Matrix_frequency = temp;
                temp = laptops[j].RAM; laptops[j].RAM = laptops[j + 1].RAM; laptops[j + 1].RAM = temp;
                temp = laptops[j].Memory; laptops[j].Memory = laptops[j + 1].Memory; laptops[j + 1].Memory = temp;
            }
        }
    }
}

void Memory_sort(computer* laptops, int array_size)
{
    int temp; char* tempc;
    for (int i = 1; i < array_size; i++)
    {
        for (int j = 0; j < array_size - 1; j++)
        {
            if ((laptops[j].Memory) > (laptops[j + 1].Memory))
            {
                tempc = laptops[j].name; laptops[j].name = laptops[j + 1].name; laptops[j + 1].name = tempc;
                temp = laptops[j].Matrix_frequency; laptops[j].Matrix_frequency = laptops[j + 1].Matrix_frequency; laptops[j + 1].Matrix_frequency = temp;
                temp = laptops[j].RAM; laptops[j].RAM = laptops[j + 1].RAM; laptops[j + 1].RAM = temp;
                temp = laptops[j].Memory; laptops[j].Memory = laptops[j + 1].Memory; laptops[j + 1].Memory = temp;
            }
        }
    }
}

void sorting(computer* laptops, int array_size)
{
    int sort_choice = 0;
    printf("\n1.Sort by Name.\n2.Sort by Matrix Frequency.\n3.Sort by RAM.\n4.Sort by Memory.\nChoose the type of sorting: ");
    input_sort_choice(sort_choice);
    switch (sort_choice)
    {
    case 1:
        name_sort(laptops, array_size);
        break;
    case 2:
        Matrix_frequency_sort(laptops, array_size);
        break;
    case 3:
        RAM_sort(laptops, array_size);
        break;
    case 4:
        Memory_sort(laptops, array_size);
        break;
    }
    printf("\nStructure was sorted!\n");
}

void free_memory(computer* laptops, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        free(laptops[i].name);
    }
    free(laptops);
}

void menu(computer* laptops, int array_size)
{
    int choice = 0, exit = 0;
    //create_structure(laptops, array_size);
    while (exit != 3)
    {
        printf("-------------------------------------------------\n1.Create structure.\n2.Print structure.\n3.Sort structure.\n4.Exit.\nChoose the option: ");
        //input_choice(choice);
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            if (exit != 1)
                create_structure(laptops, array_size);
            else
                printf("Structure already created.\n");
            break;
        case 2:
            print_structure(laptops, array_size);
            break;
        case 3:
            sorting(laptops, array_size);
            break;
        case 4:
            exit = 3;
            break;
        default:
            printf("Wrong input. Try again.\n");
            rewind(stdin);
            break;
        }
    }
    free_memory(laptops, array_size);
}

int main()
{
    int array_size=0;
    computer* laptops=NULL;
    //printf("%d\n", array_size);
    //print_structure(laptops, array_size);
    //printf("%s", laptops[0].name);
    menu(laptops, array_size);
    return 0;
}
