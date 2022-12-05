/*******Binary terr Traversal Inorder Preorder Postorder*******/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
}*right=NULL,*left=NULL;

struct node *Tr=NULL;

void insert();
void print_inorder();
void print_preorder();
void print_postorder();

int main()
{
	//struct node *T;
	int ch,val;
		printf("\n1.Insert\n2.print in INORDER\n3.print in PREORDER\n4.Print in POSTORDER\n5.Exit");
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
				printf("Elements inorder-->:\n");
				print_inorder(Tr);
				break;
			case (3):
				printf("Element preorder-->:\n");
				print_preorder(Tr);
				break;
			case (4):
				printf("Elements postorder-->:\n");
				print_postorder(Tr);
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

void print_preorder(struct node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(struct node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(struct node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

