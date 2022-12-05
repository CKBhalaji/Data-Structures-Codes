/*******INSERT A ELEMENT IN A RANDOM LOCATION********/
/*#include <stdio.h>
 
int main()
{
   int array[100], position, c, n, value;
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
 
   printf("Enter %d elements\n", n);
 
   for (c = 1; c <= n; c++)
      scanf("%d", &array[c]);
 
   printf("Enter the location where you wish to insert an element\n");
   scanf("%d", &position);
   //position=position+1;
   printf("Enter the value to insert\n");
   scanf("%d", &value);
   
   for (c = n ; c >position - 1; c--)
      array[c+1] = array[c];
 
   array[position] = value;
 
   printf("Resultant array is\n");
 
   for (c = 1; c <= n+1 ; c++)
      printf("%d\n", array[c]);
 
   return 0;
}*/
/********FINDING SECONT MIN AND MAX********/
#include <stdio.h>
 
int main()
{
   int a[100], position, c, n, value;
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
 
   printf("Enter %d elements\n", n);
 
   for (c = 1; c <= n; c++)
      scanf("%d", &a[c]);
    int min=a[0];
    int max=a[0];
    int i,j;
    for(i=0;i<n;i++)
    {
    	int temp;
    	for(j=i+1;j<n;j++)
    	{
    		if(a[i]<a[j])
    		{
    			temp=a[i];
    			a[i]=a[j];
    			a[j]=temp;
			}
		}
	}
	printf("/n2nd Smallest-->:%d",a[n-3]);
	printf("/n2nd Largest-->:%d/n",a[1]);
return 0;
}	
