#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct node
{
	int roll_no;
	char name[20];
	struct node *next;
}*head=NULL;
void insertinformation();
void display();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert student Information and Dislay\n2.display\n3.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				insertinformation();
				display();
				break;
			case (2):
				display();
				break;
			default:
				exit(0);
		}
	}
	return 0;
	}

void insertinformation()
{
	int data;
	char nname[20];
	struct node *newnode,*p;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Roll no.->:");
	scanf("%d",&data);
	printf("Enter Name-->:");
	scanf("%s",&nname);
	newnode->roll_no=data;
	strcpy(newnode->name,nname);
    newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		   p=p->next;
		p->next=newnode;
	}
}

void display()
{
	struct node *p;
	p=head;
	while(p->next!=NULL)
	{
		printf("%d.-\t\t%s\n",p->roll_no,p->name);
		p=p->next;
	}
     printf("%d.-\t\t%s\n",p->roll_no,p->name);  
}
