/******REVERSE THE ELEMENTS IN K-GROUPS-SINGLY LINKED LIST******/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
}*head=NULL;
struct Node *newnode;

struct Node *reverse (struct Node *head, int k)
{
	if (!head)
		return NULL;   
	
	struct Node* current = head;
	struct Node* next = NULL;
	struct Node* prev = NULL;
	int count = 0;
	
	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	
	if (next != NULL)
	    head->next = reverse(next, k);
	return prev;
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
	}
}

void display(struct Node *node)
{
	while(node->next!=NULL)
	{
		printf("%d->",node->data);
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
