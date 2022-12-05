#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char array[10][20],stack[10][20];
int size,top=-1;

void arrayz()
{
    int i;
    char data[20];
    printf("Enter the Size of the Array:");
    scanf("%d",&size);
    printf("Enter Elements\n");
    for ( i = 0; i < size; i++)
    {
        scanf("%s",array[i]);
    }
}

void arrdisplay()
{
    int i,j;
    printf(" Elements Are\n");
    for ( i = 0; i < size; i++)
    {
        printf("%d.",i+1);
        for ( j = 0; array[i][j]!='\0'; j++)
        {
            printf("%c",array[i][j]);
        }
        printf(".\n");
    } 
}
void stacky()
{
    int i,j,k,l,len2,len1,found=0;
    for ( i = 0; i < size; i++)
    {
        if (array[i][0]== '$')
        {
            break;
        }
        for ( j = i+1; j < size; j++)
        {
            len1=strlen(array[i]);
            len2=strlen(array[j]);
            for ( k = 0; k < len1; k++)
            {
                found=0;
                for (l = 0; l < len2; l++)
                {
                    if (array[i][k]==array[j][l])
                    {
                        found=1;
                        break;
                    }
                    
                }
                if (found!=1)
                {
                    break;
                }  
            }
            if(found==1)
            {
                array[j][0]= '$';
            }  
        }
    }
    for ( i = 0; i < size; i++)
    {
        if(array[i][0] != '$')
        {
            continue;
        }
        len1=strlen(array[i]);
        for ( j = 0; j < len1; j++)
        {
            stack[i][j]=array[i][j];
            top+=1;
        } 
        stack[i][j]='\0';
    }  
}
void stdisplay()
{
    int count=0,i;

    for (i=0; i<top; i++)
    {
        count+=1;
    } 
    printf("Number of elements in stack:%d",count);
}
void main()
{
    int c;
    printf("1.Insert in array \n2.Display array \n3.Add original Element in stack \n4.Display Number of Elements in Stack\n5.Exit");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            {
                arrayz();
                break;
            }
            case 2:
            {
                arrdisplay();
                break;
            }
            case 3:
            {
                stacky();
                break;
            }
            case 4:
            {
                stdisplay();
                break;
            }
            default:
                break;
        }
    }while(c<=4);
    printf("Successfully Done!!!!");
    getch();
}    
