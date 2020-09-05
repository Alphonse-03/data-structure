#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*newnode,*tail,*temptail;


void createLinkedlist()
{
    int n;
    head=NULL;
    temp=head;
    tail=head;
    printf("enter the number of nodes\n");
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
    tail=temp;
}
int length()
{
    int l=0;
    temp=head;
    while(temp->next!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}
void palindromell()
{
   int c=0;
   int l=length();
   int i=l/2;
   temp=head;
   temptail=head;
   while(i--)
   {
       if(temp->data!=tail->data)
       {
           c=1;
           break;
       }
       else
       {
           temp=temp->next;
           while(temptail->next!=tail)
           {
               temptail=temptail->next;
           }
           tail=temptail;
           temptail=head;
       }
   }
   if(c==0)
   {
       printf("palindrome\n");
   }
   else
   {
       printf("not palindrome");
   }
}

int main()
{
    createLinkedlist();
    palindromell();
    return 0;
}
