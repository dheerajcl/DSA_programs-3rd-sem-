#include <stdio.h>
#include <stdlib.h>

// Define a structure for queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define a structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Initialize a queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Enqueue a new element to the queue
void enqueue(struct Queue* q, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1; // You may want to handle this error differently
    }

    struct QueueNode* temp = q->front;
    int data = temp->data;

    q->front = temp->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

// Push an element onto the stack
void push(struct Queue* q1, struct Queue* q2, int data) {
    // Enqueue the element to q2
    enqueue(q2, data);

    // Dequeue all elements from q1 and enqueue to q2
    while (!isEmpty(q1)) {
        enqueue(q2, dequeue(q1));
    }

    // Swap q1 and q2
    struct Queue* temp = q1;
    q1 = q2;
    q2 = temp;
}

// Pop the top element from the stack
int pop(struct Queue* q1) {
    if (isEmpty(q1)) {
        printf("Error: Stack is empty\n");
        return -1; // You may want to handle this error differently
    }

    return dequeue(q1);
}

// Get the top element of the stack without popping it
int top(struct Queue* q1) {
    if (isEmpty(q1)) {
        printf("Error: Stack is empty\n");
        return -1; // You may want to handle this error differently
    }

    return q1->front->data;
}

int main() {
    struct Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    push(&q1, &q2, 1);
    push(&q1, &q2, 2);
    push(&q1, &q2, 3);

    printf("Top element: %d\n", top(&q1));
    printf("Popped element: %d\n", pop(&q1));

    printf("Top element: %d\n", top(&q1));

    return 0;
}
