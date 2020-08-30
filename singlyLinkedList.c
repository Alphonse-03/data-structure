#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    char data[20];
    struct data *next;
}*head,*tail,*temp,*newnode,*temp2,*temp3;

void createSingleNode()
{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the value\n");
        scanf("%s",newnode->data);
        newnode->next=NULL;
}

void createLinkedlist()
{
    int t=1;
    head=NULL;
    while(t)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the value\n");
        scanf("%s",newnode->data);
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
        printf("enter anything other than 0 to continue\n");
        scanf("%d",&t);
    }
}
int lenght()
{
    temp=head;
    int c=1;
    if(head->next!=NULL)
    {
        c++;
    }
    return c;
}
void display();
void addBeg()
{
   createSingleNode();
    newnode->next=head;
    head=newnode;
}
void addLas()
{
     createSingleNode();
     temp=head;
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=newnode;
}
void addRan()
{
    int loc,c;
    printf("enter the location\n");
    scanf("%d",&loc);
    if(loc>c)
    {
        printf("location is exceding the size of the likedlist.\n adding the value as the last node.......\n");
        addLas();
    }
    else
    {
        createSingleNode();
     temp=head;
     loc=loc-1;
     while(--loc)
     {
         temp=temp->next;
     }
     temp2=temp->next;
     temp->next=newnode;
     newnode->next=temp2;
    }

}
void delBeg()
{
    temp=head;
    head=head->next;
    free(temp);
}
void delLas()
{
     temp=head;
     temp2=temp->next;
     while(temp2->next!=NULL)
     {
         temp2=temp2->next;
         temp=temp->next;
     }
     temp->next=NULL;
     free(temp2);
}
void delRan()
{
    int loc;
    int c=lenght();
    printf("enter the location\n");
    scanf("%d",&loc);
    if(loc>c)
    {
        printf("no element found at the particular location.\n please check the location any try again :D\n");
    }
    else{

temp=head;
     temp2=temp->next;
     loc=loc-1;
     while(--loc)
     {
         temp2=temp2->next;
         temp=temp->next;
     }
     temp->next=temp2->next;
     free(temp2);    }

}
void reverse()
{
    temp=head;
    head=head->next;
    temp2=head;
    temp3=head;
    temp->next=NULL;
    while(head->next!=NULL)
    {
        temp3=temp2;
        temp2=temp2->next;

         head->next=temp;
        head=temp2;
        temp=temp3;
    }
    head->next=temp;
}


void choice()
{
    int cho,c;
    printf("enter 1 for inserting a node at Beginning\n");
    printf("enter 2 for inserting a node at Last\n");
    printf("enter 3 for inserting a node at a given location\n");
    printf("enter 4 for deleting a node at beginning\n");
    printf("enter 5 for deleting a node at Last\n");
    printf("enter 6 for deleting a node from a given location\n");
    printf("enter 7 for reversing the node\n");
    printf("enter 8 to find the length of the linkedlist\n");
    printf("enter 9 for displaying the linkedlist\n");
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
        case 7:reverse();
                      display();
                      break;
        case 8:c=lenght();
                printf("length of the node is %d",c);
                      break;
        case 9:display();
                      break;
       default:printf("wrong choice please check your option\n");
  }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%s ",temp->data);
        temp=temp->next;
    }
    printf("\n")
}
int main()
{
    int cho=1;
    createLinkedlist();

    while(cho)
    {
        system("cls");
         choice();
         printf("press 0 to quit\n");
    scanf("%d",&cho);
    }

    return 0;
}
