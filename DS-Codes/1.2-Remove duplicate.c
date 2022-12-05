/******REMOVR THE DUPLICATE ELEMENTS FROM THE SORTED LINKED LIST******/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
}*head=NULL;
void insertfirst();
void display();
void sort();
void deleteduplicate();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert first and Dislay\n2.Sort\n3.Delete duplicate\n4.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insertfirst();
				display();
				break;
			case (2):
				sort();
				display();
				break;
			case (3):
				deleteduplicate();
				display();
				break;
			default:
				exit(0);
		}
	}
	//return 0;
	
}

void insertfirst()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted->:");
	scanf("%d",&data);
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

void sort()
{
	struct node *p,*s;
	int temp;
    for(p=head;p!=NULL;p=p->next)
    {
    	for(s=p->next;s!=NULL;s=s->next)
    	{
    		if(p->value>s->value)
    		{
    			temp=p->value;
    		    p->value=s->value;
    		    s->value=temp;
			}
    	}
	}
}

void deleteduplicate()
{
	struct node *p,*temp;
	p=head;
	if(head==NULL)
	{
		printf("There is no list");
	}
	else
	{
		while(p->next!=NULL)
		{
			if(p->value==p->next->value)
			{
				temp=p->next->next;
				free(p->next);
				p->next=temp;
		 	}
		 	else
		 	{
		 		p=p->next;
			}
	    }
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
