#include <stdio.h>
#include <string.h>

typedef struct stablo* Position;
typedef struct stablo
{
    char name[100];
    Position sibling;
    Position child;
} Stablo;

typedef struct stog* PositionStog; //stog sluzi za pamcenje parent direktorija
typedef struct stog
{
    Position el;
    PositionStog next;
} Stog;

int Push(Position current, PositionStog HeadStog);  //push i pop s pocetka
Position Pop(PositionStog HeadStog); 
Position ChangeToParent(PositionStog HeadStog); //vraca se u direktorij iznad
int PrintDirectory(Position current);   //dir (ls u Linux Terminalu i Powershellu), ispisuje djecu
Position ChangeDirectory(Position current, char* name); //ulazi u poddirektorij
Position Insert(Position current, Position q);  //md  
//Position MakeDirectory(Position current, char* name); //md

int main()
{
    return 0;
}

int Push(Position current, PositionStog HeadStog)
{
    PositionStog newEl = NULL;
    PositionStog temp = HeadStog;

    newEl = (PositioStog)malloc(sizeof(Stog));
    if(newEl == NULL))
    {
        printf("Greska pri alokaciji, neuspjesan push na stog");
        return 1;
    }

    newEl->el = current;
    newEl->next = HeadStog->next; //push na pocetak
    HeadStog->next = newEl;

    return 0;
}

Position Pop(PositionStog HeadStog)
{
    if(HeadStog->next == NULL)
        return NULL;

    Position toPop = HeadStog->next; //pop s pocetka
    Position parent = toPop->el;
    HeadStog->next = toPop->next;
    free(toPop);
    return parent;
}

int PrintDirectory(Position current)
{
    if(current->child == NULL)
        printf("This directory is empty.\n");
    else
    {
        current = current->child;
        while(current != NULL)
        {
            printf("%s\n", current->name);
            current = current->sibling;
        }
    }

    return 0;
}

Position ChangeToParent(PositionStog HeadStog)
{
    return Pop(HeadStog);
}

Position ChangeDirectory(Position current, char* name)
{
    if(current->child == NULL)
    {
        printf("Cannot change directory.\n") //nema poddirektorija? (subdirectory?)
        return current;
    }
    else
    {
        current = current->child;
        while(strcmp(current->name, name != NULL) //vraca 0 ako su jednaki
            current = current->sibling;
        
        return current;
    }
}

/*
Position MakeDirectory(Position current, char* name)
{
    Position newDir = NULL;

    newDir = (Position)malloc(sizeof(Stablo));
    if(newDir == NULL)
    {
        printf("Greska pri alokaciji memorije za direktorij.\n");
        return 1;
    }

    current = current->child;
    while(current->sibling != NULL)
        current = current->sibling;
    
    current->sibling = newDir;
    newDir->sibling = NULL;
    strcpy(newDir->name, name);
    return newDir;
}
*/
Position Insert(Position current, Position q)
{
    if(current == NULL)
        return q;
    if(strcmp(current->name, q->name) > 0)      //sortirani unos
    {
        q->sibling = current;
        return q;
    }
    else if(strcmp(current->name, q->name) < 0)
    {
        current->sibling = Insert(current->sibling, q);     //rekurzija!
    }
    else
    {
        printf("A directory or file with that name already exists.\n");
        free(q);
        return current;
    }
}