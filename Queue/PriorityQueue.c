#include <stdio.h>
#define MAX_SIZE 15

typedef struct InputInfo
{
    int data;
    int priority;
} Info;

typedef struct PriorityQueue
{
    Info queue[MAX_SIZE];
    int front;
    int rear;
} PriorityQueue;

int count = 0;

void initialize(PriorityQueue *pq)
{
    pq->front = 0;
    pq->rear = -1;
}

int isEmpty(PriorityQueue *pq)
{
    return (pq->front > pq->rear);
}

int isFull(PriorityQueue *pq)
{
    return (pq->rear == MAX_SIZE - 1);
}

void enqueue(PriorityQueue *pq, int element, int elementPriority) 
{
    int i;

    if (isFull(pq))
        printf("Queue is full\n");
    else
    {
        i = pq->rear;
        pq->rear++;
        while (pq->queue[i].priority >= elementPriority && i >= 0)
        {
            pq->queue[i + 1] = pq->queue[i];
            i--;
        }
        pq->queue[i + 1].data = element;
        pq->queue[i + 1].priority = elementPriority;
    }
}

int dequeue(PriorityQueue *pq)
{
    int element;
    if (isEmpty(pq))
    {
        printf("Queue is empty\n");
        element = -1;
    }
    else
    {
        element = pq->queue[pq->front].data;
        pq->front++;
    }
    return element;
}

void display(PriorityQueue *pq)
{
    int index = pq->front;
    while (index <= pq->rear)
    {
        printf("%d\t", pq->queue[index].data);
        index++;
    }
}

int frontOfQueue(PriorityQueue *pq)
{
    return (pq->queue[pq->front].data);
}

int main()
{
    PriorityQueue pq;
    initialize(&pq);
    int choice, element, elementPriority;
    while (1)
    {
        printf("Enter the operation to be performed:\n");
        printf("1-Enqueue\n2-Dequeue\n3-Display\n4-IsEmpty\n5-FrontOfQueue\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element and its priority\n");
            scanf("%d%d", &element, &elementPriority);
            enqueue(&pq, element, elementPriority);
            count++;
            break;
        case 2:
            element = dequeue(&pq);
            printf("Deleted element is %d\n", element);
            count--;
            break;
        case 3:
            printf("Queue contents are:\n");
            display(&pq);
            break;
        case 4:
            if (isEmpty(&pq))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 5:
            printf("Front value= %d\n", frontOfQueue(&pq));
            break;
        }
    }
    return 0;
}