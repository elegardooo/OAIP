#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct computer
{
    char* name;
    int Matrix_frequency;
    int RAM;
    int Memory;
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
    int max_size = 255;
    int length = 0;
    int c;
    (*string) = (char*)calloc(max_size, sizeof(char));
    fgets((*string), max_size, stdin);
    length = strlen((*string));
    (*string)[length-1] = '\0';
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
        printf("\nName: %s", laptops[i].name);
        printf("\nMatrix_frequency: %d", laptops[i].Matrix_frequency);
        printf("\nRAM: %d", laptops[i].RAM);
        printf("\nMemory: %d\n", laptops[i].Memory);
    }
}

void input_sort_choice(int* sort_choice)
{
    while (scanf_s("%d", sort_choice) != 1 || *sort_choice < 1 || *sort_choice > 4 || getchar() != '\n')
    {
        printf("Wrong input. Try again.\n");
        while (getchar() != '\n');
    }
}

void create_structure(computer** laptops, int* array_size)
{
    //int array_size;
    printf("Input size of array: ");
    (*array_size) = input_nums();
    *laptops = struct_memory(*array_size);
    **laptops = struct_filling((laptops), *array_size);
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
    int exit = 0;
    while (exit != 1)
    {
        printf("\n1.Sort by Name.\n2.Sort by Matrix Frequency.\n3.Sort by RAM.\n4.Sort by Memory.\nChoose the type of sorting: ");
        input_sort_choice(&sort_choice);
        switch (sort_choice)
        {
        case 1:
            name_sort(laptops, array_size);
            exit = 1;
            break;
        case 2:
            Matrix_frequency_sort(laptops, array_size);
            exit = 1;
            break;
        case 3:
            RAM_sort(laptops, array_size);
            exit = 1;
            break;
        case 4:
            Memory_sort(laptops, array_size);
            exit = 1;
            break;
        default:
            printf("Wrong input. Try again.\n");
            rewind(stdin);
            break;
        }
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

void deleting(computer** laptops, int* array_size)
{
    int del_num=0;
    printf("\nChoose laptop number to remove(From 1 to %d): ", *array_size);
    while (scanf_s("%d", &del_num)!= 1 || (del_num < 1) || (del_num > *array_size) || getchar()!='\n')
    {
        printf("Wrong input. Try again.\n\n");
        rewind(stdin);
    }
    free((*laptops)[del_num-1].name);
    for (int i = del_num-1; i < (*array_size)-1; i++)
    {
        (*laptops)[i].name = (*laptops)[i + 1].name;
        (*laptops)[i].Matrix_frequency = (*laptops)[i + 1].Matrix_frequency;
        (*laptops)[i].RAM = (*laptops)[i + 1].RAM;
        (*laptops)[i].Memory = (*laptops)[i + 1].Memory;
    }
    (*array_size) = (*array_size) - 1;
    *laptops = (computer*)realloc(*laptops, (*array_size)  * sizeof(computer));
}

int compare_Matrix(computer* laptops, int i)
{
    if (laptops[i].Matrix_frequency == laptops[i + 1].Matrix_frequency)
        return 0;
    else
        if (laptops[i].Matrix_frequency > laptops[i + 1].Matrix_frequency)
            return 1;
        else
            return -1;
}

int compare_RAM(computer* laptops, int i)
{
    if (laptops[i].RAM == laptops[i + 1].RAM)
        return 0;
    else
        if (laptops[i].RAM > laptops[i + 1].RAM)
            return 1;
        else
            return -1;
}

int compare_Memory(computer* laptops, int i)
{
    if (laptops[i].Memory == laptops[i + 1].Memory)
        return 0;
    else
        if (laptops[i].Memory > laptops[i + 1].Memory)
            return 1;
        else
            return -1;
}

void double_sort(computer* laptops, int array_size)
{
    int first_sort, second_sort, temp, sort[5];
    char* tempc;
    printf("\n1.Sort by Name.\n2.Sort by Matrix Frequency.\n3.Sort by RAM.\n4.Sort by Memory.\nChoose the 1st type of sorting : ");
    while (scanf_s("%d", &first_sort) != 1 || first_sort < 1 || first_sort >4 || getchar() != '\n')
    {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    switch (first_sort)
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
    printf("\n1.Sort by Name.\n2.Sort by Matrix Frequency.\n3.Sort by RAM.\n4.Sort by Memory.\nChoose the 2nd type of sorting: ");
    while (scanf_s("%d", &second_sort) != 1 || second_sort == first_sort || second_sort < 1 || second_sort > 4 || getchar() != '\n')
    {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    for(int i=1; i<array_size; i++)
        for (int j = 0; j < array_size - 1; j++)
        {
            sort[1] = strcmp(laptops[j].name, laptops[j + 1].name);
            sort[2] = compare_Matrix(laptops, j);
            sort[3] = compare_RAM(laptops, j);
            sort[4] = compare_Memory(laptops, j);
            if (sort[first_sort] == 0 && sort[second_sort] > 0)
            {
                tempc = laptops[j].name; laptops[j].name = laptops[j + 1].name; laptops[j + 1].name = tempc;
                temp = laptops[j].Matrix_frequency; laptops[j].Matrix_frequency = laptops[j + 1].Matrix_frequency; laptops[j + 1].Matrix_frequency = temp;
                temp = laptops[j].RAM; laptops[j].RAM = laptops[j + 1].RAM; laptops[j + 1].RAM = temp;
                temp = laptops[j].Memory; laptops[j].Memory = laptops[j + 1].Memory; laptops[j + 1].Memory = temp;
            }
        }
}

void menu(computer* laptops, int array_size)
{
    int choice = 0, exit = 0;
    while (exit != 3)
    {
        printf("-------------------------------------------------\n1.Create structure.\n2.Print structure.\n3.Sort structure by 1 type.\n4.Sort structure by 2 types.\n5.Remove laptop.\n6.Exit.\nChoose the option: ");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            if (exit != 1) 
            {
                create_structure(&laptops, &array_size);
                exit = 1;
            }
            else
                printf("Structure already created.\n");
            break;
        case 2:
            if (exit != 1)
            {
                printf("You need to create structure first.\n");
                break;
            }
            print_structure(laptops, array_size);
            break;
        case 3:
            if (exit != 1)
            {
                printf("You need to create structure first.\n");
                break;
            }
            sorting(laptops, array_size);
            break;
        case 4:
            if (exit != 1)
            {
                printf("You need to create structure first.\n");
                break;
            }
            double_sort(laptops, array_size);
            break;
        case 5:
            if (exit != 1)
            {
                printf("You need to create structure first.\n");
                break;
            }
            if (array_size == 1)
            {
                printf("There's only 1 laptop.\n");
                break;
            }
            deleting(&laptops, &array_size);
            break;
        case 6:
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
    menu(laptops, array_size);
    return 0;
}
