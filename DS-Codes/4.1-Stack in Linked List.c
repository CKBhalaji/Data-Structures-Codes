/*******Implimentation Of Stack Using Array*******/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int stack[100];
int top=-1;

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert and Dislay\n2.Delete\n3.Show First Value In Stack\n4.Exit\nEner choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case (1):
				push();
				display();
				break;
			case (2):
				pop();
				display();
				break;
			case (3):
				peek();
				break;
			default:
				exit(0);
		}
	}
	return 0;	
}

int push()
{
	int data;
	printf("Enter the element::");
	scanf("%d",&data);
	top++;
	stack[top]=data;
}

void pop()
{
	top--;
}

void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}

void peek()
{
	printf("First Element in Stack Is %d",stack[top]);
}

/***C++ implementation of above method
//#include<bits/stdc++.h>
//using namespace std;

// Function to find the size of manipulated sequence
int removeConsecutiveSame(vector <string> v)
{
	stack<string> st;

	// Start traversing the sequence
	for (int i=0; i<v.size(); i++)
	{
		// Push the current string if the stack
		// is empty
		if (st.empty())
			st.push(v[i]);
		else
		{
			string str = st.top();

			// compare the current string with stack top
			// if equal, pop the top
			if (str.compare(v[i]) == 0)
				st.pop();

			// Otherwise push the current string
			else
				st.push(v[i]);
		}
	}

	// Return stack size
	return st.size();
}

// Driver code
int main()
{
	vector<string> V = { "ab", "aa", "aa", "bcd", "ab"};
	cout << removeConsecutiveSame(V);
	return 0;
}*/

