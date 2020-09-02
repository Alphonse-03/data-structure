#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*newnode;
void createLinkedList()
{
    int nos;
    head=NULL;
    head=temp;
    printf("enter the number of node\n");
    scanf("%d",&nos);
    while(nos>0)
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
        nos=nos-1;
    }
}
void bubbleSort()
{
    temp=head;
    int x;
    struct node *temp2;
    int l,i;
    for(l=1;temp->next!=NULL;temp=temp->next,l++);
    for(i=0;i<l;i++)
    {
    temp=head;
    temp2=temp->next;
    while(temp2!=NULL)
    {
        if(temp->data>temp2->data)
        {
            x=temp->data;
            temp->data=temp2->data;
            temp2->data=x;
            temp=temp->next;
            temp2=temp2->next;
        }
        else
        {
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    createLinkedList();
    bubbleSort();
    display();
    return 0;
}
