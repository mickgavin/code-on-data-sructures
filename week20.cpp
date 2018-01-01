#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct result
{
	int ID;
	char surname[20];
	char firstname[20];
	char english, maths, french, philosophy;
	struct result *next;
};

struct result *first;

void printMenu();

void writeData();
void readData();
void findRecord(int recordNumber);


void  main(void)
{
	int id;

	writeData();
	readData();

	do
	{
		printf("Enter which ID you want: ");
		scanf_s("%d", &id);
		findRecord(id);
	} while (id != 0);

}


void writeData()
{
	FILE *fp;
	int i = 0, j;

	struct result results[] = { { 137, "Elsie", "Barton", 'A', 'A', 'B', 'A' },{ 108, "Hazel", "Bender", 'A', 'B', 'A', 'A' },{ 102, "Paige", "Chen", 'D', 'D', 'A', 'D' },{ 101, "Kristina", "Chung", 'D', 'B', 'B', 'A' } };

	fp = fopen("F:\\results.dat", "wb+");

	for (j = 0; j<4; j++)
	{
		fwrite(&results[j], sizeof(result), 1, fp);
	}

	fclose(fp);

}

void readData()
{

	FILE *fp;

	struct result *last = NULL;
	struct result *current = NULL;


	fp = fopen("F:\\results.dat", "rb+");


	while (!feof(fp))
	{
		if (first == NULL)
		{
			first = (struct result *)malloc(sizeof(struct result));
			first->next = NULL;
			current = first;
		}
		else
		{
			last = (struct result *)malloc(sizeof(struct result));
			current->next = last;
			current = last;
			last->next = NULL;
		}

		fread(current, sizeof(result), 1, fp);
	}

	fclose(fp);



}

void findRecord(int id)
{
	struct result *current;

	current = first;

	while (current != NULL)
	{
		if (current->ID == id)
		{
			printf(" student info:%d %s %s maths(%c) English(%c) French(%c) Philsophy(%c) \n", id, current->surname, current->firstname, current->english, current->maths, current->french, current->philosophy);
			return;
		}
		current = current->next;
	}

}