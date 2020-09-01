#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data[20];
    struct node *next;
}*head,*temp,*newnode;
void display();
void createCircularLinkedlist()
{
    int i=1;
    while(i)
    {
         newnode=(struct node*) malloc(sizeof(struct node));
         printf("data\n");
        scanf("%s",newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        if(head!=NULL)
        {
            temp->next=newnode;
            temp=temp->next;
        }
        printf("enter 0 to exit\n");
        scanf("%d",&i);
    }
   temp->next=head;
}
int length()
{
    int l=1;
    temp=head;
    while(temp->next!=head)
    {
        l++;
        temp=temp->next;
    }
    return l;
}
void inserting()
{
    int i;
    int l=length();
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("data\n");
    scanf("%s",newnode->data);
    newnode->next=NULL;
     printf("Enter the location after which you want to insert the element\n");
     scanf("%d",&i);

    if(i<l)
    {

        temp=head;
        i=i-1;
        while(--i)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void display()
{
    temp=head;
    printf("%s ",temp->data);
    temp=temp->next;
    while(temp!=head)
    {
        printf("%s ",temp->data);
        temp=temp->next;
    }
}
void deleting()
{
    int i;
    int l=length();
    struct node *temp2;
    printf("enter the location to be deleted\n");
    scanf("%d",&i);
    temp=head;
    temp2=temp;
    temp2=temp2->next;
    if(i<=l)
    {
        i=i-1;
        while(--i)
        {
            temp2=temp2->next;
            temp=temp->next;

        }
        temp->next=temp2->next;
       free(temp2);
    }
}
void reverse()
{
    struct node *temp2,*temp3;
    temp=head;
    temp2=head;
    temp2=temp2->next;
    temp3=temp2;
    while(temp2!=head)
    {
        if(temp2->next==head)
        {
            head->next=temp2;
        }
        temp3=temp3->next;
        temp2->next=temp;
        temp=temp2;
        temp2=temp3;
    }
}
void choice()
{
    int cho,l,x=1;
     while(x)
     {
        printf("enter 1 for inserting node after a particular element\n");
        printf("enter 2 for deleting a particular element\n");
        printf("enter 3 for reversing \n");
        printf("enter 4 for displaying\n");
        printf("enter 5 to find the length\n");
        scanf("%d",&cho);


         switch(cho)
            {
                case 1:inserting();

                            display();
                            break;
                case 2:deleting();
                            display();
                            break;
                case 3:reverse();
                            display();
                            break;
                case 4:
                            display();
                            break;
                case 5:l=length();
                            printf("%d",l);
                            break;
                default:printf("wrong choice");
            }
           printf("press 0 to quit\n");
           scanf("%d",&x);
    }
}
int main()
{
    createCircularLinkedlist();
    choice();
    return 0;
}
