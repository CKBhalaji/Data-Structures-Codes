#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void dequeue();
void peek();
void display();

int Q[100];
int front=0;
int rear=-1;

int main()
{
	int ch,n;
	printf("\nEnter the number of elements in Queue-->:");
    scanf("%d",&n);
    //printf("\n1.Insert and Dislay\n2.Delete\n3.Show First Value In Stack\n4.Exit\nEner choice::");
	while(1)
	{
		printf("\n1.Insert and Dislay\n2.Delete\n3.Show First Value In Stack\n4.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				enqueue(n);
				display();
				break;
			case (2):
				dequeue();
				display();
				break;
			case (3):
				peek();
				//display();
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}

int enqueue(int n)
{
	int data;
	printf("Enter Element-->:");
	scanf("%d",&data);
	if(rear==n-1)
	{
        printf("\nQueue is FULL");
     }
    else
    {
	    rear++;
	    Q[rear]=data;
    }
}
void dequeue()
{
     printf("%d",Q[front]);
	 front=front+1;
}

void display()
{
	int i;
	printf("\nThe elements are-->:\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",Q[i]);
	}
}

void peek()
{
	printf("\nFirst Element in Stack Is %d",Q[front]);
}
