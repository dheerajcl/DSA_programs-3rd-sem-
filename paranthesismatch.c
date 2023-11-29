#include<stdio.h>
#define max 10

int S[max];
int top = -1;
void push(int x);
void pop();
void display();
int pm(char *c);

int main()
{
	char ch[max];
	printf("enter the string");
	scanf("%s", ch);
	int res = pm(ch);
	if (res==1)
		printf("balanced\n");
	else
		printf("unbalanced");
	return 0;
}

int pm(char* c)
{	int i=0;
	while(c[i]!='\0')
	{
		if(c[i]=='(')
			push('(');
		else if(c[i]==')')
		{
			if(top==-1)
				return 0;
			pop();
		}
		else if(c[i]=='[')
			push('[');
		else if(c[i]==']')
		{
			if(top==-1)
				return 0;
			pop();
		}
		else if(c[i]=='{')
			push('{');
		else if(c[i]=='}')
		{
			if(top==-1)
				return 0;
			pop();
		}
		
	}
	if(top==-1)
		return 1;
	else
		return 0;

}
void push(int x)
{
	if(top == max)
		printf("OVERFLOW\n");
	else
	{
		top++;
		S[top] = x;
	}
}
void pop()
{ int x;
	if(top == -1)
	{
		printf("UNDERFLOW\n");
		//return -1;
	}
	else
	{
		x = S[top];
		top--;
		//return x;
	}
}
void display()
{
	if(top == -1)
		printf("Stack empty");
	else
	{
		int p = top;
		while(p>-1)
		{
			printf("%d \t", S[p]);
			p--;
		}
		printf("\n");
	}
}

int peek()
{
	printf("Top element is %d\n", S[top]);
}