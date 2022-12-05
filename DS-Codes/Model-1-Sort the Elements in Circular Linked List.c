#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int value;
	struct node *next;
}*head=NULL;

void insert();

void insert()
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
	{
	    head=newnode;
	    newnode->next=head;
	    newnode->prev=head;
	}
	else
	{
		p=head;
		while(p->next!=head)
		   p=p->next;
		newnode->next=p->next;
		newnode->prev=p;
		p->next=newnode;
	}
}

void display()
{
	struct node *p;
	p=head;
	while(p->next!=head)
	{
		printf("%d<->",p->value);
		p=p->next;
	}
     printf("%d",p->value);  
}

void remove_dup()
{
	struct node *p,*q,*temp=NULL,*dummy=NULL;
	p=head;
	while(p->next!=head)
	{
		q=p->next;
		while(q->next!=head)
		{
			if(p->value==q->value)
			{
				temp=q;
				dummy=q->next;
				q->prev->next=q->next;
				q->next->prev=q->prev;
				free(temp);
				q=dummy;
			}
			else
			{
				q=q->next;
			}
		}
		p=p->next;
	}
}

int main()
{
	int ch;
	printf("\n1.Insert first and Dislay\n2.Remove Duplicates\n3.Display\n4.Exit");
	while(1)
	{
		printf("\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insert();
				display();
				break;
			case (2):
				remove_dup();
				display();
				break;
			case (3):
				display();
				break;
			case (4):
				exit(0);
		}
	}
	return 0;
}

