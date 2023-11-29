#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	int pr;
	struct node *link;
}NODE;

typedef struct PQueue
{
	NODE* start;
}PQueue;

void init(PQueue *pq)
{
	pq->start = NULL;
}

void enqueue(int ele, int pri, PQueue *pq)
{
	NODE* temp = malloc(sizeof(NODE));
	temp->data = ele;
	temp->link = NULL;
	if(pq->start == NULL)
		pq->start = temp;
	else if(pq->start->pr>=temp->pr)
	{
		temp->link = pq->start;
		pq->start = temp;
	}
	else
	{
		NODE* p=pq->start;
		NODE* befp = NULL;
		while(p!=NULL && p->pr<temp->pr)
		{
			befp = p;
			p= p->link;
		}
		temp->link = p;
			befp->link = temp;
			
	}

}
void dequeue(PQueue* pq)
{int ele =-1;
	if(pq->start == NULL)
		printf("empty\n");
	else
	{
		NODE* p = pq->start;
		pq->start= pq->start->link;
		ele = p->data;
		free(p);
	}	
	printf("deleted element is %d\n", ele);
}
int main()
{

return 0;
}
