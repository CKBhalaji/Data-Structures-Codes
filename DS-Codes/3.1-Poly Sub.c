/*****POLLYNOMIAL SUBTRACTION USING SINLY LINKED LIST******/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	int pow;
	struct Node *next;
}*head=NULL;

struct Node *newnode1;
struct Node *newnode2;

void insertlast1()
{
	int dataa,powr;
	struct Node *p;
	newnode1=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value to be inserted->:");
	scanf("%d",&dataa);
	newnode1->data=dataa;
	printf("Enter the power to be inserted->:");
	scanf("%d",&powr);
	//Newnode->data=dataa;
	newnode1->pow=powr;
	newnode1->next=NULL;
	if(head==NULL)
	{
		head=newnode1;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		     p=p->next;
		p->next=newnode1;
	}
}

void insertlast2()
{
	int dataa,powr;
	struct Node *p1;
	newnode2=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value to be inserted->:");
	scanf("%d",&dataa);
	newnode2->data=dataa;
	printf("Enter the power to be inserted->:");
	scanf("%d",&powr);
	//Newnode->data=dataa;
	newnode2->pow=powr;
	newnode2->next=NULL;
	if(head==NULL)
	{
		head=newnode2;
	}
	else
	{
		p1=head;
		while(p1->next!=NULL)
		     p1=p1->next;
		p1->next=newnode2;
	}
}

void display()
{
	//struct Node *n;
	newnode1=head;
	while(newnode1->next!=NULL)
	{
		printf("||%d|",newnode1->data);
		printf("%d||->",newnode1->pow);
		newnode1=newnode1->next;
	}
    printf("||%d|",newnode1->data);
	printf("%d||->",newnode1->pow);  
} 

void displayy()
{
	//struct Node *n;
	newnode2=head;
	while(newnode2->next!=NULL)
	{
		printf("||%d|",newnode2->data);
		printf("%d||->",newnode2->pow);
		newnode2=newnode2->next;
	}
    printf("||%d|",newnode2->data);
	printf("%d||->",newnode2->pow);  
} 
/*
void addition()
{
	struct Node *p1=head1,*p2=head2,*newnode=NULL;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->pow==p2->pow)
		{
			newnode->data=p1->data+p2->data;
			newnode->pow=p1->pow;
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->pow>p2->pow)
		{
			newnode->data=p1->data;
			newnode->pow=p1->pow;
			p1=p1->next;
		}
		else
		{
			newnode->data=p2->data;
			newnode->pow=p2->pow;
			p2=p2->next;
		}
	}
}*/

int main()
{
	int ch;
	while(1)
	{
		printf("\nEnter the choice\n1.Insert Fist Expression and Dislay\n2.Insert Second Expression and Dislay\n3.Exit\n4.addition\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insertlast1();
				display();
				break;
			case (2):
				insertlast2();
				displayy();
				break;
			case (3):
				exit(0);
			case (4):
				//addition();
				//display(newnode1);
				break;
			case (5):
				exit(0);
		}
	}
	return 0;
}

