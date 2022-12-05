/*******Tom is String Freeky*******/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display();
void push();
void hell_destroy();

char stack[5][4];
int top=-1;


int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert and Dislay\n2.Tom is String Freeky\n3.Again call of main method\n4.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				push();
				display();
				break;
			case (2):
				hell_destroy();
				display();
				break;
			case (3):
				main();
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}

void push()
{
	int side=-1,i;
	char data[7];
	printf("Enter the element::");
	scanf("%s",data);
	top++;
	for(i=1;i<7;i++){
		side+=i;
	stack[top][side]=data[i-1];
	}
}


void display()
{
	int i,j;
	top++;
	int side=-1;
	for(i=top;i>=0;i--)
	{
		for(j=side;j>=0;j--)
		{
			printf("%s,\t",stack[i][j]);
		}
	}
}

void hell_destroy()
{
	char dup[5][4];
	int count=0,i,j,k,flag=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			dup[i][j]=stack[i][j];
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			for(k=0;k<4;k++)
			{
				//for(l=k+1;l<4;l++)
				//{	
				//}
				if(dup[i][k]!=dup[i][k])
				{
					flag=1;
					break;
				}
			}
		if(flag==1)
		{
			dup[i][j]='$';
		}
		}
	}
	for(i=0;i<5;i++)
	{
		if(dup[i]!="$")
		{
			count+=1;
		}
	}
	printf("count:: %d",count);
}
