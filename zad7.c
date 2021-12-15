#include <stdio.h>
#include <string.h>

typedef struct CvorStabla* Position;
struct CvorStabla 
{
    int name;
    Position sibling;
    Position child;
};

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