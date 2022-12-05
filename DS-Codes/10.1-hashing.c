/*****Implimentation of Hashing****/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void linear_prob(int k);
void double_has(int k);
void quadratic_prob(int k);
void display(int d[10]);
void convert(int e[10]);

int a[10];
int b[10];
int c[10];
int m=10;

int main()
{
	//struct node *T;
	int ch,k;
	printf("\n1.Linear Probing\n2.Double Hashing\n3.Quadratic Probing\n5.Exit");
	convert(a);
	convert(b);
	convert(c);
	
	while(1)
	{
		printf("\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				printf("Enter the element-->;");
				scanf("%d",&k);
				linear_prob(k);
				display(a);
				break;
			case (2):
				printf("Enter the element-->;");
				scanf("%d",&k);
				double_has(k);
				display(b);
				break;
			case (3):
				printf("Enter the element-->;");
				scanf("%d",&k);
				quadratic_prob(k);
				display(c);
				break;
			case (4):
				printf("Elements-->:");
				display(a);
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}


void linear_prob(int k)
{
	//convert
	int i=0,ind;
	int hd=k%m;
	while(1)
	{
		ind=(hd+i)%m;
		if(a[ind]!=-1)
		{
			i++;
		}
		else
		{
			a[ind]=k;
			break;
		}
	}
}

void double_has(int k)
{
	int i=0,ind,c1=2,c2=3;
	int hd=k%m;
	while(1)
	{
		ind=(hd+c1*i+c2*i*i)%m;
		if(b[ind]!=-1)
		{
			i++;
		}
		else
		{
			b[ind]=k;
			break;
		}
	}
}

void quadratic_prob(int k)
{
	int i=0,ind;
	int hd1=k%m;
	int hd2=k%8;
	while(1)
	{
		ind=(hd1+i*hd2)%m;
		if(c[ind]!=-1)
		{
			i++;
		}
		else
		{
			c[ind]=k;
			break;
		}
	}
}

void display(int d[10])
{
	int i;
	for(i=0;i<m;i++)
	{
		printf("%d\t",d[i]);
	}
}

void convert(int e[10])
{
	int i;
	for(i=0;i<m;i++)
	{
		e[i]=-1;
	}
}


