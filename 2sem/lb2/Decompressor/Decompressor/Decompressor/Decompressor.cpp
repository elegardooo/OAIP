#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


#define WORD_MAX_LENGTH 50



int main()
{
	Dictionary* dictionary;
	FILE* File_txt = fopen("CompressedFile.txt", "r+");
	FILE* Dictionary_txt = fopen("1Dictionary.txt", "r+");
	if (File_txt == NULL)
	{
		perror("File open error");
		exit(1);
	}
	if (Dictionary_txt == NULL)
	{
		perror("File open error");
		exit(1);
	}
	int DictionaryCount = 0;
	dictionary = Fill_Structure(Dictionary_txt, DictionaryCount);
	fclose(Dictionary_txt);
	Decompressing(File_txt, dictionary, DictionaryCount);
	fclose(File_txt);
	printf("File is decompressed.");
	free(dictionary);

}
