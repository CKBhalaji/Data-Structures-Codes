/******ADD ONE TO DOUBLY LINKED LIST******/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int value;
	struct node *next;
}*head=NULL;

void insertfirst();

void insertfirst()
{
	int data;
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to insert-->:");
	scanf("%d",&data);
	newnode->value=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	    head=newnode;
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}

void display()
{
	struct node *p;
	p=head;
	while(p->next!=NULL)
	{
		printf("%d<->",p->value);
		p=p->next;
	}
     printf("%d",p->value);  
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert first and Dislay\n2.Display\n3.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insertfirst();
				display();
				break;
			case (2):
				display();
				break;
			case (3):
				exit(0);
		}
	}
	return 0;
}


