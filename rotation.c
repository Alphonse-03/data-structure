#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*newnode,*tail;


void createLinkedlist()
{
    int n=5;
    head=NULL;
    temp=head;
    tail=head;
    while(n--)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the value\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }
    tail=temp;
}
void rotation()
{
    int r;
    temp=head;
    printf("enter the rotation value\n");
    scanf("%d",&r);
    while(r--)
    {
        head=head->next;
        tail->next=temp;
        temp->next=NULL;
        tail=tail->next;
        temp=head;
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    createLinkedlist();
    rotation();
    display();
    return 0;
}
