#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	struct node *next;
}*head=NULL;
void insertlast();
void display();
void print_alter();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert and Dislay\n2.Display\n3.Print Alternate\n4.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insertlast();
				display();
				break;
			case (2):
				display();
				break;
			case (3):
				print_alter();
				display();
				break;
			default:
				exit(0);
		}
	}
	return 0;
}

void insertlast()
{
	int data;
	struct Node *p;
	struct Node *Newnode;
	Newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value to be inserted->:");
	scanf("%d",&data);
	Newnode->value=data;
	Newnode->next=NULL;
	if(head==NULL)
	{
		head=Newnode;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		     p=p->next;
		p->next=Newnode;
	}
}

void display()
{
	struct Node *p;
	p=head;
	while(p->next!=NULL)
	{
		printf("%d->",p->value);
		p=p->next;
	}
     printf("%d",p->value);  
}

void print_alter()
{
	int count=0;
	while(head!=NULL)
	{
		if(count%2==0)
		{
			printf("%d\t",head->value);
	    }
		count++;
		head=head->next;
	}
}
