#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef struct node
{
    int data;
    struct node* link;
} NODE;

typedef struct Queue
{
    int front, rear, capacity;
    int* array;
} Queue;

int visit[max] = {0};

void init_adj_list(NODE** a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = NULL;
}

NODE* getNode()
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    return temp;
}

NODE* create_list(NODE** head, int d, int n)
{
    NODE* cur;
    NODE* x = getNode();
    x->data = d;
    x->link = NULL;

    if (*head == NULL)
    {
        *head = x;
        return *head;
    }
    else
    {
        cur = *head;
        while (cur->link != NULL)
            cur = cur->link;
        cur->link = x;
        return *head;
    }
}

void display(NODE* a[max], int n)
{
    NODE* temp;
    for (int i = 0; i < n; i++)
    {
        printf("%d->", i);
        temp = a[i];
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int indegree(NODE** a, int n, int v)
{
    int c = 0;
    NODE* temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        while (temp != NULL)
        {
            if (temp->data == v)
                c++;
            temp = temp->link;
        }
    }
    return c;
}

int outdegree(NODE** a, int n, int v)
{
    int c = 0;
    NODE* temp = a[v];
    while (temp != NULL)
    {
        c++;
        temp = temp->link;
    }
    return c;
}

void dfs(NODE** a, int n, int s)
{
    NODE* p;
    int i;
    visit[s] = 1;
    printf("%d\t", s);
    for (p = a[s]; p != NULL; p = p->link)
    {
        i = p->data;
        if (!visit[i])
            dfs(a, n, i);
    }
}

void bfs(NODE** a, int n, int s)
{
    NODE* p;
    int i, j;
    visit[s] = 1;
    printf("%d\t", s);

    Queue* q = createQueue(n);
    enqueue(q, s);

    while (!isEmpty(q))
    {
        j = dequeue(q);

        for (p = a[j]; p != NULL; p = p->link)
        {
            i = p->data;
            if (!visit[i])
            {
                visit[i] = 1;
                printf("%d\t", i);
                enqueue(q, i);
            }
        }
    }
}

Queue* createQueue(int capacity)
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->capacity = capacity;
    q->array = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

bool isEmpty(Queue* q)
{
    return (q->front == -1);
}

void enqueue(Queue* q, int item)
{
    if (q->rear == q->capacity - 1)
        return;
    q->array[++q->rear] = item;
    if (q->front == -1)
        q->front = 0;
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
        return -1;
    int item = q->array[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return item;
}

int main()
{
    NODE* a[max];
    int n, ch, s, d, x;
    printf("enter the number of nodes");
    scanf("%d", &n);
    init_adj_list(a, n);

    do
    {
        printf("enter the operation to perform\n 1. create adj_list \n 2. in degree \n 3. out degree\n 4. bfs traversal\n 5. dfs traversal 6. display \n 7. exit");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("enter the source and destination of an edge");
            scanf("%d%d", &s, &d);
            a[s] = create_list(&(a[s]), d, n);
            break;
        case 2:
            printf("enter the node for which in degree has to be checked\n");
            scanf("%d", &x);
            printf("indegree of %d = %d", x, indegree(a, n, x));
            break;
        case 3:
            printf("enter the node for which out degree has to be checked\n");
            scanf("%d", &x);
            printf("outdegree of %d = %d", x, outdegree(a, n, x));
            break;
        case 4:
            printf("enter the source vertex\n");
            scanf("%d", &s);
            bfs(a, n, s);
            break;
        case 5:
            printf("enter the source vertex\n");
            scanf("%d", &s);
            dfs(a, n, s);
            break;
        case 6:
            printf("graph is\n");
            display(a, n);
            break;
        }
    } while (ch != 7);

    return 0;
}
