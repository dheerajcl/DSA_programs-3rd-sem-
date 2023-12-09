#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int data;
	struct queue* next;
}Queue;

void init(Queue** ,Queue**);
void enqueue(Queue** front,Queue** rear,int ele);
void dequeue(Queue** front,Queue** rear);
void display(Queue** front,Queue** rear);

int main(){
	Queue* front = NULL;
	Queue* rear = NULL;

	init(&front,&rear);

	int ch,ele;

	while(1){

		printf("Enter the option : \n1. Enqueue\n2. Dequeue\n3. Display\n");
		scanf("%d",&ch);

		switch(ch){
			case 1 :
				printf("Enter the element :\n");
				scanf("%d",&ele);
				enqueue(&front,&rear,ele);
				break;

			case 2 :
				dequeue(&front,&rear);
				//printf("Deleted element is %d\n",ele);
				break;

			case 3 : 
				printf("Queue contents are : \n");
				display(&front,&rear);
				break; 
		}
	}


}

void init(Queue** front,Queue** rear){
	*front = NULL;
	*rear = NULL;
}

void enqueue(Queue** front,Queue** rear,int ele){
	Queue* t = malloc(sizeof(Queue*));
	t->data = ele;
	t->next = NULL;

	if(*front == NULL && *rear == NULL){
		*rear = t;
		*front = t;
		// (*front)->next = *rear;
	}
	else{
		(*rear)->next = t;
		*rear = t;
	}

}

void dequeue(Queue** front,Queue** rear){
	
	Queue* p = *front;

	if(*front==NULL && *rear==NULL){
		printf("Empty queue\n");
	}
	else if(*front == *rear){
		*front = NULL;
		*rear = NULL;
	}
	else{
		*front = (*front)->next;
	}

	printf("Delted element is %d\n",p->data);
	free(p);
	p = NULL;
}

void display(Queue** front,Queue** rear){
	Queue* temp = *front;

	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}

	printf("\n");

}