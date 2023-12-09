/*
#include<stdio.h>
#include<stdio_ext.h>
#define max 10

// Global declaration.
int stack[max];
int top = -1;

void push(int data);
int pop();
int search(int data);
void display();

int main(){

	int ch,x;

	do{

		printf("Enter the choice : \n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.search\n");
		printf("4.seek\n");
		printf("5.display\n");
		printf("Enter 0 to exit.\n");

		scanf("%d",&ch);

		switch(ch){

			case 1 :
				printf("Enter the element : \n");
				scanf("%d",&x);
				push(x);
				break;

			case 2 : 
				x = pop();
				if(x==-1){
					printf("Stack Underflow.\n");
				}
				else{
					printf("Popped element is %d\n",x);
				}
				break;

			case 3:
				printf("Enter the element : \n");
				scanf("%d",&x);
				x = search(x);
				if(x==-1){
					printf("Element not found.\n");
				}
				else{
					printf("Element found at an index %d\n",x);
				}

				break;

			case 4 :
				if(top==-1){
					printf("Stack underflow\n");
				}
				else{
					printf("Element at top is %d\n",stack[top]);
				}
				break;

			case 5 :
				display();
				break;


			}

			printf("Enter any key to move on......\n");
			__fpurge(stdin);
			getc(stdin);

	}while(ch!=0);


	return 0;
}

void push(int data){
	if(top==max-1){
		printf("Stack overflow\n");
	}
	else{
		top++;
		stack[top] = data;
	}
}

int pop(){
	if(top==-1){
		return -1;
	}
	else{
		int toReturn = stack[top];
		top--;
		return toReturn;

		// or return top--;
	}
}

int search(int data){
	for(int i=0;i<=top;i++){
		if(stack[i]==data){
			return i;
		}
	}
	return -1;
}

void display(){
	for(int i=0;i<=top;i++){
		printf("%d ",stack[i]);
	}
	printf("\n");
}

***********************************************************************************************************************************************************************

*/

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

NODE* init();
NODE* push(NODE* head,int data);
int pop(NODE* head);
int search(NODE* head,int data);
void display(NODE* head);

int main(){

	int x,ch,che;
	NODE* stack = NULL;

	do{
		printf("Enter the choice : \n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.search\n");
		printf("4.seek\n");
		printf("5.display\n");
		printf("Enter 0 to exit.\n");

		scanf("%d",&ch);

		switch(ch){

			case 1 :
				printf("Enter the element : \n");
				scanf("%d",&x);
				stack = push(stack,x);
				break;

			case 2 : 
				x = pop(stack);
				if(x==-1){
					printf("Stack Underflow.\n");
				}
				else{
					printf("Popped element is %d\n",x);
				}
				break;

			case 3:
				printf("Enter the element : \n");
				scanf("%d",&x);
				x = search(stack,x);
				if(x==-1){
					printf("Element not found.\n");
				}
				else{
					printf("Element found at an index %d\n",x);
				}

				break;

			case 4 :
				if(stack==NULL){
					printf("Stack underflow\n");
				}
				else{
					printf("Element at top is %d\n",stack->data);
				}
				break;

			case 5 :
				display(stack);
				break;

			}


	}while(ch!=0);


	return 0;
}

NODE* init(){
	NODE* temp = malloc(sizeof(NODE));
	temp->next = NULL;
	return temp;
}

NODE* push(NODE* head,int data){
	NODE* temp = init();
	temp->data = data;
	temp->next = NULL;

	if(head==NULL){
		head = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}

	return head;
}

int pop(NODE* head){
	if(head==NULL){
		return -1;
	}
	else{
		int toReturn = head->data;
		NODE* p = head;
		head = head->next;
		free(p);
		return toReturn;
	}

}

int search(NODE* head,int data){
	NODE* p = head;
	int count=0;

	while(p!=NULL && p->data!=data){
		count++;
		p = p->next;
	}
	if(p==NULL){
		return -1;
	}
	else{
		return count;
	}
}

void display(NODE* head){
	NODE* temp = head;

	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}