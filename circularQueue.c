#include <stdio.h>
#include <stdlib.h>
#define N 5
int front=-1,rear=-1;
int queue[5];
void enqueue()
{
    int n;
    printf("enter the character\n");
    scanf("%d",&n);
    if(rear==-1)
    {
        queue[++rear]=n;
        front++;
    }
    else if((rear==N-1 && front==0)||(front-rear)==1)
    {
        printf("overflow\n");
    }
    else if(rear>-1 && rear<N-1)
    {
        queue[++rear]=n;
    }
    else if(rear>-1&&rear==N-1&&front!=0)
    {
        rear=0;
        queue[rear]=n;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("nothing to delete\n");
    }
    if(front>-1&&front<N-1 && front!=rear)
    {
        front++;
    }
    if(front==N-1 && rear<front)
    {
        front=0;
    }
    if(front==rear)
    {
        front=rear=-1;
    }

}
void display()
{
    int i;
    printf("your output\n");
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d  ",queue[i]);
        }
    }
    else
    {
        for(i=front;i<=N-1;i++)
        {
            printf("%d  ",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d  ",queue[i]);
        }
    }

    for(i=0;i<4;i++)
    {
        printf("\n");
    }
    for(i=0;i<=4;i++)
    {
        printf("%d",queue[i]);
    }
    printf("\n");
}
void peek()
{
    printf("peeked value      %d",queue[front]);
    printf("\n");
}
int main()
{
    int cho;
    do
    {
        printf("enter 1 for enqueue\n");
        printf("enter 2 for dequeue\n");
        printf("enter 3 for display\n");
        printf("enter 4 for peek\n");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1:enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
               break;
            case 4:peek();
                break;
            default: exit(0);
        }
    } while(1);
    return 0;
}
