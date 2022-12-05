/*******Creat Binary Tree For A Given Array*******/
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

struct node *Tr=NULL,*root;
int i,n,a[100];

struct node* insertLevelOrder(int arr[],int i, int n,struct node *root);
void arraycreation();
void print_inorder(struct node * tree);
void insert_in_tree();

int main()
{
	//struct node *T;
	int ch,val,hei;
		printf("\n1.Insert Elements In Array\n2.Insert In To Tree\n3.Print in INORDER\n4.Exit");
	while(1)
	{
		printf("\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				arraycreation();
				break;
			case (2):
				insert_in_tree();
				break;
			case (3):
				printf("Elements inorder-->:\n");
				print_inorder(root);
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}
struct node* insertLevelOrder(int arr[],int i, int n,struct node *root)
{
    root = NULL;
    // Base case for recursion
    if (i < n)
    {
    	struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = arr[i];
        node->left = node->right = NULL;
        root=node;
        // insert left child
        root->left = insertLevelOrder(arr,2 * i + 1, n,Tr);
        // insert right child
        root->right = insertLevelOrder(arr,2 * i + 2, n,Tr);
    }
    return root;
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
void insert_in_tree()
{
	for(i=0;i<n;i++)
	{
		root=insertLevelOrder(a,0,n,Tr);
	}
	printf("Sucessfully Inserted\n");
}
void arraycreation()
{
	
	printf("Enter the Number of Elements in Array-->:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the Element %d-->:",i+1);
		scanf("%d",&a[i]);
	}
}
