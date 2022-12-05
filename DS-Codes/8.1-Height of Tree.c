/*******Height of the tree*******/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
}*right=NULL,*left=NULL;
struct node *Tr=NULL;
void insert(struct node ** tree, int val);
int heightoftree(struct node *t);
int main()
{
	//struct node *T;
	int ch,val,hei;
		printf("\n1.Insert\n2.Height\n3.Exit");
	while(1)
	{
		printf("\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				printf("Enter element to insert-->:");
				scanf("%d",&val);
				insert(&Tr,val);
				break;
			case (2):
				hei=heightoftree(Tr);
				printf("Height of TREE is-->:%d\n",hei);
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}
void insert(struct node ** tree, int val)
{
    struct node *temp = NULL;
    if(!(*tree))
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    else if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int heightoftree(struct node *t)
{
	int L_height,R_height;
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		L_height= heightoftree(t->left);
		R_height= heightoftree(t->right);
		if(L_height > R_height)
        {
        	return L_height + 1;
		}
		else
		{
			return R_height + 1;
		}
	}
}
