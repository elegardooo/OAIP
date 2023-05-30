#include "Header.h"

void Marks(char* str, int i, FILE* file)
{
	switch (str[i])
	{
	case '.':
		fprintf(file, ".");
		break;
	case ',':
		fprintf(file, ",");
		break;
	case ' ':
		fprintf(file, " ");
		break;
	case '-':
		fprintf(file, "-");
	case ':':
		fprintf(file, ":");
		break;
	case ';':
		fprintf(file, ";");
		break;
	}
}

Dictionary* Fill_Structure(FILE* Dictionary_txt, int *DictianoryCount)
{
	Dictionary* dictionary = (Dictionary*)calloc(1, sizeof(Dictionary));
	int WordNum = 0;
	char* str;
	str = (char*)calloc(4096, sizeof(char));
	char* word = (char*)calloc(1, sizeof(char));
	while ((fgets(str, 4096, Dictionary_txt)) != NULL)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ' ')
			{
				word[WordNum] = '\0';
				strcpy_s(dictionary[*DictianoryCount].DictionaryWord, WORD_MAX_LENGTH, word);
				WordNum = 0;
			}
			else
				if (str[i] == '\0' || str[i] == '\n')
				{
					word[WordNum] = '\0';
					strcpy_s(dictionary[*DictianoryCount].TranslationWord, WORD_MAX_LENGTH, word);
					WordNum = 0;
				}
				else
				{
					word[WordNum] = str[i];
					word = (char*)realloc(word, (WordNum + 2) * sizeof(char));
					WordNum++;
				}
		}
		(*DictianoryCount)++;
		dictionary = (Dictionary*)realloc(dictionary, (*DictianoryCount + 2) * sizeof(Dictionary));
	}
	return dictionary;
}

void Decompressing(FILE* File_txt, Dictionary* dictionary, int DictionaryCount)
{
	FILE* DecompressedFile_txt;
	char* str = (char*)calloc(4096, sizeof(char));
	char* word = (char*)calloc(1, sizeof(char));
	int DictionaryIndex = 0, WordNum = 0;
	fopen_s(&DecompressedFile_txt, "DecompressedFile.txt", "w");
	while (fgets(str, 4096, File_txt) != NULL) 
	{
		for (int i = 0; i < (strlen(str)); i++) {
			if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n' || str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == ':') 
			{
				word[WordNum] = '\0';
				for (DictionaryIndex = 0; DictionaryIndex < DictionaryCount; DictionaryIndex++) 
				{
					//printf("%d     ", DictionaryIndex);
					if (strcmp(dictionary[DictionaryIndex].TranslationWord, word) == 0) 
					{
						fprintf(DecompressedFile_txt, "%s", dictionary[DictionaryIndex].DictionaryWord);
						Marks(str, i, DecompressedFile_txt);
						break;
					}
					else
						if (strcmp(dictionary[DictionaryIndex].DictionaryWord, word) == 0) 
						{
							fprintf(DecompressedFile_txt, "%s", dictionary[DictionaryIndex].TranslationWord);
							Marks(str, i, DecompressedFile_txt);
							break;
						}
				}
				if (strcmp(dictionary[DictionaryIndex].TranslationWord, word) != 0 && strcmp(dictionary[DictionaryIndex].DictionaryWord, word) != 0) 
				{
					fprintf(DecompressedFile_txt, "%s", word);
					Marks(str, i, DecompressedFile_txt);

				}
				WordNum = 0;
			}
			else 
			{
				word[WordNum] = str[i];
				word = (char*)realloc(word, (WordNum + 2) * sizeof(char));
				WordNum++;
			}
		}
		fprintf(DecompressedFile_txt, "\n");
	}
	fclose(DecompressedFile_txt);
	free(str);
}