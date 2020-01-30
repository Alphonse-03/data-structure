#include <stdio.h>
#include<conio.h>
#include<malloc.h>
void display();
struct student
{
    int r;
    char name[20];
    struct student *next;
}*fresh,*temp,*start,*last,*tempo,*tempo2,*prev;
struct student *new_node()
{
    printf("enter the roll and name\n");
    temp=(struct student *)malloc(sizeof(struct student));
    scanf("%d %s",&temp->r,temp->name);
    temp->next=NULL;
    return temp;
}
void add_beg()
{
	fresh=new_node();
	clrscr();
    if(fresh==NULL)
    {
	printf("NULL");
    }
    else
    {
    fresh->next=start;
    start=fresh;
    }
}
void add_las()
{
	fresh=new_node();
	clrscr();
    if(fresh==NULL)
    {
	printf("NULL");
    }
    else if(start!=NULL)
    {
	for(last=start;last->next!=NULL;last=last->next);
	last->next=fresh;
	last=fresh;
    }
	else
    {
     //	printf("roll\t%d\nname\t%s",temp->r,temp->name);  \
      start=temp;
    }
}
void rem_beg()
{
	clrscr();
	if(start==NULL)
	{
		printf("LINKLIST EMPTY\n");
	}
	else
	{
		start=start->next;
		display();
	}
}
void rem_las()
{
	clrscr();
	if(start==NULL)
	{
		printf("LINKLIST EMPTY\n");
	}
	if(start->next==NULL)
	{
		rem_beg();
	}
	else
	{
		for(last=start->next,tempo=start;last->next!=NULL;last=last->next,tempo=tempo->next);
		{
			tempo->next=NULL;
			display();
		}
	}
}
void rem_tran()
{
	int val;
	printf("enter the roll to be deleted\n");
	scanf("%d",&val);
	if(val==start->r)
	{
		rem_beg();
	}
	else
	temp=start->next;
	while(temp->r==val)
	{
	       /*	for(tempo=temp->next,prev=start;;tempo=tempo->next,prev=prev->next);
		tempo2=tempo->next;
		prev->next=tempo2;  */
		tempo=temp->next;
		prev=start;
		prev->next=tempo;
		tempo=tempo->next;
		prev=start->next;
		temp=temp->next;
	}
}
void add_tran()
{
	int pos,i;
	fresh=new_node();
	clrscr();
    if(fresh==NULL)
    {
	printf("NULL");
    }
   else if(start==NULL)
   {
	printf("roll\t%d\nname\t%s",temp->r,temp->name);
   }
    else
    {
	printf("enter the position\n");
	scanf("%d",&pos);
	for(tempo=start,i=0;i<pos-1;tempo=tempo->next,i++);
	tempo2=tempo->next;
	tempo->next=fresh;
	tempo=fresh;
	fresh->next=tempo2;
    }
}
void display()
{
    for(temp=start;temp!=NULL;temp=temp->next)
    {
	printf("roll\t%d\nname is\t%s\n",temp->r,temp->name);
    }
}
 void main()
{
    int cho;
    clrscr();
     for(;1;)
    {
    printf("enter 1 for inserting from beginning \n");
    printf("enter 2 for adding at any position\n");
    printf("enter 3 for inserting from last\n");
    printf("enter 4 for deleting first node\n");
    printf("enter 5 for deleting any node\n");
    printf("enter 6 for deleting last node\n");
    printf("enter anything except 1,2,3,4,5,6 for terminating the program\n");
    scanf("%d",&cho);
    switch(cho)
    {
	case 1:
	    add_beg();
	    display();
	    break;
	case 2:
	    add_tran();
	    display();
	    break;
	case 3:
	    add_las();
	    display();
	    break;
	case 4:
	    rem_beg();
      //	    display();
	    break;
	case 5:
	   rem_tran();
	    display();
	    break;
	case 6:
	    rem_las();
	   // display();
	    break;
	default:exit(0);
	    break;
    }
    if(cho!=3&&cho!=2&&cho!=1&&cho!=4&&cho!=5&&cho!=6)
    {
    break;
    }
    }
    getch();
}




