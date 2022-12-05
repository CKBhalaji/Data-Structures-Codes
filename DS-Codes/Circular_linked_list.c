#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
}*head=NULL;
void insertfirst()
{
    struct node *newnode,*p;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value for insert:");
    scanf("%d",&data);
    newnode->value=data;
    newnode->next=NULL;
    if (head==NULL)
    {
        head = newnode;
        newnode->next=head;
    }
    else
    {
        p=head;
        newnode->next=p;
        while (p->next!=head)
        {
            p=p->next;
        }
        p->next=newnode;
        head=newnode;
    }
}
void insertlast()
{
    struct node *newnode,*p;
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value for insert:");
    scanf("%d",&data);
    newnode->value=data;
    newnode->next=NULL;
    if (head==NULL)
    {
        head = newnode;
        newnode->next=head;
    }
    else
    {
        p=head;
        while (p->next!=head)
        {
            p=p->next;
        }
        p->next=newnode;
        newnode->next=head;
    }
}
void insertmiddle()
{
    struct node *newnode,*p;
    int data,search;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value for insert:");
    scanf("%d",&data);
    printf("Enter the value to insert after:");
    scanf("%d",&search);
    newnode->value=data;
    newnode->next=NULL;
    if (head==NULL)
    {
        printf("No List");
    }
    else
    {
        p=head;
        while (p->value!=search)
        {
            p=p->next;
        }
        newnode->next=p->next;
        p->next=newnode;
    }
}
void deletefirst()
{
    struct node *p,*temp;
    if (head==NULL)
    {
        printf("No List");
    }
    else if (head->next==head)
    {
        p=head;
        head=NULL;
        free(p);
    }
    else
    {
        p=head;
        while (p->next!=head)
        {
            p=p->next;
        }
        p->next=head->next;
        temp=head;
        head=temp->next;
        free(temp);
    }
}
void deletelast()
{
    struct node *p,*temp;
    if (head==NULL)
    {
        printf("No List");
    }
    else if (head->next==head)
    {
        p=head;
        head=NULL;
        free(p);
    }
    else
    {
        p=head;
        while (p->next->next!=head)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=head;
        free(temp);
    }
}
void deletemiddle()
{
    struct node *p,*temp;
    int search;
    printf("Enter the value for delete:");
    scanf("%d",&search);
    if (head==NULL)
    {
        printf("No List");
    }
    else if (head->next==head)
    {
        p=head;
        head=NULL;
        free(p);
    }
    else
    {
        p=head;
        while (p->next->value!=search)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }
}
void display()
{
    struct node *p;
    int flag;
    p=head;
    if (head==NULL)
    {
        printf("head->NULL");
    }
    else
    {
    printf("head->%d",p->value);
    p=p->next;
    while (p!=head)
    {
        printf("->%d",p->value);
        p=p->next;
        flag=1;
    }
      printf("->head");
    }
}
void main()
{
    int c;
    printf("1.Insert First\n2.Insert Last\n3.Insert Middle\n4.Delete first\n5.Delete Last\n6.Delete Middle\n7.Display\n8.Exit");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            insertfirst();
            break;
        case 2:
            insertlast();
            break;
        case 3:
            insertmiddle();
            break;
        case 4:
            deletefirst();
            break;
        case 5:
            deletelast();
            break;
        case 6:
            deletemiddle();
            break;
        case 7:
            display();
            break;
        default:
            break;
        }
    } while (c!=8);
    printf("Successfully Done!!!");
    getch();
}