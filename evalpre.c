//Edata prefix

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 15
typedef struct stack
{
	float s[max];
	int top;
}STACK;

void init(STACK *opst)
{
	opst->top = -1;
}

void push(STACK *opst, float ele)
{
	if(opst->top == max)
		printf("overflow\n");
	else
	{
		opst->top++;
		opst->s[opst->top] = ele;
	}
}

float pop(STACK *opst)
{
	float ele=0;
	if(opst->top == -1)
		printf("underflow\n");
	else
	{
		ele = opst->s[opst->top] ;
		opst->top--;
	}
	return ele;
}

int main()
{
	STACK opst;
	init(&opst);
	char post[20],ch;
	float op1,op2,res;
	int i;
	printf("enter the string\n");
	gets(post);			//3+2*1*4/2-3---321*4*2/+3-
	i = strlen(post);
	for(i;i>=0;i--)
	{
		ch = post[i];
		if(isdigit(ch))
			push(&opst, ch-'0');
		else
		{
			op2 = pop(&opst);
			op1 = pop(&opst);
			switch(ch)
			{
				case '+': res = op2+op1;
					break;
				case '-': res = op2-op1;
					break;
				case '*': res = op2*op1;
					break;
				case '/': res = op2/op1;
					break;
			}
			push(&opst,res);
		}
	}
	res = pop(&opst);
	printf("result : %f", res);
}