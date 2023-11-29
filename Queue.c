#include<stdio.h>
#define max 15

typedef struct queue
{
	int q[max];
	int rear;
	int front;
}QUEUE;

void init(QUEUE* pq)
{
	pq->front = 0;
	pq->rear = -1;
}

int isempty(QUEUE* pq)
{
	return(pq->front > pq->rear);
}
int isfull(QUEUE* pq)
{
	return(pq->rear==max-1);	
}
void enqueue(QUEUE* pq, int ele)
{
	if(isfull(pq))
		printf("Q is full\n");
	else
	{
		pq->rear++;
		pq->q[pq->rear] = ele;
	}
}

int dequeue(QUEUE* pq)
{	int ele=-1;
	if(isempty(pq))
		printf("Q is empty\n");
	
	else
	{
		ele = pq->q[pq->front];
		pq->front++;
	}
	return ele;
	
}
void display(QUEUE* pq)
{
	int p = pq->front;
	while(p<=pq->rear)
	{
		printf("%d\t", pq->q[p]);
		p++;
	}	
}
int ToQ(QUEUE* pq)
{
	return(pq->q[pq->rear]);

}

int main()
{
	QUEUE pq;
	init(&pq);
	int ch,ele;
	while(1)
	{	printf("enter the operation to be performed:\n");
		printf("1-enqueue\n2-dequeue\n3-display\n4-isempty\n5-ToQ\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("enter the number\n");
				scanf("%d", &ele);
				enqueue(&pq,ele);
				break;
			case 2: ele = dequeue(&pq);
				printf("deleted number=%d\n",ele);
				break;
			case 3: printf("queue contents\n");
				display(&pq);
				break;
			case 4: ele = isempty(&pq);
				if(ele==1)
					printf("empty queue\n");
				else
					printf("Not empty queue\n");
				break;
			case 5: printf("top of the queue = %d\n", ToQ(&pq));
				break;
		}
	}
return 0;
}