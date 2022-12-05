#include<stdio.h>
#include<conio.h>
int queue[10];
int front=0,rear=-1;
void enqueue()
{
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    if(rear==9&&rear==(front+1)%10)
        printf("Overflow");
    else
    {
        if(front!=0&&rear==9)
            rear=0;
        else
            rear=rear+1;
        queue[rear]=data;
    }
}
void dequeue()
{
    if(rear==-1&&front==0)
        printf("Underflow");
    else
    {
        printf("The dequeue element is %d",queue[front]);
        front+=1;
        if(front==10)
            front=0;
    }
}
void peek()
{
    if (rear==-1)
        printf("Queue is Empty");
    else
        printf("The Front Element is %d ",queue[front]);
}
void display()
{
    int i=front;
    printf("Queue Elements:");
    while(i!=rear)
    {
        printf("%d \t",queue[i]);
        i++;
        if(i==10)
            i=0;
    }
    printf("%d \t",queue[i]);
}
void main()
{
    int c;
    printf("\n IMPLEMENTATION OF QUEUE USING ARRAY \n1.Enqueue\n2.dequeue\n3.peek\n4.display\n5.Exit");
    do
    {
        printf("\nEnter Your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                break;
        }
    }while(c<=4);
    printf("Successfully Done!!!");
    getch();
}