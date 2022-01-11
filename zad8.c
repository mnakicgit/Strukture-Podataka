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

Position Insert(Position root, Position noviEl);
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
                root = Insert(root, CreateElement(el));
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
                if(FindEl(root, el))
                    printf("Broj se nalazi u stablu.\n");
                else
                    printf("Broj se NE nalazi u stablu.\n");
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

Position Insert(Position root, Position noviEl)
{
    if(root == NULL)
        return noviEl;

    else if(root->data < noviEl->data)
        root->right = Insert(root->right,noviEl);

    else if(root->data > noviEl->data)
        root->left = Insert(root->left,noviEl);

    else
    {
        free(noviEl);
        return root;
    }

    return root;
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

int InorderIspis(Position root) //samo mijenjas di je printf
{
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
    if (root)
	{
	    printf("%d ", root->data);
		InorderIspis(root->left);
		InorderIspis(root->right);
	}
    return 0;
}

int PostorderIspis(Position root)
{
    if (root)
	{
		InorderIspis(root->left);
		InorderIspis(root->right);
		printf("%d ", root->data);
	}
    return 0;
}

Position DeleteEl(Position root, int toDelete)
{
    Position temp = NULL;

    if(!root)
        return root;

    if(root->data == toDelete)
    {
        if(root->left)
        {
            temp = root->left;
            while(temp->right)
            {
                temp = temp->right;
            }
            temp->left = root->left;
            temp->right = root->right;
        }
        else if(root->right)
        {
            temp = root->right;
            while(temp->left)
            {
                temp = temp->left;
            }
            temp->left = root->left;
            temp->right = root->right;
        }
        root->right = NULL;
        root->left = NULL;
        free(root);
        printf("Element je izbrisan.\n");
        return temp;
    }
    if(root->data < toDelete)
        root->right = DeleteEl(root->right, toDelete);
    else
        root->left = DeleteEl(root->left, toDelete);


}

int FindEl(Position root, int toFind)
{
    if(!root)
        return 0;
    if(root->data == toFind)
        return toFind;
    else if(root->data < toFind)
        return FindEl(root->right, toFind);
    else if(root->data > toFind)
        return FindEl(root->left, toFind);
    else
        return 0;
}
