#include <stdio.h>
#define MAX 5
int main()
{
	int ch,k;
	int visited[MAX] = {0};
	int adj[MAX][MAX], i, j;
	printf("\n1.Insert \n2.Breadth First Traversal\n3.Depth First Traversal\n5.Exit");
	while(1)
	{
		printf("\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				printf("\n Enter the adjacency matrix:\n ");
				for(i = 0; i < MAX; i++)
				    for(j = 0; j < MAX; j++)
					    scanf("%d", &adj[i][j]);
				//breadth_first_search(adj,visited,0);
				break;
			case (2):
				/*printf("\n Enter the adjacency matrix: ");
				for(i = 0; i < MAX; i++)
				    for(j = 0; j < MAX; j++)
					    scanf("%d", &adj[i][j]);
				printf("DFS Traversal: ");*/
				breadth_first_search(adj,visited,0);
				printf("\n");
				break;
			case (3):
				printf("DFS Traversal: ");
				depth_first_search(adj,visited,0);
				break;
			default:
				exit(0);
		}
	}
  return 0;
}
void depth_first_search(int adj[][MAX],int visited[],int start)
{
	int stack[MAX];
	int top = -1, i;
	printf("%c–",start + 65);
	visited[start] = 1;
	stack[++top] = start;
	while(top != -1)
	{
		start = stack[top];
		for(i = 0; i < MAX; i++)
		{
			if(adj[start][i] && visited[i] == 0)
			{
				stack[++top] = i;
				printf("%c–", i + 65);
				visited[i] = 1;
				break;
			}
		}
		if(i == MAX)
		{
			top--;
		}
	}
}
void breadth_first_search(int adj[][MAX],int visited[],int start)
{
	int queue[MAX],rear = -1,front =-1, i;
	queue[++rear] = start;
	visited[start] = 1;
	while(rear != front)
	{
		start = queue[++front];
		if(start == MAX)
		    printf("5\t");
		else
		   printf("%c \t",start + 65);
		   for(i = 0; i < MAX; i++)
		   {
		   	   if(adj[start][i] == 1 && visited[i] == 0)
				{
					queue[++rear] = i;
					visited[i] = 1;
				}
			}
	}
}

/* int visited[MAX] = {0};
  int adj[MAX][MAX], i, j;
printf("\n Enter the adjacency matrix: ");
  for(i = 0; i < MAX; i++)
    for(j = 0; j < MAX; j++)
 scanf("%d", &adj[i][j]);
breadth_first_search(adj,visited,0);
  return 0;
  
  
  
   int adj[MAX][MAX];
  int visited[MAX] = {0}, i, j;
printf("\n Enter the adjacency matrix: ");
  for(i = 0; i < MAX; i++)
    for(j = 0; j < MAX; j++)
 scanf("%d", &adj[i][j]);
printf("DFS Traversal: ");
  depth_first_search(adj,visited,0);
printf("\n");
*/

  
  
