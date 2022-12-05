/******REVERSE THE ELEMENTS IN K-GROUPS-DOUBLY LINKED LIST******/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}*head=NULL;
struct Node *newnode;

struct Node *reverse (struct Node *head, int k)
{
	if (!head)
		return NULL;
	
	head->prev=NULL;
	struct Node *curr = head;
	struct Node *temp;
	struct Node *newhead;
	int count = 0;
	
	while (curr != NULL && count < k)
	{
		newhead=curr;
		temp=curr->prev;
		curr->prev=curr->next;
		curr->next=temp;
		curr=curr->prev;
		count++;
	}
	
	if(count>=k)
	{
		struct node *rest=reverse (curr,k);
		head->next=rest;
	}
	return newhead;
}

void insertlast(struct Node *Newnode)
{
	int data;
	struct Node *p;
	Newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value to be inserted->:");
	scanf("%d",&data);
	Newnode->data=data;
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
		Newnode->prev=p;
	}
}

void display(struct Node *node)
{
	while(node->next!=NULL)
	{
		printf("%d<->",node->data);
		node=node->next;
	}
    printf("%d",node->data);  
} 

int main(void)
{
    int ch,n;
	while(1)
	{
		printf("\n1.Insert and Dislay\n2.kreverse\n3.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insertlast(newnode);
				display(head);
				break;
			case (2):
				printf("Enter at which K it should reverse::");
				scanf("%d",&n);
				head = reverse (head, n);
				display(head);
				break;
			case (3):
				exit(0);
		}
	} 
	return(0);
}
