#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
};
struct node *front=NULL,*rear=NULL;
void dequeue();
void enqueue();
void peek();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert and Dislay\n2.Delete\n3.Show First Value In Stack\n4.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				enqueue();
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

void enqueue()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted->:");
	scanf("%d",&data);
	newnode->value=data;
	newnode->next=NULL;
	if(front==NULL&&rear==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	struct node *temp;
	if(front==NULL&&rear==NULL)
	   printf("There isno node to display");
	else
	{
		temp=front;
		front=temp->next;
		free(temp);
	}

}
void peek()
{
	struct node *temp;
	if(front==NULL&&rear==NULL)
	   printf("There isno node to display");
	temp=front;
	printf("%d",front->value);
}

void display()
{
	struct node *p;
	//p=front;
	if(front==NULL&&rear==NULL)
	   printf("There isno node to display");
    else
    {
        p=front;
	    while(p->next!=NULL)
	    {
            printf("%d--",p->value);
		    p=p->next;
	     }
         printf("%d",p->value);  
     }
}
