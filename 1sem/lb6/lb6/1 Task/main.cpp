// 1 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <time.h>
#include <stdlib.h>
#include "array.h"

void main(void)
{
    int *mas, n, choose;
    srand(time(NULL));
    printf("Enter the size of array: ");
    input_size(n);
    mas = memory(n);
    printf("1.User filling\n2.Random filling\n");
    printf("Choose the type of array filling: ");
    input_choose(choose);
    type_of_filling(mas, n, choose);
    printf("Array: ");
    //output_array(mas, n);
    clock_t start = clock();
    sort(mas, n);
    clock_t end=clock();
    printf("\nChanged array: ");
    //output_array(mas, n);
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%f", seconds);

    free(mas);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
