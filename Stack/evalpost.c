#include<stdio.h>
#include<ctype.h>
#define max 10
typedef struct stack
{
	float s[max];
	int top;
}STACK;

void init(STACK* ST)
{
	ST->top = -1;
}

void push(STACK* st, float s)
{
	if(st->top==max-1)
		printf("Overflow\n");
	else
	{
		st->top++;
		st->s[st->top] = s;
	}
}

float pop(STACK* st){
float x;
	if(st->top==-1)
		printf("UNDERflow\n");
	else
	{
		x = st->s[st->top];
		st->top--;
	}
	return x;
}

float evaluate_post(STACK* st, char* post)
{
	float res;
	int i;
	float op1,op2;
	char ss;
	for(i=0;post[i]!='\0';i++)
	{	ss = post[i];
		if(isdigit(ss))
			push(st,ss-'0');//st
		else 
		{	
			op2 = pop(st);
			op1 = pop(st);
			if(ss == '+')
				res = op1+op2;
			else if(ss == '-')
				res = op1-op2;
			else if(ss == '*')
				res = op1*op2;
			else if(ss == '/')
				res = op1/op2;
			else
				printf("invalid \n");
			push(st, res);
		}	
	}
	res = pop(st);
return res;
}
int main()
{
	STACK st;
	init(&st);
	char post[10];
	printf("enter the postfix expression\n");
	gets(post);
	float res = evaluate_post(&st, post);
	printf("output = %f\n", res);
return 0;
}