//*********INSERT FIRST AND DISPLAY*********
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
}*head=NULL;
void insertfirst();
void display();

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
				display1();
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

void display1()
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
void display()
{
   int c=0;
   struct node *temp;
   while(temp!=NULL)
   {
        temp=temp->next;
		c+=1;
	}
	int n=c/2;
	int a=1;
	temp=head;
	while(a!=n)
	{
	    temp=temp->next;
		a+=1;
	}
	if(c%2==0)
	{
		printf(temp->value,temp->next->value);
	}
	    //printf(temp->data,temp->next->data);
	else
	{
		printf(temp->next->value);
	}
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int top = -1;
char stack[100];
 
// function prototypes
void push(char);
void pop();
void find_top();
 
void main()
{
	int i;
	char a[100];
	printf("enter expression\n");
	scanf("%s", &a);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{
			pop();
		}
	}
	find_top();
}
 
// to push elements in stack
void push(char a)
{
	stack[top] = a;
	top++;
}
 
// to pop elements from stack
void pop()
{
	if (top == -1)
	{
		printf("False\n");
		exit(0);
	}	
	else
	{		
		top--;
	}
}
 
// to find top element of stack
void find_top()
{
	if (top == -1)
		printf("\nTrue\n");
	else
		printf("\nFalse\n");
}*/
