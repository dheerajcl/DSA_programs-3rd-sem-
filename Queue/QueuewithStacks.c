#include <stdio.h>
#include <stdlib.h>

// Define a structure for stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Define a structure for the stack
struct Stack {
    struct StackNode* top;
};

// Initialize a stack
void initStack(struct Stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return (s->top == NULL);
}

// Push an element onto the stack
void push(struct Stack* s, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop the top element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty\n");
        return -1; // You may want to handle this error differently
    }

    struct StackNode* temp = s->top;
    int data = temp->data;

    s->top = temp->next;
    free(temp);

    return data;
}

// Enqueue an element to the queue
void enqueue(struct Stack* s1, struct Stack* s2, int data) {
    // Push the element onto s1
    push(s1, data);
}

// Dequeue an element from the queue
int dequeue(struct Stack* s1, struct Stack* s2) {
    // If s2 is empty, transfer elements from s1 to s2
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }

    // Pop the top element from s2
    return pop(s2);
}

int main() {
    struct Stack s1, s2;
    initStack(&s1);
    initStack(&s2);

    enqueue(&s1, &s2, 1);
    enqueue(&s1, &s2, 2);
    enqueue(&s1, &s2, 3);

    printf("Dequeued element: %d\n", dequeue(&s1, &s2));

    enqueue(&s1, &s2, 4);

    printf("Dequeued element: %d\n", dequeue(&s1, &s2));
    printf("Dequeued element: %d\n", dequeue(&s1, &s2));

    return 0;
}
