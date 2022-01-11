#include <stdio.h>
#include <stdlib.h>

typedef struct cvor* Pozicija;
struct cvor
{
    int data;
    Pozicija left;
    Pozicija right;
};

Pozicija Insert(int, Pozicija);
Pozicija Alociraj(int);
int Replace(Pozicija);

int main()
{
    Pozicija root = NULL;

    root = Insert(2, root); //insert ne stvara bin. stablo pretrazivanja nego kao na slici, vidi zadatak
    root = Insert(5, root);
    root = Insert(7, root);
    root = Insert(8, root);
    root = Insert(11, root);
    root = Insert(1, root);
    root = Insert(4, root);
    root = Insert(2, root);
    root = Insert(3, root);
    root = Insert(7, root);

    return 0;
}

Pozicija Insert(int broj, Pozicija root) //rekurzija!!
{
	if (root == NULL)
		return Alociraj(broj);
	else if (broj >= root->data)
		root->left = Insert(broj, root->left);
    else if (broj < root->data)
		root->right = Insert(broj, root->right);

	return root;
}

Pozicija Alociraj(int broj)
{
    Pozicija noviCvor = NULL;
    noviCvor = (Pozicija)malloc(sizeof(struct cvor));

    if(noviCvor == NULL)
    {
        printf("Greska pri alokaciji.\n");
        return NULL;
    }

    noviCvor->data = broj;
    noviCvor->left = NULL;
    noviCvor->right = NULL;

    return noviCvor;
}

int Replace(Pozicija root) //uufffffffffffweghilawguo
{

    return 0;
}

int OtvoriDatPozoviSpremanje(Pozicija root, char* imeDat) //??
{
    FILE* dat = NULL;
	dat = fopen(imeDat, "w");

    if(dat != NULL) 
    {
        //SpremiInorder 
    }
    else
    {
        printf("Greska pri otvaranju datoteke.\n");
        return 1;
    }

    return 0;
}