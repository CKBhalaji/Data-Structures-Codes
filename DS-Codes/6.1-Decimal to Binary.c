/******Decimal to binary convertor******/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
}*head=NULL;

void bintodec();
void push(int data);
void display();
void pop();

int main()
{
	int ch;
	while(1)
	{
		printf("\nEnter the choice\n1.Binary To Decimal Convertor\n2.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				bintodec();
				display();
				pop();
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
void bintodec()
{
	int n,s,t;
	printf("\nEnter Number  to convert to Decimal-->:");
	scanf("%d",&n);
	while(1)
	{
		s=n%2;
		push(s);
		n=n/2;
		if(n==1)
		{
			push(n);
			break;
		}
	}
}
void push(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void pop()
{
	struct node *temp;
	while(1)
	{
		if(head==NULL)
		{
		    break;
	    }
		else
		{
			temp=head;
			head=temp->next;
			free(temp);
		}
	}
}
void display()
{
	struct node *p;
	p=head;
	printf("The converted elements-->:\n");
	while(p->next!=NULL)
	{
		printf("%d\t",p->value);
		p=p->next;
	}
     printf("%d",p->value);  
}










