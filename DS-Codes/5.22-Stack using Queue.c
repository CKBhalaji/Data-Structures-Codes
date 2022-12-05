#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int Q[100];
int front=0;
int rear=-1;

int main()
{
	int ch,n;
	printf("\nEnter the number of elements in Queue-->:");
    scanf("%d",&n);
    printf("\n1.Insert and Dislay\n2.Delete\n3.Show First Value In Stack\n4.Exit\n");
	while(1)
	{
		printf("\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				push(n);
				display();
				break;
			case (2):
				pop();
				display();
				break;
			case (3):
				peek();
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}

void push(int n)
{
	int data,s;
	s=n;
	printf("Enter Data-->:");
	scanf("%d",&data);
	enqueue(data,s);
}

void enqueue(int data,int n)
{
	if(rear==n-1)
	{
		printf("Queue Is Full");
	}
	else
	{
		rear++;
		Q[rear]=data;
	}
}

void pop()
{
	dequeue();
}

void dequeue()
{
	printf("%d",Q[front]);
	front=front+1;
}

void peek()
{
	printf("First Element-->:||%d||",Q[front]);
}

void display()
{
	int i;
	printf("\nElements in Queue-->:\n");
	for(i=front;i<=rear;i++)
	{
		printf("\n||%d||",Q[i]);
		printf("\n-----");
	}
}

