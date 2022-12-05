/******REMOVE ELEMENTS AT Kth POSITION IN DOUBLY LINKED LIST******/
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
void removekthpos();

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
	    head=newnode;
	else
	{
		p=head;
	    while(p->next!=NULL)
	    	p=p->next;
		p->next=newnode;
		newnode->prev=p;
	}
}

void removekthpos()
{
	int pos,kpos;
	struct node *p;
	if(head==NULL)
	    printf("**NO ELEMENT TO REMOVE**");
	else
	{
		printf("Enter the position to remove::");
		scanf("%d",&kpos);
		p=head;
		pos=1;
		while(kpos!=pos)
		{
			p=p->next;
			pos++;
		}
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
	}
}

void display()
{
	struct node *p;
	p=head;
	while(p->next!=NULL)
	{
		printf("%d->",p->value);
		p=p->next;
	}
     printf("%d",p->value);  
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert and Dislay\n2.Remve the element in kth pos\n3.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insert();
				display();
				break;
			case (2):
				removekthpos();
				display();
				break;
			case (3):
				exit(0);
		}
	}
	return 0;
}


