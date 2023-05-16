#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_VALUE 255
#define MAX_IP_VALUE 255
#define MAX_IP_COMPONENTS 4
#define CACHE_SIZE 5
#define TYPE_1_SEARCH 0
#define TYPE_2_SEARCH 1
#define TYPE_1 1
#define TYPE_2 2
#define INVALID 0
#define VALID 1 

typedef struct node node;
typedef struct hashtable hashtable;

typedef struct hashtable_object
{
    char* key;
    node* node;
} hashtable_object;

typedef struct list
{
    hashtable_object* object;
    struct list* next;
} list;

typedef struct hashtable
{
    hashtable_object** objects;
    list** chains;
    int size;
    int count;
} hashtable;

typedef struct node
{
    char* key;
    char* value;
    struct node* next;
    struct node* prev;
} node;

typedef struct cache
{
    hashtable* table;
    node* head;
    node* tail;
    int count;
} cache;

typedef struct data
{
    char domain[MAX_STR_VALUE];
    char ip[MAX_STR_VALUE];
} data;

enum menu
{
    SEARCH_BY_IP = 1, PRINT_CACHE, EXIT
};

void free_object(hashtable_object* object);
void free_list(list* head);
void free_chains(hashtable* table);
void free_hashtable(hashtable* table);
void free_cache(cache* Cache);
list** create_chains(hashtable* table);
hashtable_object* create_object(char* key, node* node);
hashtable* create_table(int table_size);
cache* cache_initialization(int cache_size);
node* create_node(char* key, char* value);
char* str_input();
int int_input(int min, int max);
int hash_domain(const char* domain);
char* find_key_in_hashtable(hashtable* table, char* domain);
int check_ip_valid(char* ip);
FILE* open_file(const char* file_name, const char* access);
int find_type_index(const char* str, const char* type);
int database_searching(char* key, char** domain, char** ip);
void add_in_database(const char* domain);
void hashtable_delete(hashtable* table, const char* key);
void tail_delete(node** head, node** tail);
void add_to_head(node** head, node** tail, char* key, char* value);
list* create_list();
list* insert_list(list* head, hashtable_object* object);
void prevent_collision(hashtable* table, int index, hashtable_object* object);
void add_to_hashtable(hashtable* table, node* node, char* key);
void insert_in_cache(cache* Cache, char* key, char* value);
char* find_ip_in_cache(cache* Cache, char* key, int mark);
void find_ip_by_domain(cache* Cache);
void print_cache(cache* Cache);

