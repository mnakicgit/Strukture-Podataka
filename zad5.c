#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE (50)

struct _Element;
typedef struct _Element* Position;
typedef struct _Element {
	double number;
	Position next;
} Element;


Position CreateElement(double number);
int InsertAfter(Position position, Position newElement);
int DeleteAfter(Position position);
int Push(Position head, double number);
int Pop(double* resultDestination, Position head); //redoslijed zbog konvencije
int DoOperation(Position head, char operation);
int ReadFileCalculatePostfix(double* resultDestionation, char* fileName);
int DeleteAll(Position head);



int main()
{
	double rezultat = 0;

    ReadFileCalculatePostfix("postfiks.txt", &rezultat);

    printf("Rezultat: %0.2lf\n", rezultat);

	return EXIT_SUCCESS;
}

Position CreateElement(double number)
{
	Position newElement = NULL;

	newElement = (Position)malloc(sizeof(Element));

	if(newElement == NULL)
	{
		perror("Greska pri alokaciji memorije.\n");
		return NULL;
	}

	newElement->number = number;
	newElement->next = NULL;

	return newElement;
}

int InsertAfter(Position position, Position newElement)
{
	newElement->next = position->next;
	position->next = newElement;

	return EXIT_SUCCESS;
}

int DeleteAfter(Position position)
{
	Position temp = position->next;

	if(temp == NULL)
	{
		return EXIT_SUCCESS;
	}

	position->next = temp->next;

	free(temp);
	return EXIT_SUCCESS;
}

int Push(Position head, double number)
{
	Position newElement = NULL;

	newElement = CreateElement(number);
	if(newElement == NULL)
	{
		return EXIT_FAILURE;
	}

	InsertAfter(head, newElement);

	return EXIT_SUCCESS;
}

int Pop(double* resultDestination, Position head)
{
	Position first = head->next;

	if(first == NULL)
	{
		perror("Greska pri citanju datoteke.\n");
		return EXIT_FAILURE;
	}

	*resultDestination = first->number; //derefenciranje, vrijednost na lokaciji
	DeleteAfter(head);

	return EXIT_SUCCESS;
}

int DoOperation(Position head, char operation)
{
    double rezultat = 0;
	double operand1 = 0;
	double operand2 = 0;


	Pop(&operand2, head);
    Pop(&operand1, head);

	switch(operation)
	{
	case '+':
        rezultat = operand1 + operand2;
		break;
	case '-':
		rezultat = operand1 - operand2;
		break;
	case '*':
		rezultat = operand1 * operand2;
		break;
	case '/':
		if (operand2 == 0)
		{
			perror("Dijeljenje s nulom nije dozvoljeno.\n");
			return EXIT_FAILURE;
		}
		rezultat = operand1 / operand2;
		break;
	default:
		printf("Nepostojeca operacija.\n\n");
		return EXIT_FAILURE;
	}

    Push(head, rezultat);

	return EXIT_SUCCESS;
}

int ReadFileCalculatePostfix(double* resultDestination, char* fileName)
{
	FILE* f = NULL;
	Element head = { .next = NULL, .number = 0 };
	char* buffer = NULL;
	char* currentBuffer = NULL;
	int fileLength = 0;
	int n = 0;
	int number = 0;
	char operation = 0;

	f = fopen(fileName, "rb"); //read binary!
	if(f == 0)
	{
		perror("Greska pri ucitavanju datoteke.\n");
		return EXIT_FAILURE;
	}

	fseek(f, 0, SEEK_END);
	fileLength = ftell(f);

	buffer = (char*)calloc(fileLength + 1, sizeof(char));
	if(buffer == NULL)
	{
		perror("Greska pri alokaciji memorije.\n");
		return -2;
	}

	rewind(f);
	fread(buffer, sizeof(char), fileLength, f);
	printf("%s\n", buffer);
	fclose(f);

	currentBuffer = buffer;

	while(strlen(currentBuffer) > 0)
	{
		sscanf(currentBuffer, " %lf %n", &number, &n);

        //kako znati je li broj ili operacija?
	}
	free(buffer);

    Pop(resultDestination, &head);

	if(head.next == NULL)
	{
		printf("Greska pri citanju datoteke.\n");
		DeleteAll(&head);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int DeleteAll(Position head)
{
	while(head->next != NULL)
	{
		DeleteAfter(head);
	}

	return EXIT_SUCCESS;
}
