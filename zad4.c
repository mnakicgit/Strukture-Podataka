#define _CRT_SECURE_NO_WARNINGS //obavezno prije include, da mos pokrenit program, inace zastita od malwarea
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE (50)
#define MAX_LINE (1024)

struct _Polinom; //Polinom preimenuj u Element
typedef struct _Polinom* Position;
typedef struct _Polinom 
{
    int koef;
    int eksp;
    Position next;
} Polinom;

//polinomi u datoteci su zapisani na nacin ka ea kb eb... \n kx ex ky ey... (dva polinoma u svojim redovima, koeficijent pa eksponent)

int ProcitajDat(char* naziv_dat, Polinom head1, Polinom head2);
int SortiraniUnos(Polinom head1, Polinom head2, int koef1, int koef2, int eksp1, int eksp2);

//MergeAfter (position position, newElement) - ako vec ne postoji, dodaj novi
//... if rezultantni koes == 0, deleteafter, free, else ako je isti, zbroji ih, free newElement

int main()
{
    Polinom Polinom1, Polinom2;
    Polinom head1 = {.next = NULL, .koef = 0, .eksp = 0};
    Polinom head2 = {.next = NULL, .koef = 0, .eksp = 0};



    return 0;
}

int ProcitajDat(char* naziv_dat, Polinom head)
{
    char buffer[MAX_SIZE] = {0}; //dodaj current buffer 
    int n = 0;
    FILE* dat = NULL;
    dat = fopen("polinomi.txt", "r");

    if(dat == NULL)
    {
        printf("Greska pri otvaranju datoteke.\n");
        return -1;
    }

    fgets(buffer, MAX_LINE, dat);

    while(n < MAX_LINE)
    {
        sscanf(buffer, " %d %d %n", &koef, &eksp, &n); //broj bajtova n
    }

    //dva puta, saljes drugi head

    //free(& )

    return 0;
}

int SortiraniUnos(Position head, int koef, int eksp)
{
    Polinom temp = head;

    while(temp->next != NULL && eksp < temp->next->eksp)
    {
        if 
    }

    return 0;
}