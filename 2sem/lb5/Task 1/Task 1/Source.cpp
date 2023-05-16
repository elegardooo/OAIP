#include "Header.h"

void free_object(hashtable_object* object)
{
    free(object->key);
    free(object->node);
    free(object);
}

void free_list(list* head)
{
    list* temp = NULL;
    if (head == NULL)
        return;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->object->key);
        free(temp->object->node);
        free(temp->object);
        free(temp);
    }
}

void free_chains(hashtable* table)
{
    list** chains = table->chains;
    for (int i = 0; i < table->size; i++)
        free_list(chains[i]);
    free(chains);
}

void free_hashtable(hashtable* table)
{
    hashtable_object* object = NULL;
    for (int i = 0; i < table->size; i++)
    {
        object = table->objects[i];
        if (object != NULL)
            free_object(object);
    }
    free_chains(table);
    free(table);
}

void free_cache(cache* Cache)
{
    free_hashtable(Cache->table);
    free(Cache);
}

list** create_chains(hashtable* table)
{
    list** chains = (list**)malloc(table->size * sizeof(list*));
    if (chains)
    {
        for (int i = 0; i < table->size; i++)
        {
            chains[i] = NULL;
        }
    }
    return chains;
}

hashtable_object* create_object(char* key, node* node)
{
    hashtable_object* object = (hashtable_object*)malloc(sizeof(hashtable_object));
    object->node = node;
    object->key = key;
    return object;
}

hashtable* create_table(int table_size)
{
    hashtable* table = (hashtable*)malloc(sizeof(hashtable));
    if (table)
    {
        table->size = table_size;
        table->count = 0;
        table->objects = (hashtable_object**)malloc(table_size * sizeof(hashtable_object*));
        if (table->objects)
        {
            for (int i = 0; i < table_size; i++)
                table->objects[i] = NULL;
        }
        table->chains = create_chains(table);
    }
    return table;
}

cache* cache_initialization(int cache_size)
{
    cache* Cache = (cache*)malloc(sizeof(cache));
    if (Cache)
    {
        Cache->table = create_table(cache_size);
        Cache->head = NULL;
        Cache->tail = NULL;
        Cache->count = 0;
    }
    return Cache;
}

node* create_node(char* key, char* value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->key = key;
    temp->value = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

char* str_input()
{
    int str_size = NULL;
    char* str = (char*)calloc(MAX_STR_VALUE, sizeof(char));
    gets_s(str, MAX_STR_VALUE);
    str_size = strlen(str);
    str = (char*)realloc(str, str_size + 1);
    return str;
}

int int_input(int min, int max)
{
    int choice = 0;
    while (scanf_s("%d", &choice) == 0 || choice < min || choice > max || getchar() != '\n')
    {
        printf("Wrong input. Try again\n");
        rewind(stdin);
    }
    return choice;
}

int hash_domain(const char* domain)
{
    int hash = 0;
    for (int i = 0; i < strlen(domain); i++)
        hash = hash * 31 + domain[i];
    if (hash < 0)
        hash = hash * (-1);
    return hash % CACHE_SIZE;
}

char* find_key_in_hashtable(hashtable* table, char* domain)
{
    int index = NULL;
    if (domain == NULL)
        return NULL;
    index = hash_domain(domain);
    hashtable_object* cur_object = table->objects[index];
    list* head = table->chains[index];
    while (cur_object != NULL)
    {
        if (strcmp(cur_object->key, domain) == 0)
            return cur_object->node->value;
        if (head == NULL)
            return NULL;
        cur_object = head->object;
        head = head->next;
    }
    return NULL;
}

int check_ip_valid(char* ip)
{
    if (ip == NULL)
        return 0;
    int arr[MAX_IP_COMPONENTS];
    int count = sscanf(ip, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
    if (count != MAX_IP_COMPONENTS)
        return 0;
    for (int i = 0; i < MAX_IP_COMPONENTS; i++)
    {
        if (arr[i]<0 || arr[i] > MAX_IP_VALUE)
            return 0;
    }
    return 1;
}

FILE* open_file(const char* file_name, const char* access)
{
    FILE* file = NULL;
    fopen_s(&file, file_name, access);
    if (file == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    return file;
}

int find_type_index(const char* str, const char* type)
{
    int i = 0;
    int j = 0;
    int searched_index = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        j = 0;
        searched_index = i;
        while (type[j] != '\0' && str[searched_index] == type[j])
        {
            searched_index++;
            j++;
        }
        if (type[j] == '\0')
            return searched_index;
    }
    return 0;
}

int database_searching(char* key, char** domain, char** ip)
{
    int index = 0;
    int new_str_index = 0;
    int type_indent = 0;
    int domain_type = 0;
    char* string = (char*)malloc(MAX_STR_VALUE);
    char* file_domain = (char*)malloc(MAX_STR_VALUE);
    char* file_ip = (char*)malloc(MAX_STR_VALUE);
    FILE* file = open_file("database.txt", "r");
    while (!feof(file))
    {
        fgets(string, MAX_STR_VALUE, file);
        index = find_type_index(string, "IN A");
        type_indent = 4;
        domain_type = TYPE_1;
        if (index == 0)
        {
            index = find_type_index(string, "IN CNAME");
            type_indent = 8;
            domain_type = TYPE_2;
        }
        fseek(file, 0 + new_str_index, SEEK_SET);
        fgets(file_domain, index - type_indent, file);
        fseek(file, index + new_str_index + 1, SEEK_SET);
        fgets(file_ip, MAX_STR_VALUE, file);
        new_str_index = new_str_index + strlen(string) + 1;
        if (strcmp(key, file_domain) == 0)
        {
            (*domain) = file_domain;
            (*ip) = file_ip;
            (*ip)[strcspn((*ip), "\n")] = '\0';
            free(string);
            fclose(file);
            return domain_type;
        }
    }
    free(string);
    fclose(file);
    return 0;
}

void add_in_database(const char* domain)
{
    FILE* database = fopen("database.txt", "r+");
    if (database == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    char* str = NULL;
    fseek(database, 0, SEEK_END);
    fprintf(database, "%s", domain);
    printf("Pick a type of domain.\n1. 'IN A' 2. 'IN CNAME' \nYour choice: ");
    int choice = 0;
    choice = int_input(1, 2);
    if (choice == 1)
    {
        fprintf(database, "%s", " IN A ");
        printf("\nEnter the IP adress: ");
        str = str_input();
        while (check_ip_valid(str) == 0)
        {
            printf("\nWrong input. Enter the correct IP adress: ");
            free(str);
            str = str_input();
        }
    }
    else
        if (choice == 2)
        {
            fprintf(database, "%s", " IN CNAME ");
            printf("\nEnter the domain: ");
            str = str_input();
        }
    fprintf(database, "%s\n", str);
    fclose(database);
}

void hashtable_delete(hashtable* table, const char* key)
{
    int index = hash_domain(key);
    hashtable_object* object = table->objects[index];
    list* head = table->chains[index];
    if (object == NULL)
    {
        return;
    }
    else
    {
        if (!strcmp(object->key, key) && head == NULL)
        {
            table->objects[index] = NULL;
            table->count--;
            return;
        }
        else if (head != NULL)
            if (!strcmp(object->key, key))
            {
                list* node = head;
                head = head->next;
                node->next = NULL;
                table->objects[index] = create_object(node->object->key, node->object->node);
                table->chains[index] = head;
                return;
            }
        list* cur = head;
        list* prev = NULL;
        while (cur != NULL)
        {
            if (!strcmp(cur->object->key, key))
            {
                if (prev = NULL)
                {
                    table->chains[index] = head->next;
                    cur->next = NULL;
                    return;
                }
                else
                {
                    prev->next = cur->next;
                    cur->next = NULL;
                    return;
                }
            }
            prev = cur;
            cur = cur->next;
        }

    }
}

void tail_delete(node** head, node** tail)
{
    node* temp = (*head);
    if ((*tail) != (*head))
    {
        while (temp->next != (*tail))
            temp = temp->next;
        (*tail) = temp;
        (*tail)->next = NULL;
    }
    else
    {
        (*tail) = NULL;
        (*head) = NULL;
    }
}

void add_to_head(node** head, node** tail, char* key, char* value)
{
    node* temp = create_node(key, value);
    if ((*head) == NULL)
    {
        (*head) = temp;
        (*tail) = temp;
    }
    else
    {
        temp->next = (*head);
        (*head)->prev = temp;
        (*head) = temp;
    }

}

list* create_list()
{
    list* new_list = (list*)malloc(sizeof(list));
    return new_list;
}

list* insert_list(list* head, hashtable_object* object)
{
    if (head == NULL)
    {
        list* new_list = create_list();
        new_list->object = object;
        new_list->next = NULL;
        head = new_list;
        return new_list;
    }
    else
    {
        list* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        list* node = create_list();
        node->object = object;
        node->next = NULL;
        temp->next = node;
        return head;
    }
}

void prevent_collision(hashtable* table, int index, hashtable_object* object)
{
    list* head = table->chains[index];

    if (head == NULL)
    {
        head = create_list();
        head->object = object;
        head->next = NULL;
        table->chains[index] = head;
        return;
    }
    else
    {
        list* current = table->chains[index];
        while (current != NULL)
        {
            if (!strcmp(current->object->key, object->key))
            {
                free(current->object->node->value);
                current->object->node->value = object->node->value;
                return;
            }
            current = current->next;
        }
        table->chains[index] = insert_list(head, object);
        return;
    }
}

void add_to_hashtable(hashtable* table, node* node, char* key)
{
    hashtable_object* object = create_object(key, node);
    int index = hash_domain(key);
    hashtable_object* current_object = table->objects[index];
    if (current_object == NULL)
    {
        table->objects[index] = object;
        table->count++;
    }
    else
    {
        if (!strcmp(current_object->key, key))
        {
            free(current_object->node->value);
            current_object->node->value = node->value;
            return;
        }
        else
        {
            prevent_collision(table, index, object);
            return;
        }
    }
}

void insert_in_cache(cache* Cache, char* key, char* value)
{
    if (Cache->count >= CACHE_SIZE)
    {
        hashtable_delete(Cache->table, Cache->tail->key);
        tail_delete(&Cache->head, &Cache->tail);
    }
    add_to_head(&Cache->head, &Cache->tail, key, value);
    add_to_hashtable(Cache->table, Cache->head, key);
    Cache->count++;
}

char* find_ip_in_cache(cache* Cache, char* key, int mark)
{
    char* found_in_cache = NULL;
    char* hashtable_res = find_key_in_hashtable(Cache->table, key);
    if (hashtable_res != NULL)
    {
        if (check_ip_valid(hashtable_res) == VALID && mark == TYPE_1_SEARCH)
        {
            printf("\nFound in cache.\n");
            return hashtable_res;
        }
        else
            return hashtable_res;
    }
    else
    {
        if (mark == TYPE_1_SEARCH)
            printf("\nNot found in cache.\n");
        char* domain = NULL;
        char* ip = NULL;
        int type_found_in_database = database_searching(key, &domain, &ip);
        if (type_found_in_database == 0)
        {
            int add_choice = 0;
            printf("\nError. Domen wasnt found\n");
            printf("Do you want to add domain and IP adress?\n1.Yes 2.No\nYour choice: ");
            add_choice = int_input(1, 2);
            if (add_choice == 1)
            {
                add_in_database(key);
                return NULL;
            }
            return NULL;
        }
        else if (type_found_in_database == TYPE_2)
        {
            mark = TYPE_2_SEARCH;
            if ((found_in_cache = find_ip_in_cache(Cache, ip, mark)) != NULL)
            {
                insert_in_cache(Cache, key, found_in_cache);
                return found_in_cache;
            }
        }
        else if (mark == TYPE_2_SEARCH)
            return ip;
        else
        {
            insert_in_cache(Cache, domain, ip);
            return ip;
        }
    }
}

void find_ip_by_domain(cache* Cache)
{
    char* found_in_cache = NULL;
    char* domain = NULL;
    printf("\nEnter the domain: ");
    domain = str_input();
    found_in_cache = find_ip_in_cache(Cache, domain, TYPE_1_SEARCH);
    if (found_in_cache != NULL)
    {
        printf("IP adress: %s\n", found_in_cache);
    }
}

void print_cache(cache* Cache)
{
    node* node = Cache->head;
    while (node != NULL) {
        printf("%s - %s\n", node->key, node->value);
        node = node->next;
    }
}


