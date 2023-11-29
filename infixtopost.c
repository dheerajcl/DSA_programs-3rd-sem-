#include<stdio.h>
#include<ctype.h>
#define max 15

char stack[max];
int top = -1;

void push(int ele)
{
	if(top==max-1)
		printf("Overflow\n");
	else
	{
		top++;
		stack[top]=ele;
	}

}
char pop()
{	char x;
	if(top==-1)
		printf("UNDERFLOW\n");
	else
	{
		x = stack[top];
		top--;
	}
	return x;
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;	
}
int precedence(char x)	
{
	if(x=='^')
		return 3;
	else if(x=='*' || x=='/')
		return 2;
	else if(x=='+' || x=='-')
		return 1;
	else
		return 0;

}

void infix_to_postfix(char* in, char* post)
{	
	int i,j=0;
	char ss,x;
	for(i=0;in[i]!='\0';i++)
	{
		ss =in[i];
		if(isalnum(ss))
			post[j++]=ss;
		else if(ss == '(')
			push(ss);
		else if(ss==')')
		{
			while((x=pop())!='(')
			{
				post[j++]=x;
			}
			
		}
		else
		{
			while(precedence(ss)<=precedence(stack[top]))
			{
				post[j++] = pop();
			}
			push(ss);
		}
	}
	while(!isempty())
	{
		post[j++] = pop();
	}	
	post[j] = '\0';
}
			
int main()
{	
	char in[20], post[20];
	printf("enter the infix expression:\n");
	gets(in);
	infix_to_postfix(in,post);
	printf("postfix expression is %s\n", post);
return 0;
}