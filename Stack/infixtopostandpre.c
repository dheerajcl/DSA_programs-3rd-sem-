#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max 45

char stack[max];
int top = -1;

void push(int ele)
{
	if (top == max - 1)
		printf("Overflow\n");
	else
	{
		top++;
		stack[top] = ele;
	}
}
char pop()
{
	char x;
	if (top == -1)
	{
		printf("UNDERFLOW\n");
		return '\0'; // return a default value
	}
	else
	{
		x = stack[top];
		top--;
	}
	return x;
}
int isempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
int precedence(char x)
{
	if (x == '^')
		return 3;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '+' || x == '-')
		return 1;
	else
		return 0;
}

void infix_to_postfix(char *in, char *post)
{
	int i, j = 0;
	char ss, x;
	for (i = 0; in[i] != '\0'; i++)
	{
		ss = in[i];
		if (isalnum(ss))
			post[j++] = ss;
		else if (ss == '(')
			push(ss);
		else if (ss == ')')
		{
			while ((x = pop()) != '(')
			{
				post[j++] = x;
			}
		}
		else
		{
			while (precedence(ss) <= precedence(stack[top]))
			{
				post[j++] = pop();
			}
			push(ss);
		}
	}
	while (!isempty())
	{
		post[j++] = pop();
	}
	post[j] = '\0';
}

void infix_to_prefix(char *in, char *pre)
{
    int i, j = 0;
    char ss, x;
    int len = strlen(in);

    // Reverse the infix expression and replace '(' with ')' and vice versa
    for (i = 0; i < len / 2; i++)
    {
        char temp = in[i];
        in[i] = in[len - i - 1] == '(' ? ')' : in[len - i - 1] == ')' ? '(' : in[len - i - 1];
        in[len - i - 1] = temp == '(' ? ')' : temp == ')' ? '(' : temp;
    }

    // Convert the modified infix expression to postfix
    for (i = 0; in[i] != '\0'; i++)
    {
        ss = in[i];
        if (isalnum(ss))
            pre[j++] = ss;
        else if (ss == '(')
            push(ss);
        else if (ss == ')')
        {
            while ((x = pop()) != '(')
            {
                pre[j++] = x;
            }
        }
        else
        {
            while (!isempty() && precedence(ss) <= precedence(stack[top]))
            {
                pre[j++] = pop();
            }
            push(ss);
        }
    }
    while (!isempty())
    {
        pre[j++] = pop();
    }
    pre[j] = '\0';

    // Reverse the postfix expression to get the prefix expression
    for (i = 0; i < j / 2; i++)
    {
        char temp = pre[i];
        pre[i] = pre[j - i - 1];
        pre[j - i - 1] = temp;
    }
}


int main()
{
    char in[20], in_copy[20], post[20], pre[20];
    printf("enter the infix expression:\n");
    scanf("%s",in);
    strcpy(in_copy, in); // copy the original infix expression
    infix_to_postfix(in, post);
    infix_to_prefix(in_copy, pre); // use the copy for infix_to_prefix
    printf("postfix expression is %s\n", post);
    printf("prefix expression is %s\n", pre); // print the prefix expression
    return 0;
}