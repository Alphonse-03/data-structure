#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data[1];
    struct node *next;
}*head,*temp,*newnode,*temp2;


void createLinkedlist()
{
    int n;
    head=NULL;
    temp=head;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    while(n--)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("enter the value\n");
        scanf("%s",newnode->data);

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
}
void vowelconsonents()
{
    char x[1];
    temp=head;
    temp2=temp->next;
    if(temp->data[0]=='a'||temp->data[0]=='e'||temp->data[0]=='i'||temp->data[0]=='o'||temp->data[0]=='u')
    {
        temp=temp->next;
        temp2=temp2->next;
    }
    while(temp2!=NULL)
    {
        if(temp2->data[0]=='a'||temp2->data[0]=='e'||temp2->data[0]=='i'||temp2->data[0]=='o'||temp2->data[0]=='u')
        {
            x[0]=temp->data[0];
            temp->data[0]=temp2->data[0];
            temp2->data[0]=x[0];
            temp=temp->next;
            temp2=temp2->next;
        }
        else
        {
            temp2=temp2->next;
        }
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%s",temp->data);
        temp=temp->next;
    }
}
int main()
{
    createLinkedlist();
    vowelconsonents();
    display();
    return 0;
}



