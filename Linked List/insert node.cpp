#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head;

void clist(int n);
void tlist();
void ibegg();
void imid();

int main()
{
    int n,c;
    printf("Enter the number of nodes in the List :");
    scanf("%d", &n);
    clist(n);
    printf("Enter your choice :\n 0. Exit\n 1. Print List\n 2. Insert Element at the begninning\n 3. Insert Element at any given position\n");
    scanf("%d", &c);
    while(c != 0)
    {
        switch (c)
        {
            case 1: tlist();
                    break;
            case 2:ibegg();
                    tlist();
                    break;
            case 3:imid();
                    tlist();
                    break;
            default: printf("Enter correct choice");
        }
        printf("Enter your choice :\n 0. Exit\n 1. Print List\n 2. Insert Element at the begninning\n 3. Insert Element at any given position\n");
         scanf("%d", &c);   
    }
    return 0;
}

void clist(int n)
{
    int data,i;
    struct node *temp,*newnode;
    head = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data in node 1 : ");
    scanf("%d", &data);
    head->data = data;
    head->link = NULL;
    temp = head;
    for(i=2;i<=n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data in node %d : ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->link = NULL;
        temp->link = newnode;
        temp = temp->link;
    }
}

void tlist()
{
    int i;
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("Data : %d\n", temp->data);
        temp= temp->link;
    }
}

void ibegg()
{
    int data;
    struct node *newnode;
    printf("Enter data for new node: ");
    scanf("%d", &data);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->link = head;
    head = newnode;
}

void imid()
{
    int data,pos;
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position to insert new data: ");
    scanf("%d", &pos);
    printf("\nEnter the data in node :");
    scanf("%d", &data);
    newnode->data = data;
    temp=head;
    for(int i = 2; i<pos; i++)
    {
        temp = temp->link;
        if(temp==NULL)
            break;
    }
    if(temp != NULL)
    {
        newnode->link = temp->link;
        temp->link = newnode;
    }
    else
    {
       printf("Unable to insert at the given position\n");
    }
}
