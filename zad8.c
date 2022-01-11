#include <stdio.h>
#include <stdlib.h>

struct _cvor;
typedef struct _cvor* Position;
typedef struct _cvor
{
    int data;
    Position left;
    Position right;
}cvor;

Position Insert(Position p, int broj);
Position CreateElement(int broj);
int InorderIspis(Position root);
int PreorderIspis(Position root);
int PostorderIspis(Position root);
Position DeleteEl(Position root, int toDelete);
int FindEl(Position root, int toFind);

int main()
{
    Position root = NULL;

    int odabir = -1;
    int el = 0;

    while(odabir != 0)
    {
        printf("\nOdaberi:\n 1 Ubaci element u stablo\n 2 Ispisi stablo inorder\n 3 Ispisi stablo preorder\n 4 Ispisi stablo postorder\n 5 Izbrisi element iz stabla\n 6 Pronadi element\n 0 Exit\n");

        scanf("%d", &odabir);

        switch(odabir)
		{
			case 1:
				printf("Upisi broj koji zelis ubaciti:\n");
                scanf("%d", &el);
                root = Insert(root, el);
				break;
			case 2:
                printf("Elementi stabla inorder:\n");
                InorderIspis(root);
				break;
			case 3:
                printf("Elementi stabla preorder:\n");
                PreorderIspis(root);
				break;
			case 4:
                printf("Elementi stabla postorder:\n");
                PostorderIspis(root);
				break;
			case 5:
                printf("Upisi broj koji zelis izbrisati:\n");
                scanf("%d", &el);
                DeleteEl(root, el);
				break;
            case 6:
                printf("Upisi broj koji zelis pronaci:\n");
                scanf("%d", &el);
                FindEl(root, el);
                break;
			case 0:
				printf("Kraj programa");
				break;
			default:
				printf("Krivi unos!\n");
		}

    }

    return 0;
}

Position Insert(Position p, int broj)
{
    Position noviEl = CreateElement(noviEl);

    if(p == NULL)
        return noviEl;

    else if(p->data < noviEl->data)
        p->right = Insert(p->right,noviEl);

    else if(p->data > noviEl->data)
        p->left = Insert(p->left,noviEl);

    else
    {
        free(noviEl);
        return p;
    }

    return p;

    return NULL;
}

Position CreateElement(int broj)
{
	Position newElement = NULL;

	newElement = (Position)malloc(sizeof(cvor));

	if(newElement == NULL)
	{
		printf("Greska pri alokaciji memorije.\n");
		return NULL;
	}

	newElement->data = broj;
	newElement->right = NULL;
	newElement->left = NULL;

	return newElement;
}

int InorderIspis(Position root)
{
    printf("\n");
    if (root)
	{
		InorderIspis(root->left);
		printf("%d ", root->data);
		InorderIspis(root->right);
	}

    return 0;
}

int PreorderIspis(Position root)
{
    return 0;
}

int PostorderIspis(Position root)
{
    return 0;
}

Position DeleteEl(Position root, int toDelete)
{
    return NULL;
}

int FindEl(Position root, int toFind)
{
    return 0;
}
