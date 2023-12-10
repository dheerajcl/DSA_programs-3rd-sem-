#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node
{
	int data;
	struct node* link;
}NODE;

int visit[max]={0};

void init_adj_list(NODE** a, int n)
{
	for(int i=0;i<n;i++)
		a[i] = NULL;
}
NODE* getNode()
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	return temp;
}

NODE* create_list(NODE** head, int d,int n)
{
	NODE* cur;
	NODE* x =getNode();
	x->data = d;
	x->link = NULL;
	
	if(*head==NULL)
	{	
		*head = x;
		return *head;
	}
	else
	{
		cur = *head;
		while(cur->link!=NULL)
			cur = cur->link;
		cur->link = x;
		return *head;
	}
}

void display(NODE* a[max], int n)
{
	NODE* temp;
	for(int i=0;i<n;i++)
	{
		printf("%d->",i);
		temp = a[i];
		while(temp!=NULL)
		{	printf("%d->", temp->data);
			temp=temp->link;
		} 
		printf("\n");
	}

}
int indegree(NODE** a,int n,int v)
{
	int c=0;
	NODE* temp;
	for(int i=0;i<n;i++)
	{
		temp = a[i];
		while(temp!=NULL)
		{	if(temp->data==v)
				c++;
			temp=temp->link;
		}
	}
	return c;
}
int outdegree(NODE** a,int n,int v)
{
	int c=0;
	NODE* temp = a[v];
	for(int i=0;i<n;i++)
	{
		while(temp!=NULL)
		{
			c++;
			temp = temp->link;
		}
	}
	return c;
}
void dfs(NODE** a, int n, int s)
{
	NODE* p;int i;
	visit[s] = 1;
	printf("%d\t", s);
	for(p=a[s];p!=NULL;p=p->link)
	{
		i = p->data;
		if(!visit[i])
			dfs(a,n,i);
	}
}		

int main()
{
	NODE* a[max];
	int n,ch,s,d,x;
	printf("enter the number of nodes");
	scanf("%d", &n);
	init_adj_list(a,n);
	
	do
	{
		printf("enter th operation to perform\n 1. create adj_list \n 2. in degree \n 3. out degree\n 4. bfs traversal\n 5. dfs traversal 6. display \n 7. exit");
		scanf("%d", &ch);
	
		switch(ch)
		{
			case 1: printf("enter the source and destination of an edge");
				scanf("%d%d", &s,&d); 
				a[s] = create_list(&(a[s]),d,n);
				break;
			case 2: printf("enter the node for which in degree has to be checked\n");
				scanf("%d", &x);
				printf("indegree of %d = %d", x, indegree(a,n,x));
				break;
			case 3: printf("enter the node for which out degree has to be checked\n");
				scanf("%d", &x);
				printf("outdegree of %d = %d", x, outdegree(a,n,x));
				break;
			/*case 4: printf("enter the source vertex\n");
				scanf("%d", &s);
				bfs(a,n);
				break;*/
			case 5: printf("enter the source vertex\n");
				scanf("%d", &s);
				dfs(a,n,s);
				break;
			case 6: printf("graph is\n");
				display(a,n);
				break;
			
		}}while(1);
	
return 0;
}

/*NODE* create_list(NODE** a, int s,int d)
{
	NODE* cur;
	NODE* x =getNode();
	x->data = d;
	x->link = NULL;

	cur = a[s];
	if(cur==NULL)
		a[i] = x;
	else
	{
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = x;
	}
}*/