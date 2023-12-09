#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to find the midpoint of the linked list using fast and slow pointers
struct Node* findMidpoint(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to split the linked list into two parts at the given node
void splitList(struct Node* head, struct Node** firstHalf, struct Node** secondHalf, struct Node* midpoint) {
    if (midpoint == NULL) {
        return;
    }

    *firstHalf = head;
    *secondHalf = midpoint->next;
    midpoint->next = NULL;
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    struct Node* midpoint = findMidpoint(head);
    struct Node* firstHalf = NULL;
    struct Node* secondHalf = NULL;
    splitList(head, &firstHalf, &secondHalf, midpoint);

    printList(firstHalf);
    printList(secondHalf);

    return 0;
}
