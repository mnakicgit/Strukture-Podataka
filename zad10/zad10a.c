//datoteka drzave.txt je u formatu:
//Drzava1 drzava1.txt
//Drzava2 drzava2.txt

//datoreke drzava su u formatu:
//Grad1, izmisljeni_broj_stanovnika   -- npr New York, 10000000
//Grad2, ...

//Zadatak pod a) lista stabala

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (50)

struct _cvorListe;
struct _cvorStabla;

typedef struct _cvorListe* PositionL;
typedef struct _cvorStabla* PositionS;

typedef struct _cvorListe
{
    char imeDrz[MAX_SIZE]; //ime drzave
    PositionS stablo; //pokazivac na stablo gradova
    PositionL next; //pokazivac na sljedecu drzavu u listi
} cvorListe;

typedef struct _cvorStabla
{
    char imeGr[MAX_SIZE]; //ime grada
    int br; //broj stanovnika
    PositionS left;
    PositionS right;
} cvorStabla;

int main()
{
    //ispisi drzave i gradove

    //pretraga gradova odredene drzave koji imaju vise stanovnika od unesenog
    return 0;
}
