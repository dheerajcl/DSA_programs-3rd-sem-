#include<stdio.h>
#define max 50

char S[max];
int top = -1;

void push(char x);
char pop();
int pm(char *c);

int main()
{
    char ch[max];
    printf("enter the string: ");
    scanf("%49s", ch); // limit the input to prevent buffer overflow
    int res = pm(ch);
    if (res==1)
        printf("balanced\n");
    else
        printf("unbalanced\n");
    return 0;
}

int pm(char* c)
{
    int i=0;
    while(c[i]!='\0')
    {
        if(c[i]=='(' || c[i]=='[' || c[i]=='{')
            push(c[i]);
        else if(c[i]==')' || c[i]==']' || c[i]=='}')
        {
            if(top==-1)
                return 0;
            char opening = pop();
            if((c[i]==')' && opening!='(') || (c[i]==']' && opening!='[') || (c[i]=='}' && opening!='{'))
                return 0;
        }
        i++;
    }
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(char x)
{
    if(top == max-1)
        return;
    else
    {
        top++;
        S[top] = x;
    }
}

char pop()
{
    if(top == -1)
        return '\0';
    else
    {
        char x = S[top];
        top--;
        return x;
    }
}