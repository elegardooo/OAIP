#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** memory_alloc(int size)
{
    int memory_size = size;
    int** temp = (int**)calloc(memory_size, sizeof(int*));
    if(!temp)
    {
        printf("Error: can't allocate memory");
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        temp[i] = (int*)calloc(size, sizeof(int));
        if (!temp[i])
        {
            printf("Error: can't allocate memory");
            exit(1);
        }
    }
    return temp;
}

void matrix_filling(int** array, int size)
{
    printf("Fill the adjacency matrix: \n");
    for (int row = 0; row < size; row++)
    {
        for (int col = row; col < size; col++)
        {
            if (col != row)
            {
                printf("Enter the connection of %d verticy with %d verticy (1 - connected; 0 - not connected): ", row + 1, col + 1);
                while ((scanf_s("%d", &array[row][col]) != 1) || (array[row][col] < 0) || (array[row][col] > 1) || (getchar() != '\n'))
                {
                    printf("Wrong input. Try again.\n");
                }
                array[col][row] = array[row][col];
            }
            else
                array[col][row] = 0;
        }
    }
}

void matrix_printing(int** array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("|%d \n", i + 1);
    }
}

void set_printing(int* set, int set_size)
{
    printf("\nMaximum indepent set is {");
    for (int i = 0; i < set_size; i++)
    {
        if (i != set_size - 1)
            printf("%d,  ", set[i]);
        else
            printf("%d", set[i]);
    }
    printf("}");
}

void free_memory(int** array, int* set, int vertices)
{
    for (int i = 0; i < vertices; i++)
        free(array[i]);
    free(array);
    free(set);
}

int main()
{

    int** matrix;
    int* set;
    int set_size = 1;
    int vertices;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    while ((scanf_s("%d", &vertices) != 1) || (vertices < 1) || (getchar() != '\n'))
    {
        printf("Wrong input. Try again\n");
        rewind(stdin);
    }
    matrix = memory_alloc(vertices);
    matrix_filling(matrix, vertices);
    matrix_printing(matrix, vertices);
    set = (int*)calloc(vertices, sizeof(int));
    if (!set)
    {
        printf("Error: can't allocate memory");
        exit(1);
    }
    set[0] = rand() % vertices + 1;
    for (int col = 0, found = 0; col < vertices; found = 0, col++)
    {
        for (int set_pos = 0, repeat = 0; set_pos < set_size; repeat = 0, set_pos++)
        {
            if (set[set_pos] != col + 1)
            {
                if ((matrix[set[set_pos] - 1][col] == 0) && (repeat == 0))
                    found = 1;
                else
                {
                    set_pos = set_size;
                    found = 0;
                }
            }
            else
            {
                set_pos = set_size;
                found = 0;
            }
        }
        if (found == 1)
        {
            set[set_size] = col + 1;
            set_size++;
        }
    }
    set_printing(set, set_size);
    free_memory(matrix, set, vertices);
    return 0;
}
