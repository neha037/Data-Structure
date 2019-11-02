#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};
struct node* head;

void clist(int n);
void tlist();

int main()
{

    int n;
    printf("Enter the total number of nodes :");
    scanf("%d",&n);
    clist(n);
    tlist();

}

void clist(int n)
{
    struct node *newnode, *temp;
    int data,i;

    head = (struct node*)malloc(sizeof(struct node));

    if(head== NULL)
    {
        printf("unable to allocate memory");
        return;
    }

    //input data from user
    printf("\nEnter the data of node 1: ");
    scanf("%d",&data);

    head->data = data;
    head->link = NULL;

    //create n-1 nodes to the list
    temp = head;
    for(i=2;i<=n;i++)
    {
        newnode = (struct node*)(malloc(sizeof(struct node)));

        if(newnode == NULL)
        {
            printf("\nUnable to allocate memory");
        }

        printf("\nEnter the data of node %d :",i);
        scanf("%d",&data);
        newnode->data = data;
        newnode->link =NULL;

        temp->link = newnode;
        temp = temp->link;
    }

}

void tlist()
{
    struct node *temp;
    if(head ==NULL)
    {
        printf("\nList is Empty");
        return;
    }
    temp = head;
    printf("\nThe list is :");
    while(temp!= NULL)
    {
        printf("\nData = %d", temp->data);
        temp= temp->link;

    }

}

