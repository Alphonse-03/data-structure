#include<stdio.h>
#include<conio.h>
int tos;
struct element
{
	float ul;
	float ll;
	int f;
}stack[20];
void push()
{
	int i;
	float d1,d2;
	printf("enter the number of elements\n");
	scanf("%d",&tos);
	for(i=0;i<tos;i++)
	{
		printf("enter the upper limit,Lower Limit,Frequency\n");
		scanf("%f%f%d",&d1,&d2,&stack[i].f);
		stack[i].ul=d1;
		stack[i].ll=d2;
	}
}
float CalMean()
{
	int j;
	float x,fx=0.0,sf=0.0;
	float mean=0.0;
	for(j=0;j<tos;j++)
	{
		x=(stack[j].ul+stack[j].ll)/2.0;
		fx=x*stack[j].f+fx;
		sf=sf+stack[j].f;
	}
	mean=fx/sf;
	return mean;
}
float FindMedian()
{
	int k,i=0;
	float sf=0.0,N,L,fc=0.0,h;
	float median;
	for(k=0;k<tos;k++)
	{
		sf=sf+stack[k].f;
	}
	N=sf/2.0;
	while(N>0)
	{
		if(N-stack[i].f>=0)
		{
			N=N-stack[i].f;
			fc=fc+stack[i].f;
			i++;
		}
		else
		{
			N=-1;
		}
	}
	L=stack[i].ll;
	h=stack[i].ul-stack[i].ll;
	median=L+(((sf/2.0)-fc)/stack[i].f)*h;
	return median;
}
void mode()
{
	float mn,md,mo;
	mn=CalMean();
	md=FindMedian();
	mo=(3*md)-(2*mn);
	printf("MODE=> %f",mo);
}
void main()
{
	int cho;
	float mean,median;
	clrscr();
	printf("enter 1 for mean \n");
	printf("--------------------\n");
	printf("enter 2 for median \n");
	printf("--------------------\n");
	printf("enter 3 for mode \n");
	printf("--------------------\n");
	printf("enter 4 for all the operations \n");
	printf("--------------------\n");
	scanf("%d",&cho);
	switch(cho)
	{
		case 1:
		clrscr();
		push();
		mean=CalMean();
		printf("mean => %f",mean);
		getch();
		break;
		case 2:
		clrscr();
		push();
		median=FindMedian();
		printf("median => %f",median);
		getch();
		break;
		case 3:
		clrscr();
		push();
		mode();
		getch();
		break;
		case 4:
		push();
		mean=CalMean();
		median=FindMedian();
		printf("mean => %f",mean);
		printf("median => %f",median);
		mode();
		getch();
		getch();
		break;
	}
}



