#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;

typedef struct stack
{
    NODE* st[15];
    int top;
}STACK;

typedef struct Etree{
    NODE* root;
}ETREE;

void init_stack(STACK *s)
{
    s->top=-1;
}

void init_etree(ETREE *t)
{
    t->root=NULL;
}

NODE* push(STACK *s,NODE* temp)
{
    s->top++;
    s->st[s->top]=temp;
    return temp;
}

NODE* pop(STACK *s)
{
    NODE* temp;
    temp=s->st[s->top];
    s->top--;
    return temp;
}

int main()
{
    char postfix[50];
    int i;
    printf("Enter postfix expression: ");
    gets(postfix);
    STACK S;
    ETREE T;
    init_stack(&S);
    init_etree(&T);
    NODE *temp;
    for(i=0;postfix[i]!='\0';i++){
        temp=malloc(sizeof(NODE));
        temp->data=postfix[i];
        temp->left=NULL;
        temp->right=NULL;
        if(isdigit(postfix[i])){
            push(&S,temp);
        }
        else{
            temp->right=pop(&S);
            temp->left=pop(&S);
            push(&S,temp);
        }
    }
    T.root=pop(&S);
    printf("the result is = %d",evaluate(&T));
    return 0;
}

int evaluate(ETREE *T){
    return eval(T->root);
}

int eval(NODE *p){
    int res;
    switch(p->data)
    {
        case '+':res=eval(p->left)+eval(p->right);
        break;
        case '-':res=eval(p->left)-eval(p->right);
        break;
        case '*':res=eval(p->left)*eval(p->right);
        break;
        case '/':res=eval(p->left)/eval(p->right);
        break;
        default: return(p->data-'0');
    }
}