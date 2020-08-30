#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    char data[20];
    struct node *next;
    struct node *prev;
}*head,*tail,*temp2,*temp,*newnode;

void createDoubleLinkedList()
{
    int t=1;
    head=NULL;
    while(t)
    {
        newnode=(struct node*) malloc(sizeof(struct node));
        printf("enter the value\n");
        scanf("%s",newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        printf("enter 0 to quit and any other integer to continue\n");
        scanf("%d",&t);
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%s  ",temp->data);
        temp=temp->next;
    }
}
void createOneNode()
{
        newnode=(struct node*) malloc(sizeof(struct node));
        printf("enter the value\n");
        scanf("%s",newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
}
void addBeg()
{
    createOneNode();
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
int length()
{
    int i=0;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;
}
void addLas()
{
    createOneNode();
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
}
void addRan()
{
    int pos,l;
    l=length();
    createOneNode();
    printf("enter the position where you want your node\n");
    scanf("%d",&pos);
    if(pos>l)
    {
        printf("The length of the linked list is less than given postion.\nAdding the node at last......\n");
        addLas();
    }
    else
    {
        temp=head;
        while(--pos)
        {
            temp=temp->next;
        }
        newnode->prev=temp->prev;
        newnode->next=temp;
        temp->prev->next=newnode;
    }
}
void delBeg()
{
  temp=head;
  head=head->next;
  head->prev=NULL;
  free(temp);
}
void delLas()
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    tail=temp;
    temp->prev->next=NULL;
    free(tail);
}

void delRan()
{
    int loc,l;
    l=length();
    temp=head;
    printf("enter the location\n");
    scanf("%d",&loc);
    if(loc>l)
    {
        printf("location doesnot exists...\n please try again\n");
    }
    else
    {
        while(--loc)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void reverse()
{
    temp2=head;
    temp=temp2;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            head=temp;
        }
        temp=temp->next;
        temp2->next=temp2->prev;
        temp2->prev=temp;
        temp2=temp;
    }
}

void choice()
{
    int cho,l;
    printf("Enter 1 for adding element at beginning\n");
    printf("Enter 2 for adding element at end\n");
    printf("Enter 3 for adding element at random position\n");
    printf("Enter 4 for deleting element at beginning\n");
    printf("Enter 5 for deleting element at end\n");
    printf("Enter 6 for deleting element at random position\n");
    printf("Enter 7 for finding the lenght\n");
    printf("Enter 8 for reversing\n");
    printf("Enter 9 for displaying the linkedlist\n");
    scanf("%d",&cho);
    switch(cho)
        {
            case 1:addBeg();
                      display();
                      break;
             case 2:addLas();
                      display();
                      break;
             case 3:addRan();
                      display();
                      break;
            case 4:delBeg();
                      display();
                      break;
             case 5:delLas();
                      display();
                      break;
            case 6:delRan();
                      display();
                      break;
             case 7:l=length();
                    printf("length of the Linkedlist is %d",l);
                      break;
            case 8:reverse();
                      display();
                      break;
            case 9:;display();
                      break;
            default:printf("wrong choice\n");
        }
}
int main()
{
    int cho;

    createDoubleLinkedList();
    while(cho)
    {
        choice();
        printf("enter 0 to exit \n");
        scanf("%d",&cho);
    }

    return 0;
}
