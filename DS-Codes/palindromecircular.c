#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
}*head=NULL;
typedef struct node node;
void insertlast();
void deletefirst();
void display();
int check_Palindrome();
void main()
{
	int ch;
	printf("1.insertlast\n2.deletefirst\n3.display");
	while(1)
	{
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					insertlast();
					break;
				}
			case 2:
				{
					deletefirst();
					break;
				}
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
					check_Palindrome();
					break;
				}
			default:
				exit(0);
		}
	}
}
void insertlast()
{
	int x;
	node *newnode,*p;
	newnode=(node *)malloc(sizeof(node));
	printf("Enter your data");
	scanf("%d",&x);
	newnode->value=x;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
	}
	else
	{
		p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=newnode;
		newnode->next=head;
	}
}
void deletefirst()
{
	node *temp,*p;
	if(head==NULL)
	{
		printf("There is no node to delete");
	}
	else
	{
		p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		temp=head;
		head=temp->next;
		p->next=head;
		free(temp);
	}
}
void display()
{
	node *p;
	p=head;
	while(p->next!=head)
	{
		printf("%d",p->value);
		p=p->next;
	}
	printf("%d",p->value);
}
int check_Palindrome()
{
	int flag=1;
	node *first,*last,*temp,*p;
	first=head;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	last=temp;
	while(last->next!=first || last->next==head )
	{
		if(last==first)
		{
			printf("It is a palindrome");
			return;
		}
		if(last->value!=first->value)
		{
			printf("Not palindrome");
			return;
		}
		temp=first;
		while(temp->next!=last)
		{
			temp=temp->next;
		}
		last=temp;
		first=first->next;
	}
	printf("Palindrome");
	return;
}














