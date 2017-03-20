#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char firstName[50];
	char lastName[50];
	long id;
	char english, french, maths, philosophy;
} result;

result *results[100];
int numResults = 0;

int readFile(char *fileName);
void initialiseResults();
void printResult(result *aResult);

int main()
{
	char fileName[] = "F:\\Downloads\\Results.txt";
	int i = 0;

	void initialiseResults();

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}

	printf("%6s%12s%12s%12s%12s%12s%12s\n", "I.D.", "First Name", "Last Name", "English", "French", "Maths", "Philosophy");
	while (results[i] != NULL)
	{
		printResult(results[i]);
		i++;
	}

	return 0;
}

void printResult(result *aResult)
{
	printf("%6d%12s%12s%12c%12c%12c%12c\n", aResult->id, aResult->firstName, aResult->lastName, aResult->english, aResult->maths, aResult->french, aResult->philosophy);
}

void initialiseResults()
{
	int i;
	for (i = 0; i < 100; i++)
		results[i] = NULL;
}

int readFile(char *fileName)
{
	FILE *file;
	char string[100];

	fopen_s(&file, fileName, "r");
	fgets(string, 100, file);
	while (!feof(file)) {
		results[numResults] = (result*)malloc(sizeof(result));
		fscanf(file, "%d\t%s\t%s\t%c\t%c\t%c\t%c\n", (&(results[numResults])->id), ((results[numResults])->firstName), ((results[numResults])->lastName), (&(results[numResults])->english), (&(results[numResults])->maths), (&(results[numResults])->french), (&(results[numResults])->philosophy));
		numResults++;
	}
	fclose(file);
	return 1;
}