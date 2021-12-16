#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct stablo* Position;
typedef struct stablo
{
    char name[100];
    Position sibling;
    Position child;
} Stablo;

typedef struct stog* PositionStog;
typedef struct stog
{
    Position el;
    PositionStog next;
} Stog;

Position Insert(Position current, Position q);  //md
Position PrintChildren(Position parent);    //dir (ls u Linux Terminalu i Powershellu)

int main()
{
    return 0;
}

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

Position PrintChildren(Position parent)
{
    Position P = parent->child; //first
}

int Push(Position current, PositionStog HeadStog)
{
    PositionStog newEL = NULL;
    PositionStog temp = HeadStog;

    newEl = (PositioStog)malloc(sizeof(Stog));
    if(newEl == NULL))
    {
        printf("Greska pri alokaciji, neuspjesan push na stog");
        return 1;
    }


}











