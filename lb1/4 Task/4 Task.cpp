﻿// 4 Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int input;
    printf("1. Informatics\n");
    printf("2. Cultural studies\n");
    printf("3. Math\n");
    printf("4. Foreign language\n");
    printf("5. Economics\n");
    printf("Choose the discipline: ");
        scanf("%d", &input);
        while (input < 1 || input >5)
        {
            printf("Wrong input, Choose the discipline: ");
            scanf("%d", &input);
        }
    switch (input)
    {
    case 1:         printf("Exam, Credit");
        break;
    case 2:       printf("Credit");
        break;
    case 3:          printf("Exam, Credit");
        break;
    case 4:    printf("Exam, Credit");
        break;
    case 5:           printf("Exam"); 
        break;
            
    }

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
