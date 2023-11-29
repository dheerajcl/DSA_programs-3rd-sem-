#include<stdio.h>
#define max 50
typedef struct PQueue
{
	int a[max];
	int n;
}PQ;

void init_pq(PQ* ppq)
{
	ppq->n = 0;
}
void disp(PQ *ppq)
{
	for(int i=0; i<ppq->n;i++)
		printf("%d\t", ppq->a[i]);
}
int enqueue(PQ* ppq, int ele)
{
	int p,c;
	if(ppq->n == max)	//full condition
		return 0;
	ppq->a[ppq->n] = ele;	//placing at last position

	c = ppq->n;		//instead of c=i
	p = (c-1)/2;
	while(c>0 && ppq->a[p]<ele)
	{
		ppq->a[c] = ppq->a[p];
		c = p;
		p = (c-1)/2;
	}
	ppq->a[c] = ele;
	ppq->n++;		//inc. no. of ele
	return 1;
}
	
int dequeue(PQ* ppq, int* pe)
{
	int p,c,ele;
	
	if(ppq->n==0)		//empty queue
		return 0;

	*pe = ppq->a[0];	//adding a pointer pointing to root node dataue that will be returned
		//earlier we were doing a[i] = a[0] but now we are removing the root element from the queue

	ele = ppq->a[ppq->n-1];	//storing the last elements
		
	p = 0;
	if(ppq->n==1)
	 c = -1;
	else
	 c = 1;
	if(ppq->n>2 && ppq->a[2]>ppq->a[1])
	 c = 2;
	while(c>0 && ppq->a[c]>ele)
	{
		ppq->a[p] = ppq->a[c];
		p = c;
		c = 2*p+1;
		if(c+1<=ppq->n-1&& ppq->a[c+1]>ppq->a[c])
		 c =c+1;
		if(c>=ppq->n-1)	//=
		 c = -1;
	}
	ppq->a[p] = ele;
	ppq->n--;
	return 1;
}
void main()
{
	PQ ppq;
	init_pq(&ppq);
	int ch,ele,k;
	do
	{
		switch(ch)
		{
		 case 1: printf("enter the element\n");
			 scanf("%d", &ele);
			 enqueue(&ppq, ele);
			 break;
		 case 2: k = dequeue(&ppq ,&ele);
			 if(!k)
				printf("empty queue\n");
			 else
				printf("deleted no. is %d\n", ele);
			 break;
		 case 3: disp(&ppq);
			 break;
		}
		printf("enter the choice \n");
		scanf("%d", &ch);
	}while(ch!=0);

}