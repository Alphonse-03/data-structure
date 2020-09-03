#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head1,*head2,*temp1,*temp2,*newnode1,*newnode2,*tail,*temp3;

void ll1()
{
    int n;
    head1=NULL;
        temp1=head1;
    printf("enter the length\n");
    scanf("%d",&n);
    while(n--)
    {
        newnode1=(struct node*) malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode1->data);
        newnode1->next=NULL;
        if(head1==NULL)
        {
            head1=newnode1;
            temp1=head1;
        }
        else
        {
            temp1->next=newnode1;
            temp1=temp1->next;
        }
    }
}
void ll2()
{
     int n;
    head2=NULL;
        temp2=head2;
    printf("enter the length\n");
    scanf("%d",&n);
    while(n--)
    {
        newnode2=(struct node*) malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode2->data);
        newnode2->next=NULL;
        if(head2==NULL)
        {
            head2=newnode2;
            temp2=head2;
        }
        else
        {
            temp2->next=newnode2;
            temp2=temp2->next;
        }
    }
}
void unionll()
{
    int c=0;
    tail=head1;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    temp1=head1;
    temp2=head2;
    while(temp2!=NULL)
    {
        c=0;
        while(temp1!=NULL)
        {
            if(temp2->data==temp1->data)
            {
                c=1;
                break;
            }
            else
            {
                temp1=temp1->next;
            }
        }
        if(c==0)
        {
            tail->next=temp2;
            temp3=temp2;
            temp2=temp2->next;
            temp3->next=NULL;
            tail=tail->next;
            temp1=head1;
        }
        if(c==1)
        {
            temp3=temp2;
            temp2=temp2->next;
            temp3->next=NULL;
            temp1=head1;
        }
    }
}

void print()
{
    temp1=head1;
    while(temp1!=NULL)
    {
        printf("%d  ",temp1->data);
        temp1=temp1->next;
    }
}

int main()
{
    ll1();
    ll2();
    unionll();
    print();
    return 0;
}
