#include<stdio.h>
#include<stdlib.h>

// Define a node in the priority queue
typedef struct node
{
    int data; // The data stored in the node
    int priority; // The priority of the node
    struct node *next; // Pointer to the next node
} Node;

// Define the priority queue
typedef struct PriorityQueue
{
    Node* head; // The first node in the queue
} PriorityQueue;

// Initialize the priority queue
void initialize(PriorityQueue *pq)
{
    pq->head = NULL; // Set the head to NULL
}

// Add an element to the priority queue
void enqueue(int element, int priority, PriorityQueue *pq)
{
    // Create a new node
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->priority = priority;
    newNode->next = NULL;

    // If the queue is empty, add the new node as the head
    if(pq->head == NULL)
        pq->head = newNode;
    // If the new node has higher priority than the head, add it at the beginning
    else if(pq->head->priority >= newNode->priority)
    {
        newNode->next = pq->head;
        pq->head = newNode;
    }
    else
    {
        // Find the correct position to insert the new node
        Node* current = pq->head;
        Node* previous = NULL;
        while(current != NULL && current->priority < newNode->priority)
        {
            previous = current;
            current = current->next;
        }
        // Insert the new node at the correct position
        newNode->next = current;
        previous->next = newNode;
    }
}

// Remove the highest priority element from the priority queue
void dequeue(PriorityQueue* pq)
{
    int element = -1;
    if(pq->head == NULL)
        printf("Queue is empty\n");
    else
    {
        Node* temp = pq->head;
        pq->head = pq->head->next;
        element = temp->data;
        free(temp);
    }	
    printf("Deleted element is %d\n", element);
}

int main()
{
    // The main function is empty in this code
    return 0;
}