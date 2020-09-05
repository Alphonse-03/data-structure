/* not in working condition needs some modification if the testcase has duplicate at the last index then it returns a NULL */ 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*temp,*temptemp,*temp2,*newnode,*temp3;
void createll()
{
    int n;
    head=NULL;
    temp=head;
    printf("enter the length of linkedlist\n");
    scanf("%d",&n);
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
}
int length()
{
    int l=1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        l++;
    }
    return l;
}
int deletenode(int n)
{
     int l=length();
     if(n<l)
     {
        temptemp=head;
        temp2=temptemp->next;
        n=n-1;
        while(--n)
        {
            temptemp=temptemp->next;
            temp2=temp2->next;
        }
        temptemp->next=temp2->next;
        temp2->next=NULL;
     }
     else
     {
         temptemp=head;
         n=n-1;
         while(--n)
         {
             temptemp=temptemp->next;
         }
         free(temptemp->next);
         temptemp->next=NULL;

     }
     return 0;
}
void removeDuplicates()
{
    temp=head;
    int i;
    temp3=temp->next;
   // while(temp!=NULL)
    //{
        i=2;
       while(temp3!=NULL)
        {
            if(temp->data==temp3->data)
            {
                temp3=temp3->next;
               deletenode(i);
            }
            else
            {
                    temp3=temp3->next;
            }
            i++;
        }
        temp=temp->next;
        temp3=temp->next;
    //}
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main()
{
    createll();
    removeDuplicates();
    display();
    return 0;
}
