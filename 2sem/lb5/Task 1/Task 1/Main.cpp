﻿
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_VALUE 255

typedef struct cache
{
    char key[MAX_STR_VALUE];
    char value[MAX_STR_VALUE];
    struct cache* next;
    struct cache* prev;
} cache;

typedef struct list
{
    cache* head;
    cache* tail;
} list;

typedef struct data
{
    char domain[MAX_STR_VALUE];
    char ip[MAX_STR_VALUE];
} data;

void push(data* Data, list* List)
{
    cache* temp = (cache*)malloc(sizeof(cache));
    if (temp == NULL)
        exit(1);
    strcpy(temp->key, Data->domain);
    strcpy(temp->value, Data->ip);
    temp->next = List->head;
    temp->prev = NULL;
    if (List->head)
        List->head->prev = temp;
    List->head = temp;
    if (List->tail == NULL)
    {
        List->tail = temp;
    }
}

void* pop(list* List)
{
    cache* next;
    void* temp;
    if (List->tail == NULL)
        exit(4);
    next = List->tail;
    List->tail = List->tail->prev;
    if (List->tail)
        List->tail->next = NULL;
    if (next == List->head)
        List->head = NULL;
    temp = next->value;
    free(next);
    return temp;
}

int hashing(char* str)
{
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
        hash = hash * 31 + str[i];
    return hash % 100;
}

data* read_data(data* Data, char* str)
{
    int pos = 0;
    for (int i = 0; str[i] != ' '; i++)
    {
        Data->domain[i] = str[i];
        if (str[i+1] == ' ')
        {
            Data->domain[i+1] = '\0';
            pos = i+1;
        }
    }
    for (int i = 0, j = pos + 1; str[j] != '\n'; i++, j++)
    {
        Data->ip[i] = str[j];
        if (str[j+1] == '\n')
            Data->ip[i+1] = '\0';
    }
    int b = hashing(Data->domain);
    printf("%d ", b);
    return Data;
}

list* cache_memory()
{
    list* temp = (list*)malloc(sizeof(list));
    if (temp == NULL)
        exit(1);
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

list* deserialize_list()
{
    char str[MAX_STR_VALUE];
    FILE* Input = fopen("cache1.txt", "r");
    if (Input == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    data* Data = (data*)malloc(sizeof(data));
    if (Data == NULL)
        exit(1);
    list* List = NULL;
    for (int i = 0; i < 4; i++)
        List = cache_memory();
    while (fgets(str, MAX_STR_VALUE, Input) != NULL)
    {
        Data = read_data(Data, str);
        push(Data, List);
    }
    fclose(Input);
    return List;
}

void serialize_list(list* List)
{
    FILE* file = fopen("cache1.txt", "w");
    if (file == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    for (cache* info = List->head; info != List->tail->next; info = info->next)
    {
        fprintf(file, "%s ", info->key);
        fprintf(file, "%s\n", info->value);
    }
    fclose(file);
}

int find_ip_in_cache(list* List, char* domain, int found)
{
    for (cache* info = List->head; info != List->tail->next; info = info->next)
    {
        if (strcmp(info->key, domain) == 0)
        {
            printf("Found domain IP in cache: %s\n", info->value);
            found = 1;
        }
    }
    return found;
}

int find_ip_in_file(list* List, char* domain, int found)
{
    char str[MAX_STR_VALUE];
    FILE* file = fopen("database.txt", "r");
    if (file == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    data* Data = (data*)malloc(sizeof(data));
    if (Data == NULL)
        exit(1);
    while (fgets(str, MAX_STR_VALUE, file) != NULL)
    {
        read_data(Data, str);
        if (strcmp(domain, Data->domain) == 0)
        {
            printf("Found domain IP in file: %s\n", Data->ip);
            push(Data, List);
            pop(List);
            serialize_list(List);
            found = 1;
        }
    }
    return found;
}

void print_cache(list* List)
{
    for (cache* info = List->head; info != List->tail->next; info = info->next)
    {
        printf("\nDomain is: '%s'\t", info->key);
        printf("IP is: '%s'\n", info->value);
    }
}

void free_list(list* List)
{
    for (cache* info = List->head, *next = NULL; info; info = next)
    {
        next = info->next;
        free(info);
    }
    free(List);
}

int main()
{
    int choice = 0, exit = 0, found = 0;
    list* List = deserialize_list();
    while (exit != -1)
    {
        printf("-----------------------------------------------------------\n1.Print cache.\n2.Find IP.\n3.Exit.\nChoose the option: ");
        /*if (scanf("%d", &choice) == NULL)
            return 0;*/
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            found = 0;
            char domain[MAX_STR_VALUE];
            printf("Enter the domain name: ");
            if (scanf("%s", &domain) == NULL)
                return 0;
            //printf("%s\n", domain);
            found = find_ip_in_cache(List, domain, found);
            if (found == 0)
            {
                printf("Domain IP was not found in cache. Searching in file...\n");
                found = find_ip_in_file(List, domain, found);
                if (found == 0)
                {
                    printf("Domain IP was not found in file.\n");
                }
            }
            break;
        case 2:
            print_cache(List);
            break;
        case 3:
            free_list(List);
            exit = -1;
            printf("Exiting the program...");
            break;
        default:
            printf("Wrong input. Try again.\n");
            rewind(stdin);
            break;
        }
    }
}

