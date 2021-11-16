#define _CRT_SECURE_NO_WARNINGS //obavezno prije include, da mos pokrenit program, inace zastita od malwarea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (50)
#define MAX_LINE (1024)

struct _Element; //Polinom preimenuj u Element
typedef struct _Element* Position;
typedef struct _Element
{
    int koef;
    int eksp;
    Position next;
} Element;

//polinomi u datoteci su zapisani na nacin ka ea kb eb... \n kx ex ky ey... (dva polinoma u svojim redovima, koeficijent pa eksponent)

int ProcitajDat(char* naziv_dat, Position head1, Position head2);
int SortiraniUnos(Position head, int koef, int eksp);
int IspisiPol(Position head);
int SrediListu(Position head);
int OslobodiListu(Position head);
int DodajElement(Position head, Position before);
Position NoviElement(int koef, int eksp);
int IzbrisiElementIza(Position before);
int ZbrojiPol(Position head1, Position head2, Position headZ);
int PomnoziPol(Position head1, Position head2, Position headU);

//ili umisto MergeAfter dodaj SrediListu, nakon sortiranog unosa svih elemenata sreduje polinom

//MergeAfter mi se cini bolji ali idem probat na svoj nacin

//MergeAfter (position position, newElement) - ako vec ne postoji, dodaj novi
//... if rezultantni koes == 0, deleteafter, free, else ako je isti, zbroji ih, free newElement

int main()
{
    Element Polinom1, Polinom2;
    Element zbrojPol, umnozakPol;
    Element headP1 = {.next = NULL, .koef = 0, .eksp = 0};
    Element headP2 = {.next = NULL, .koef = 0, .eksp = 0};
    Element headZ = {.next = NULL, .koef = 0, .eksp = 0};
    Element headU = {.next = NULL, .koef = 0, .eksp = 0};

    ProcitajDat("polinomi.txt", &headP1, &headP2);
    SrediListu(&headP1);
    SrediListu(&headP2);

    printf("Ucitani polinomi:\n");
    IspisiPol(&headP1.next);
    IspisiPol(&headP2.next);

    ZbrojiPol(&headP1, &headP2, &headZ);
    SrediListu(&headZ);

    printf("Zbroj polinoma:\n");
    IspisiPol(&headZ.next);

    PomnoziPol(&headP1, &headP2, &headU);
    SrediListu(&headU);

    printf("Umnozak polinoma:\n");
    IspisiPol(&headU.next);

    //OslobodiListu() ...

    return 0;
}

int ProcitajDat(char* naziv_dat, Position head1, Position head2)
{
    char buffer[MAX_SIZE] = {0};
    FILE* dat = NULL;
    dat = fopen("polinomi.txt", "r");

    if(dat == NULL)
    {
        printf("Greska pri otvaranju datoteke.\n");
        return EXIT_FAILURE;
    }

    fgets(buffer, MAX_LINE, dat);
    SpremiProcitanoUListu(head1, buffer);

    fgets(buffer, MAX_LINE, dat);
    SpremiProcitanoUListu(head2, buffer); //dva puta sprema polinom, saljes drugi head

    fclose(dat);
    return EXIT_SUCCESS;
}

int SpremiProcitanoUListu(Position head, char* buffer) //char* ?
{
    char* currentBuffer = buffer;
    int koef = 0, eksp = 0, n = 0;

    while(strlen(currentBuffer) > 0)
    {
        sscanf(buffer, " %d %d %n", &koef, &eksp, &n); //broj bajtova n
        currentBuffer += n;
        SortiraniUnos(head, koef, eksp);
    }

    return EXIT_SUCCESS;
}

int SortiraniUnos(Position head, int koef, int eksp)
{
    Position temp = head;

    while(temp->next != NULL && eksp > temp->next->eksp)
    {
        temp = temp->next;
    }

    Position element = NoviElement(koef, eksp);

    element->next = temp->next;
    temp->next = element;

    return EXIT_SUCCESS;
}

int SrediListu(Position head)
{
    Position p = head->next;
    Position before = head;

    while(p != NULL)
    {
        while(p->eksp == p->next->eksp)
        {
            p->koef += p->next->koef;
            IzbrisiElementIza(p);
        }

        if(p->koef == 0)
            IzbrisiElementIza(before); //ili funkcijama IzbrisiEl() i FindEl ili FindBefore
        p = p->next;
        before = before->next;
    }


    return EXIT_SUCCESS;
}

int IspisiPol(Position first) //oblik 123 x^(1) + 222 x^(2) + ...
{
    Position p = first;

    while(p != NULL)
    {
        if (p->next == NULL)
            printf("%d x^(%d)\n", p->koef, p->eksp);
        else
            printf("%d x^(%d) + ", p->koef, p->eksp);
        p = p->next;
    }

    return EXIT_SUCCESS;
}

int IzbrisiElementIza(Position before)
{
    Position toDelete = before->next;

    before->next = toDelete->next;
    free(toDelete);

    return EXIT_SUCCESS;
}

Position NoviElement(int koef, int eksp)
{
    Position element = NULL;

    element = (Position) malloc (sizeof(Element));
    if(element == NULL)
    {
        printf("Greska pri alociranju memorije!\n");
        return EXIT_FAILURE;
    }

    element->koef = koef;
    element->eksp = eksp;
    element->next = NULL;

    return element;
}

int ZbrojiPol(Position head1, Position head2, Position headZ)
{
    Position temp = NULL;
    Position i = head1->next;
	Position j = head2->next;
	Position k = headZ;

	while(i != NULL && j != NULL)
    {
        if(i->eksp == j->eksp)
        {
            SortiraniUnos(k, i->koef + j->koef, i->eksp);
            i = i->next;
			j = j->next;
        }
        else if(i->eksp < j->eksp)
        {
            SortiraniUnos(k, i->koef, i->eksp);
            i = i->next;
        }
        else
		{
			SortiraniUnos(k, j->koef, j->eksp);
			j = j->next;
		}
    }

    if (i == NULL)
	{
		temp = j;
	}
	else
	{
		temp = i;
	}

	while (temp != NULL) //prepisuje ostatak elemenata
    {
		SortiraniUnos(k, temp->koef, temp->eksp);
		temp = temp->next;
	}

    return EXIT_SUCCESS;
}

int PomnoziPol(Position head1, Position head2, Position headU)
{
    Position i = head1->next;
	Position j = head2->next;

	while(i != NULL)
    {
        while(j != NULL)
        {
            SortiraniUnos(headU, i->koef * j->koef, i->eksp * j->eksp);
        }
    }

    return EXIT_SUCCESS;
}
