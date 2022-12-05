/******Vehicles in toll using Queue******/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char veh[100];
	struct node *next;
};
struct node *front=NULL,*rear=NULL;
void Veh_IN();
void Veh_OUT();
void First_Veh();
void display();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Enter the TOLL\n2.Move First Vehicle Out\n3.Show First Vehicle\n4.Show All Vehicles\n5.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				Veh_IN();
				display();
				break;
			case (2):
				Veh_OUT();
				display();
				break;
			case (3):
				First_Veh();
				break;
			case (4):
				display();
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}
void Veh_IN()
{
	char data[100];
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter Vehicle Name To Inside Toll->:");
	scanf("%s",&data);
	strcpy(newnode->veh,data);
	newnode->next=NULL;
	if(front==NULL&&rear==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void Veh_OUT()
{
	struct node *temp;
	if(front==NULL&&rear==NULL)
	   printf("There Is No Vehical In The TOLL");
	else
	{
		temp=front;
		front=temp->next;
		free(temp);
	}
}
void First_Veh()
{
	struct node *temp;
	if(front==NULL&&rear==NULL)
	   printf("There Is No Vehical In The TOLL");
	temp=front;
	printf("%s",front->veh);
}
void display()
{
	struct node *p;
	if(front==NULL&&rear==NULL)
	   printf("There Is No Vehical In The TOLL");
    else
    {
        p=front;
        printf("\n");
	    while(p->next!=NULL)
	    {
            printf("%s<-",p->veh);
		    p=p->next;
	     }
         printf("%s",p->veh);  
         printf("\n");
     }
}
