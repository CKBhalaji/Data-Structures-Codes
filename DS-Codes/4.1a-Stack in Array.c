/*******Implimentation Of Stack Using Linked List*******/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
}*head=NULL;

void push();
void pop();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert first and Dislay\n2.Delete\n3.Display First Element\n4.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				push();
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

void push()
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

void pop()
{
	struct node *temp;
	if(head==NULL)
	   printf("There isno node to display");
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
	}

}

void peek()
{
	struct node *temp;
	temp=head;
	printf("%d",temp->value);
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
