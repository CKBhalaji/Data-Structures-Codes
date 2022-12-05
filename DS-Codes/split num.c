#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int value;
struct node *next;
}*head=NULL;
void main()
{
	int n,rep,temp,x;
	printf("Enter a number:");
	scanf("%d",&n);
	temp=n;
	while(1)
	{
		x=temp%10;
		insert_first(x);
		temp=temp/10;
		if(temp==NULL)
		 break;
	}
	print_list();
}
void insert_first(int data)
{
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->value=data;
newnode->next=NULL;
if(head==NULL)
 head=newnode;
else
{
 newnode->next=head;
 head=newnode;
}
}
void print_list()
{
struct node*ptr=head;
printf("n[head]=>" );
while(ptr!=NULL)
{
printf("%d=>",ptr->value);
ptr=ptr->next;
}
printf("[null]n");
}
