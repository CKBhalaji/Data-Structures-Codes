#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *left;
struct node *right;
int height;
}node;
node *createNode(node *, int);
void inorderTraversal(node *);

int balanceFactor(node *);
int nodeHeight(node *);
node *rotateRight(node *);
node *rotateLeft(node *);
node *LL(node *);
node *RR(node *);
node *LR(node *);
node *RL(node *);

int main()
{
int n,choice;
node *root=NULL;
while(1)
{
printf("\n1. Create/Insert Node");
printf("\n2. Convert into AVL Tree");
printf("\n3. Exit\n");
printf("\nEnter your Choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter Node to Insert: ");
scanf("%d",&n);
root=createNode(root, n);
break;
case 2:
printf("\nBALANCED AVL TREE \n");
inorderTraversal(root);
break;
case 3:
exit(1);
}
}
}
node *createNode(node *root, int n)
{
if(root==NULL)
{
root=(node *)malloc(sizeof(node));
root->data=n;
root->right=NULL;
root->left=NULL;
}
else if(n < root->data)
{
root->left=createNode(root->left, n);
if(balanceFactor(root)>=2)
if(n < root->left->data)
root=LL(root);
else
root=LR(root);
}
else if(n > root->data)
{
root->left=createNode(root->left, n);
if(balanceFactor(root)<=-2)
if(n > root->right->data)
root=RR(root);
else
root=RL(root);
}


else
printf("\nDuplicate Node\n");
return root;
}
void inorderTraversal(node *root)
{
if(root==NULL)
return;
else
{
inorderTraversal(root->left);
printf("<-|%d|->  ",root->data);
inorderTraversal(root->right);
}
}

int nodeHeight(node *root)
{
int lh, rh;
if(root==NULL)
return 0;
if(root->left==NULL)
lh=0;
else
lh=1+nodeHeight(root->left);
if(root->right==NULL)
rh=0;
else
rh=1+nodeHeight(root->right);
if(lh > rh)
return lh;
else
return rh;
}
int balanceFactor(node *root)
{
int lh,rh;
if(root==NULL)
return 0;
if(root->left==NULL)
lh=0;
else
lh=1+nodeHeight(root->left);
if(root->right==NULL)
rh=0;
else
rh=1+nodeHeight(root->right);
return (lh-rh);
}
node *rotateLeft(node *root)
{
node *temp;
temp=root->left;
free(root->left);  
temp->right=root;
root->height=nodeHeight(root);
temp->height=nodeHeight(temp);
return temp;
}
node *rotateRight(node *root){
node *temp;
temp=root->right;
free(root->right);  
temp->left=root;
root->height=nodeHeight(root);
temp->height=nodeHeight(temp);
return temp;
}
node *LL(node *root)
{
root=rotateLeft(root);
return root;
}
node *RR(node *root)
{
root=rotateRight(root);
return root;
}
node *LR(node *root)
{
root=rotateRight(root->left);  
return root;
}
node *RL(node *root)
{
root=rotateLeft(root->right);  
return root;
}
