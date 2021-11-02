#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (50)

struct _Person; //obavezno
typedef struct _Person* Position; //pazi na *
typedef struct _Person
{
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    int birthYear;
    Position next;
} Person;

int PrependList(Position head, char* name, char* surname, int birthYear); //dodavanje na pocetak
int PrintList(Position first);
Position CreatePerson(char* name, char* surname, int birthYear);
int InsertAfter(Position position, Position newPerson);
Position FindLast(Position head);
int AppendList(Position head, char* name, char* surname, int birthYear); //dodavanje na kraj
Position FindPerson(Position first , char * surname);
Position FindBefore(Position position, char* surname);
int DeleteAfter(char* surname, Position head);
int InsertPersonAfter(Position head, Position newPerson, char* surname);
int InsertPersonBefore(Position head, Position newPerson, char* surname);
int InsertSort(Position head, Position newPerson); //sortirani unos
int SaveToFile(char* naziv_dat, Position first);

int main(int argc, char** argv) //argument count, argument variables(niz nizova tj matrica tj niz stringova)
{
	Person head = {.next = NULL, .name = {0}, .surname = {0}, .birthYear = 0};
	Position p = &head;

	int odabir = 0;
	char ime[MAX_SIZE] = {0};
	char prezime[MAX_SIZE] = {0};
	int god = 0;

	printf("Vezana lista osoba je prazna.\n");

	while(odabir != 0)
	{
		printf("\nOdaberi:\n 1 Dodaj osobu na pocetak\n 2 Dodaj osobu na kraj\n 3 Izbrisi osobu iz liste\n 4 Pronadi osobu\n 5 Isprintaj listu\n 6 Unesi iza osobe\n 7 Unesi ispred osobe\n 8 Upisi listu u datoteku\n 9 Procitaj listu iz datoteke\n 0 Izadi iz programa\n\nUpisi broj:");
		scanf(" %d",&odabir);

		switch(odabir)
		{
			case 1:
				printf("Unesi ime, prezime i godinu rodenja: ");
				scanf("%s %s %d", &ime, &prezime, &god);
				PrependList(p, ime, prezime, god);
				break;
			case 2:
				printf("Unesi ime, prezime i godinu rodenja: ");
				scanf("%s %s %d", &ime, &prezime, &god);
				AppendList(p, ime, prezime, god);
				break;
			case 3:
				printf("Prezime osobe koju zelis izbrisati: ");
				scanf("%s", &prezime);
				DeleteAfter(prezime, p);
				break;
			case 4:
				printf("Prezime osobe koju zelis pronaci (case sensitive): ");
				scanf("%s", &prezime);
				Position temp = FindPerson(p, prezime);
				printf("%s %s %d",temp->name, temp->surname, temp->birthYear);
				break;
			case 5:
				PrintList(p);
				break;
            case 6:
                printf("Unesi ime, prezime i godinu rodenja: ");
				scanf("%s %s %d", &ime, &prezime, &god);
				InsertPersonAfter(p, )
			case 0:
				printf("Kraj programa");
				break;
			default:
				printf("Krivi unos!\n");
		}
	}

	return EXIT_SUCCESS;
}

int PrependList(Position head, char* name, char* surname, int birthYear) //dodavanje na pocetak
{
    Position newPerson = NULL;

    newPerson = CreatePerson(name, surname, birthYear);


    strcpy(newPerson->name, name);
    strcpy(newPerson->surname, surname);
    newPerson->birthYear = birthYear;
    newPerson->next = NULL;

    InsertAfter(head, newPerson);

    return EXIT_SUCCESS;
}

int PrintList(Position first)
{
    Position temp = first->next;

	printf("Lista:\n");
    while(temp)
    {
        printf("Name: %s, surname: %s, birth year: %d\n", temp->name, temp->surname, temp->birthYear);
        temp = temp->next;
    }
	/*
    for(Position temp = first; temp != NULL; temp = temp->next;)
    {
        printf("Name: %s, surname %s, ""birth year: %d\n", temp->name, temp->surname, temp->firstYear");
        temp = temp->next;
    }
    */

    return EXIT_SUCCESS;
}

Position CreatePerson(char* name, char* surname, int birthYear)
{
    Position newPerson = NULL;

    newPerson = (Position)malloc(sizeof(Person));
    if(!newPerson)
    {
        perror("Cant allocate memory!\n"); //pristupa varijabli koja sadrzi error code zadnje greske, nema formatiran ispis - samo string
        return -1;
    }
	strcpy(newPerson->name, name);
	strcpy(newPerson->surname, surname);
	newPerson->birthYear = birthYear;
	newPerson->next = NULL;

	return newPerson;
}

int InsertAfter(Position position, Position newPerson)
{
    newPerson->next = position->next;
    position->next = newPerson;

    return EXIT_SUCCESS;
}

Position FindLast(Position head)
{
    Position temp = head;

    while(temp->next)
    {
        temp = temp->next;
    }

    return temp;
}

int AppendList(Position head, char* name, char* surname, int birthYear) //dodavanje na kraj
{
    Position newPerson = NULL;
    Position last = NULL;

    newPerson = CreatePerson(name, surname, birthYear);
    if(!newPerson)
    {
		return -1;
    }
	last = FindLast(head);
	InsertAfter(last, newPerson);

}

Position FindPerson(Position first , char* surname)
{
	Position temp = first;

	while(temp)
	{
		if(strcmp(temp->surname, surname) == 0) //strcmp moze usporedivati i >, <, abecedno
		{
			return temp; //break;
		}
		temp = temp->next;
	}
	return temp; //NULL
}


Position FindBefore(Position position, char* surname) {
    Position prev = NULL;
    prev = position;
    position = position->next;

    while(position)
    {
        if(strcmp(position->surname, surname) == 0)
        {
            prev = position;
            position = position->next;
        }
    }
    if(position == NULL) return NULL;
    else return prev;
}


int DeleteAfter(char* surname, Position head) {
    Position before = head;
	Position toDelete = before->next;
	int flag = 0;

	while(toDelete != NULL)
	{
		if(strcmp(toDelete, surname) == 0)
		{
			toDelete = before->next;
			before->next = toDelete->next;
			free(toDelete);
			flag = 1;
			break;
		}
	}

    if (flag == 0) {
		printf("Osoba ne postoji.\n");
	}

	return EXIT_SUCCESS;
}

int InsertPersonAfter(Position head, Position newPerson, char* surname)
{
    Position InsertingAfter = FindPerson(head, surname);

    InsertAfter(InsertingAfter, newPerson);

    return EXIT_SUCCESS;
}

int InsertPersonBefore(Position head, Position newPerson, char* surname)
{
    Position InsertingBefore = FindPerson(head, surname);
    Position before = FindBefore(head, surname);

    InsertAfter(before, newPerson);
}

int InsertSort(Position head, Position newPerson) //sortirani unos
{
    Position position = head;

    while (p->next != NULL && strcmp(p->next->surname, newPerson->surname) < 0)
        position = position->next;

    InsertAfter(position, newPerson);

    return EXIT_SUCCESS;
}

int SaveToFile(char* naziv_dat, Position first)
{
    Position position = first;

    FILE* f = NULL;
    f = fopen(naziv_dat, "w");

    if(f == NULL)
    {
        printf("Greska pri upisu!");
        return EXIT_FAILURE;
    }

    for(position = first->next; position != NULL; position = position->next)
        fprintf(f, "%s %s %d\n", position->name, position->surname, position->birthYear);

    fclose(f);
    return EXIT_SUCCESS;
}
