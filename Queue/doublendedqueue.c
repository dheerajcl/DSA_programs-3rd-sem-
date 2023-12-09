#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}NODE;

typedef struct queue{
	NODE* front;
	NODE* rear;
}Queue;

void init(Queue* pq){
	pq->front = NULL;
	pq->rear = NULL;
}

void insert_at_front(Queue* pq,int data){

	NODE* temp = malloc(sizeof(NODE*));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	if(pq->front == NULL && pq->rear == NULL){
		pq->front = pq->rear = temp;
	}
	else{
		temp->right = pq->front;
		pq->front->left = temp;
		pq->front = temp;
	}

}

void insert_at_last(Queue* pq,int data){

	NODE* temp = malloc(sizeof(NODE*));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;


	if(pq->front == NULL && pq->rear == NULL){
		pq->front = pq->rear = temp;
	}
	else{
		temp->left = pq->rear;
		pq->rear->right = temp;
		pq->rear = temp;
	}


}

int delete_at_front(Queue* pq){
	NODE* toDelete;
	int ans = -1;

	if(pq->front == NULL){
		printf("There is nothing in front of the queue.\n");
	}
	else if (pq->front == pq->rear){
		toDelete = pq->front;
		ans = toDelete->data;
		pq->front = NULL;
		pq->rear = NULL;
	}
	else{
		toDelete = pq->front;
		ans = toDelete->data;
		pq->front = pq->front->right;
		pq->front->left = NULL;
	}


	free(toDelete);
	return ans;

}

int delete_at_last(Queue* pq){
	NODE* toDelete;
	int ans = -1;

	if(pq->rear == NULL){
		printf("There is nothing in rear of the queue.\n");
	}
	else if (pq->front == pq->rear){
		toDelete = pq->rear;
		ans = toDelete->data;
		pq->front = NULL;
		pq->rear = NULL;
	}
	else{
		toDelete = pq->rear;
		ans = toDelete->data;
		pq->rear = pq->rear->left;
		pq->rear->right = NULL;
	}


	free(toDelete);
	return ans;

}

void display(Queue* pq){
	NODE* start = pq->front;

	printf("Queue contents are : \n");

	while(start != NULL){
		printf("%d ",start->data);
		start = start->right;
	}

	printf("\n");
}

int main(){

	Queue pq;
	int k,x,ch;
	init(&pq);
	printf("Enter the operation to be performed \n");

	do{
		printf("1. Insert at Beginning\n2. Insert at last\n3. Delete at beginning\n4. Delete at last\n5. Display\n\n");
		scanf("%d",&ch);

		switch(ch){

			case 1 :
				printf("Enter the element : \n");
				scanf("%d",&x);
				insert_at_front(&pq,x);
				break;
				

			case 2 : 
				printf("Enter the element : \n");
				scanf("%d",&x);
				insert_at_last(&pq,x);
				break;


			case 3 : 
				k = delete_at_front(&pq);
				printf("Element deleted is %d\n",k);
				break;

			case 4 : 
				k = delete_at_last(&pq);
				printf("Element deleted is %d\n",k);
				break;

			case 5 :
				display(&pq);
				break;
		}

	}while(ch<6);

	return 0;

}