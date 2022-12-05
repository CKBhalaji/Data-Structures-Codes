# include<stdio.h>  
# include<malloc.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node  
    {  
    int priority;  
    int info;  
    struct node *link;  
}NODE;  
NODE *front = NULL;  

void insert(int data,int priority)  
{  
    NODE *temp,*q;  
  
    temp = (NODE *)malloc(sizeof(NODE));  
    temp->info = data;  
    temp->priority = priority;  
    if( front == NULL || priority < front->priority )  
    {  
        temp->link = front;  
        front = temp;  
    }  
    else  
    {  
        q = front;  
        while( q->link != NULL && q->link->priority <= priority )  
            q=q->link;  
        temp->link = q->link;  
        q->link = temp;  
    }  
}  

void deleta()
{
	NODE *temp;
	int item;
	if(front==NULL)
	{
		printf("Empty");
	}
	else
	{
		temp=front;
		item=temp->info;
		front=front->link;
		free(temp);
	}
}

void display()  
{  
    NODE *ptr;
    ptr = front;
    if(front == NULL)
	printf("Queue is empty\n");
    else
    {
	printf("Queue is :\n");
	printf("Priority       Item\n");
	while(ptr != NULL)
	{
	    printf("%5d        %5d\n",ptr->priority,ptr->info);
	    ptr = ptr->link;
	}
    }
}

int main()
{
    int choice, data, priority;
    //clrscr();
    do
    {
	printf("1.Insert\n");
	printf("2.Display\n");
	printf("3.Delete\n4.Quit\n");
	printf("Enter your choice : ");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1:
		printf("Enter the data which is to be added in the queue : ");
		scanf("%d",&data);
		printf("Enter its priority : ");
		scanf("%d",&priority);
		insert(data,priority);
		break;
	    case 2:
	    	display();
			break;
		case 3:
	       deleta();
	       display();
	       break;
	    case 4:
	       exit(0);
	       //break;
		default :
		printf("Wrong choice\n");
	}
    }while(choice!=4);

return 0;
}
