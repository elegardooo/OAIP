#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Header.h"

int main()
{
    int menu_choice = 0, exit = 0, found = 0;
    cache* Cache = cache_initialization(CACHE_SIZE);
    while (exit != -1)
    {
        printf("\n-----------------------------------------------------------\n1.Find IP by domain.\n2.Print cache.\n3.Exit.\nChoose the option: ");
        menu_choice = int_input(1, 3);
        switch (menu_choice)
        {
        case SEARCH_BY_IP:
            find_ip_by_domain(Cache);
            break;
        case PRINT_CACHE:
            print_cache(Cache);
            break;
        case EXIT:
            printf("Exiting the program...");
            free_cache(Cache);
            exit = -1;
            break;
        default:
            printf("Wrong input. Try again.\n");
            rewind(stdin);
            break;
        }
    }
}

