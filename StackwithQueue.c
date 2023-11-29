#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure to represent a Queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new QueueNode with the given data
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element into the Queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element from the Queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return -1; // Queue is empty
    int data = queue->front->data;
    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}

// Structure to represent a Stack using two Queues
struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

// Function to create a new Stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Function to push an element onto the Stack
void push(struct Stack* stack, int data) {
    enqueue(stack->q1, data);
}

// Function to pop an element from the Stack and return its dataue
int pop(struct Stack* stack) {
    if (stack->q1->front == NULL)
        return -1; // Stack is empty

    // Move all elements from q1 to q2 except the last one
    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    // Pop the last element from q1
    int poppeddataue = dequeue(stack->q1);

    // Swap q1 and q2 to maintain the order
    struct Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return poppeddataue;
}

int main() {
    int n, operation, dataue;
    scanf("%d", &n);
    struct Stack* stack = createStack();

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &operation, &dataue);
        if (operation == 1) {
            push(stack, dataue);
        } else if (operation == 2) {
            int poppeddataue = pop(stack);
            if (poppeddataue != -1) {
                printf("%d", poppeddataue);
            }
        }
    }

    return 0;
}

