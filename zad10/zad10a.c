//datoteka drzave.txt je u formatu:
//Drzava1 drzava1.txt
//Drzava2 drzava2.txt

//datoteke drzava su u formatu:
//Grad1, izmisljeni_broj_stanovnika   -- npr New York, 10000000
//Grad2, ...

//Zadatak pod a)  lista stabala

//Drzave nesortirane, gradovi po broju stanovnika pa adbecedno

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

int LoadCountries(char* dat, PositionL head);
int InsertCountry(PositionL head, PositionL noviEl, char* datGradovi);
int CreateAndLoadTree(char* datGradovi, PositionL drzava);
PositionS InsertCity(PositionS root, PositionS noviEl);
PositionL CreateCountry(char* ime);
PositionS CreateCity(char* ime, int br);


int main()
{
    //ispisi drzave i gradove

    //pretraga gradova odredene drzave koji imaju vise stanovnika od unesenog

    PositionL head;

    int LoadCountries("drzave.txt", &head);

    return 0;
}

int LoadCountries(char* dat, PositionL head)
{
    FILE* dat = NULL;
    char buffer[MAX_SIZE] = {0};
    char imeDr[MAX_SIZE] = {0};
    char imeDat[MAX_SIZE] = {0};
    PositionS root = NULL;

    dat = fopen(dat, "r");

    if(dat == NULL)
    {
        printf("Greska pri otvaranju datoteke.\n");
        return 1;
    }

    while(!feof)
    {
        fgets(buffer, MAX_SIZE, dat);
        sscanf(buffer, " %s %s", imeDr, imeDat); //fscanf za datoteke, sscanf za string
        InsertCountry(head, CreateCountry(imeDr);
    }

    fclose(dat);

    return 0;
}

int InsertCountry(PositionL head, PositionL noviEl, char* datGradovi) //nesortirano unosi na kraj liste
{
    PositionL p = head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = noviEl;
    noviEl->next = NULL;

    CreateAndLoadTree(datGradovi, noviEl);

    return 0;
}

int CreateAndLoadTree(char* datGradovi, PositionL drzava)
{
    FILE* dat = NULL;

    dat = fopen(datGradovi, "r");


}

PositionS InsertCity(PositionS root, PositionS noviEl) //root se mijenja zbog rekurzije
{
    if(root == NULL)
        return noviEl;
    else if(noviEl->br > root->br) //sortirani unos po br stanovnika
        root->right = InsertCity(root->right, noviEl);
    else if(noviEl->br < root->br)
        root->left = InsertCity(root->left, noviEl);
    else if(noviEl->br == root->br) //pa abecedno
    {
        if(strcmp(noviEl->imeGr, root->imeGr) < 0)
            root->left = InsertCity(root->left, noviEl);
        else
            root->right = InsertCity(root->right, noviEl);
    }

    return root;
}

PositionL CreateCountry(char* ime)
{
    PositionL drzava = NULL;

    drzava = (PositionL)malloc(sizeof(cvorListe));

    if(drzava == NULL)
    {
        printf("Greska pri alokaciji elementa liste.\n");
        return NULL;
    }

    strcpy(drzava->imeDrz, ime);
    drzava->next = NULL;
    drzava->stablo = NULL;

    return drzava;
}

PositionS CreateCity(char* ime, int br)
{
    PositionS grad = NULL;

    grad = (PositionS)malloc(sizeof(cvorStabla));

    if(grad == NULL)
    {
        printf("Greska pri alokaciji elementa stabla.\n");
        return NULL;
    }

    strcpy(grad->imeGr, ime);
    grad->br = br;
    grad->right = NULL;
    grad->left = NULL;

    return grad;
}

