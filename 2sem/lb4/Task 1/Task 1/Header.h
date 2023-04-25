#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_MAX_VALUE 255
#define MARKER "-1"

typedef struct Tree
{
    char Word[STR_MAX_VALUE];
    struct Tree* Left;
    struct Tree* Right;
} Tree;

char* trim_start(char* str);
char* trim_end(char* str);
Tree* deserialize_tree(FILE* Input);
void serialize_tree(Tree* Root, FILE* Output);
Tree* Create_Node(Tree* Left, Tree* Right, char* str);
void edit_tree(Tree* Root);
void akinator(Tree* Root);
