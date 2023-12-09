#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
typedef struct Node {
    int index;
    struct Node* next;
} Node;

// Function to create a new node with a given index
Node* createNode(int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

// Function to create and populate the circular linked list
Node* createCircularLinkedList(int n) {
    Node* head = createNode(1);
    Node* current = head;

    // Create and link the remaining nodes
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    // Make it circular by linking the last node to the head
    current->next = head;

    return head;
}

// Function to simulate the elimination process based on the Josephus Problem
int josephus(int n, int k) {
    Node* head = createCircularLinkedList(n);
    Node* current = head;
    Node* prev = NULL;

    while (n > 1) {
        // Find the k-th person to eliminate
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }

        // Eliminate the current person
        prev->next = current->next;
        free(current);
        current = prev->next;
        n--;
    }

    // Return the index of the last person remaining
    int lastPersonIndex = current->index;
    free(current);
    return lastPersonIndex;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int lastPersonIndex = josephus(n, k);

    printf("%d\n", lastPersonIndex);

    return 0;
}
