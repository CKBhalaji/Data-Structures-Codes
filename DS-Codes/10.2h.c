#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct tree
{
int a;
struct tree *left;
struct tree *right;
}node;

node *queue[100];
int front = -1;
int rear = 0;

void enqueue(node *root)
{
queue[rear] = root;
rear++;
}

node* dequeue()
{
front++;
node *c = queue[front];
return c;
}

void levelorder(node *root)
{
node *q;
printf("\n");
enqueue(root);
while(rear-1!=front)
{
// printf("\nrear = %d , front = %d",rear , front);
q = dequeue();
printf("%d\t",q->a);
if(q->left)
enqueue(q->left);
if(q->right)
enqueue(q->right);


}



}


int main()
{
int n , i;
node *p , *q , *root;
printf("Enter the number of nodes");
scanf("%d",&n);

for(i=0;i<n;i++)
{
if(i == 0)
{
p = (node*)malloc(sizeof(node));
scanf("%d",&p->a);
p->left = NULL;
p->right = NULL;
q = p;
root = p;
}
else
{
p = (node*)malloc(sizeof(node));
scanf("%d",&p->a);
p->left = NULL;
p->right = NULL;
q = root;
while(1)
{
if(p->a > q->a)
{
if(q->right == NULL)
{
q->right = p;
break;
}
else
q = q->right;
}
else
{
if(q->left == NULL)
{
q->left = p;
break;
}
else
q = q->left;
}
}

}

}


printf("Level order Traversal is :- ");
levelorder(root);

return 0;
}






//DFS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

void DFS(node *root)
{
if(root)
{
printf("  %d",root->data);
DFS(root->left);
DFS(root->right);
}
}


int main()
{
int n , i;
struct node *p , *q , *root;
printf("Enter the number of nodes");
scanf("%d",&n);

for(i=0;i<n;i++)
{
p = (struct node*)malloc(sizeof(struct node));
scanf("%d",&p->data);
p->left = NULL;
p->right = NULL;
if(i == 0)
{
root = p; // root always point to the root node
}
else
{
q = root;   // q is used to traverse the tree
while(1)
{
if(p->data > q->data)
{
if(q->right == NULL)
{
q->right = p;
break;
}
else
q = q->right;
}
else
{
if(q->left == NULL)
{
q->left = p;
break;
}
else
q = q->left;
}
}

}

}


printf("\n DFS:-")
DFS(root);

return 0;
}
