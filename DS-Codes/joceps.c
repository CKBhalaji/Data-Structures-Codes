#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node* next;
}node;
struct node* getNode (struct node *head, int val)
{
    struct node *element = (struct node*) malloc(sizeof(struct node));
    element->value = val ;
    element->next = NULL ;
    struct node *temp = head ;
    if ( head == NULL ) {
        head = element ;
        head->next = head ;
        return head ;
    }
    while (temp->next != head)
        temp = temp->next ;
    temp->next = element ;
    element->next = head ;
    return head ;
}

struct node* ContestWinner(struct node *head, int k, int n)
{
  int i,res;
  if(n == 1)
    return head;
  for(i=1; i<=n; i++)
  {
    res = (res + k-1)%i + 1;
  }
  for(i=1; i<res; i++){
    head = head->next;
  }
  head->next = NULL;
  return head;
}
int main() 
{
    while(1){
        struct node *head = NULL, *temp ;
        int size, i, val, M;
        printf("Enter size:");
        scanf("%d",&size);
        printf("Enter num:");
        scanf("%d",&M);
        for ( i = 0 ; i < size ; i ++ ) {
            printf("Enter value %d:",i+1);
            scanf("%d",&val);
            head = getNode(head, val) ;
        }
        temp = ContestWinner(head, M, size) ;
        if ( temp != NULL )
            printf("Winner:%d\n", temp->value) ;
    }
    return 0;
}

