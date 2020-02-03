#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct dll
{
	int roll;
	char name[20];
	struct dll *next;
	struct dll *prev;
}*start,*last,*fresh,*temp;
struct dll * new_node()
{
	temp=(struct dll*)malloc(sizeof (struct dll));
	printf("enter the roll and name\n");
	scanf("%d%s",&temp->roll,temp->name);
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void add_beg()
{
	fresh=new_node();
	if(start==NULL)
	{
		start=fresh;
		last=fresh;

	}
	else
	{
		fresh->next=start;
		start->prev=fresh;
		start=fresh;
	}
}
void add_las()
{
	fresh=new_node();
	if(start==NULL)
	{
		start=fresh;
		last=fresh;
	}
	else
	{
		last->next=fresh;
		fresh->prev=last;
		last=fresh;
	}
}
void add_trans()
{
	int pos,i;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(start==NULL)
	{
		start=fresh;
		last=fresh;
	}
	if(pos!=0)
	{
		fresh=new_node();
		for(i=1,temp=start;i<pos-1;i++,temp=temp->next);
		fresh->prev=temp;
		fresh->next=temp->next;
	      temp->next->prev=fresh;
		temp->next=fresh;
	}
	else if(pos==0)
	{
		fresh=new_node();
		fresh->next=start;
		start->prev=fresh;
		start=fresh;

	}
}
int rem_beg()
{
	int c;
	start=start->next;
	start->next->prev=NULL;
	if(start==NULL)
	{
		c=0;
	}
	return c;
}
int rem_las()
{
	int c;
       for(temp=start;temp->next!=NULL;temp=temp->next);
	 last->prev->next=NULL;
	 last=last->prev;
	if(temp==start)
       {
	rem_beg();
	return c=0;
	}
}
int rem_trans()
{
	int i,p,c,l;
	printf("enter the node positon to be deleted");
	scanf("%d",&p);
	for(temp=start,l=1;temp->next!=NULL;l++,temp=temp->next);
	if(p>l)
	{
		c=1;
	}
	for(temp=start,i=1;i<p;temp=temp->next,i++);
	if(temp==start)
	{
		rem_beg();
	}
	else{
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;}
	return c;
}
void dis()
{
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		printf("%s\n",temp->roll,temp->name);
	}
}
int main()
{

	int cho,x;
	clrscr();
	do
	{
		printf("enter 1 for inserting node from beginning\n");
		printf("enter 2 for inserting node from last\n");
		printf("enter 3 for inserting node from transversal\n");
		printf("enter 4 for deleting a node from beginning\n");
		printf("enter 5 for deleting a node from last\n");
		printf("enter 6 for deleting a node from transversal\n");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:clrscr();
				add_beg();
				clrscr();
				dis ();
				break;
			case 2: clrscr();
				add_las();
				clrscr();
				dis ();
				break;
			case 3: clrscr();
				add_trans ();
				clrscr();
				dis ();
				break;
			case 4: clrscr();
				x=rem_beg();
				if(x==0)
				{
					printf("linklist empty\n");
				}
				clrscr();
				dis ();
				break;
			case 5: clrscr();
				x=rem_las();
				clrscr();
				if(x==0)
				{
					printf("linklist empty \n");
				}
				else{
				dis (); }
				break;
			case 6: clrscr();
				x=rem_trans ();
				if(x==1)
				{
					printf("the position is beyond the lenght of the linklist\n");
				}
				else{
				dis();}
				break;
			default: exit(0);

		}
	}
	while(cho>0);
	return 0;
}


