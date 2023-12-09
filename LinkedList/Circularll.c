#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

void display(NODE* head);
NODE* init();
NODE* insert_at_beg(NODE* head);
NODE* insert_at_end(NODE* head);
NODE* insert_at_any(NODE* head, int index);
NODE* delete_at_beg(NODE* head);
NODE* delete_at_end(NODE* head);
NODE* delete_at_anykey(NODE* head, int key);
NODE* delete_at_any_index(NODE* head, int index);
NODE* delete_entirelist(NODE* head);
NODE* search_element(NODE* head, int ele);
NODE* reverseList(NODE* head);
NODE* sort_ascending(NODE* head);
NODE* sort_descending(NODE* head);
NODE* del_evenNodes(NODE* head);
NODE* concat(NODE* head, NODE* head2);
void count_all_keys(NODE* head);
NODE* delete_duplicates(NODE* head);
NODE* delete_duplicates1(NODE* head);

int main() {
    NODE* head = NULL;   // list declaration locally
    int ch;
    do {
        printf("Enter the choice:\n 0.Exit\n 1.Display\n 2.Insert at beginning\n 3.Insert at end\n 4.Insert at any position\n 5.Delete at beginning\n 6.Delete at last\n 7.Delete at any key\n 8.Delete at any position\n 9.Delete entire list\n 10.Search element\n 11.Reverse list\n 12.Sort ascending\n 13.Sort descending\n 14.Delete even nodes\n 15.Concat\n 16.Count all keys\n 17.Delete duplicates\n 18.Delete duplicates1\n");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                printf("Exited from list successfully\n");
                exit(1);
            case 1:
                printf("List contents:\n");
                display(head);
                break;
            case 2:
                printf("Entered choice is to insert at beginning:\n");
                head = insert_at_beg(head);
                break;
            case 3:
                printf("Entered choice is to insert at end\n");
                head = insert_at_end(head);
                break;
            case 4:
                printf("Enter the index after which node\n");
                int index;
                scanf("%d", &index);
                head = insert_at_any(head, index);
                break;
            case 5:
                printf("Entered choice is delete at beg:\n");
                head = delete_at_beg(head);
                break;
            case 6:
                printf("Entered choice is delete at end:\n");
                head = delete_at_end(head);
                break;
            case 7:
                printf("Enter the key you need to delete:\n");
                int key;
                scanf("%d", &key);
                head = delete_at_anykey(head, key);
                break;
            case 8:
                printf("Enter the index you need to delete:\n");
                int index1;
                scanf("%d", &index1);
                head = delete_at_any_index(head, index1);
                break;
            case 9:
                printf("Entered operation is to delete entire list\n");
                head = delete_entirelist(head);
                break;
            case 10:
                printf("Enter the element you need to search:\n");
                int ele;
                scanf("%d", &ele);
                head = search_element(head, ele);
                break;
            case 11:
                printf("Entered operation is to reverse the list\n");
                head = reverseList(head);
                break;
            case 12:
                printf("Entered operation is to sort the list in ascending order\n");
                head = sort_ascending(head);
                break;
            case 13:
                printf("Entered operation is to sort the list in descending order\n");
                head = sort_descending(head);
                break;
            case 14:
                printf("Entered operation is to delete even nodes\n");
                head = del_evenNodes(head);
                break;
            case 15:
                printf("Entered operation is to concatenate two lists\n");
                head = concat(head, head);
                break;
            case 16:
                printf("Entered operation is to count all keys\n");
                count_all_keys(head);
                break;
            case 17:
                printf("Entered operation is to delete duplicates\n");
                head = delete_duplicates(head);
                break;
            case 18:
                printf("Entered operation is to delete duplicates\n");
                head = delete_duplicates1(head);
                break;
            default:
                printf("Enter a valid choice:\n");
        }
    } while (ch != 0);
}

void display(NODE* head) {
    NODE* p = head;
    if (head == NULL)
        printf("Circular singly linked list is empty\n");
    else {
        do {
            printf("%d--->", p->data);
            p = p->next;
        } while (p != head);
        printf("\n");
    }
}

NODE* init() {
    NODE* temp = malloc(sizeof(NODE));
    return temp;
}

NODE* insert_at_beg(NODE* head) {
    NODE* temp = init();
    printf("Enter the data:");
    scanf("%d", &temp->data);
    temp->next = temp;
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        NODE* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = temp;
        head = temp;
    }
    return head;
}

NODE* insert_at_end(NODE* head) {
    NODE* temp = init();
    printf("Enter the data:");
    scanf("%d", &temp->data);
    temp->next = temp;
    if (head == NULL) {
        head = temp;
    } else {
        NODE* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
    }
    return head;
}

NODE* insert_at_any(NODE* head, int index) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* temp = init();
        printf("Enter the data:");
        scanf("%d", &temp->data);
        temp->next = temp;
        int count = 0;
        NODE* p = head;
        while (p->next != head && count < index) {
            p = p->next;
            count++;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return head;
}

NODE* delete_at_beg(NODE* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* temp = head;
        NODE* p = head;
        while (p->next != head) {
            p = p->next;
        }
        head = head->next;
        p->next = head;
        free(temp);
        temp = NULL;
    }
    return head;
}

NODE* delete_at_end(NODE* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* p = head;
        NODE* befp = NULL;
        while (p->next != head) {
            befp = p;
            p = p->next;
        }
        if (p == head) {
            head = NULL;
        } else {
            befp->next = head;
        }
        free(p);
        p = NULL;
    }
    return head;
}

NODE* delete_at_anykey(NODE* head, int key) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* temp = head;
        NODE* befp = NULL;
        while (temp->data != key && temp->next != head) {
            befp = temp;
            temp = temp->next;
        }
        if (temp->data == key) {
            if (temp == head) {
                head = head->next;
                if (temp->next != head) {
                    NODE* p = head;
                    while (p->next != head) {
                        p = p->next;
                    }
                    p->next = head;
                } else {
                    head = NULL;
                }
            } else {
                befp->next = temp->next;
            }
            free(temp);
            temp = NULL;
        }
    }
    return head;
}

NODE* delete_at_any_index(NODE* head, int index) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        int count1 = 0;
        NODE* befp = NULL;
        NODE* temp = head;
        while (count1 < index) {
            befp = temp;
            temp = temp->next;
            count1++;
        }
        if (count1 == index) {
            if (temp == head) {
                head = head->next;
                if (temp->next != head) {
                    NODE* p = head;
                    while (p->next != head) {
                        p = p->next;
                    }
                    p->next = head;
                } else {
                    head = NULL;
                }
            } else {
                befp->next = temp->next;
            }
            free(temp);
            temp = NULL;
        } else {
            printf("Index out of bounds\n");
        }
    }
    return head;
}

NODE* delete_entirelist(NODE* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* p = head;
        NODE* temp;
        do {
            temp = p;
            p = p->next;
            free(temp);
        } while (p != head);
        printf("Circular singly linked list deleted successfully\n");
        head = NULL;
    }
    return head;
}

NODE* search_element(NODE* head, int ele) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* p = head;
        int count2 = 0;
        do {
            if (p->data == ele) {
                printf("The element is found at %d position\n", count2 + 1);
                return head;
            }
            p = p->next;
            count2++;
        } while (p != head);
        printf("The element is not found\n");
    }
    return head;
}

NODE* reverseList(NODE* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* current = head;
        NODE* prev = NULL;
        NODE* nextNode = NULL;
        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);
        head->next = prev;
        head = prev;
    }
    return head;
}

NODE* sort_ascending(NODE* head) {
    if (head == NULL || head->next == head) {
        // If the list is empty or only contains one element, it is already sorted
        return head;
    }
    NODE* p;
    NODE* q;
    int temp;
    do {
        int swapped = 0;
        p = head;
        q = p->next;
        do {
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                swapped = 1;
            }
            p = p->next;
            q = q->next;
        } while (q != head);
    } while (p != head);
    return head;
}

NODE* sort_descending(NODE* head) {
    if (head == NULL || head->next == head) {
        // If the list is empty or only contains one element, it is already sorted
        return head;
    }
    NODE* p;
    NODE* q;
    int temp;
    do {
        int swapped = 0;
        p = head;
        q = p->next;
        do {
            if (p->data < q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                swapped = 1;
            }
            p =            p->next;
            q = q->next;
        } while (q != head);
    } while (p != head);
    return head;
}

NODE* del_evenNodes(NODE* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* temp = head;
        NODE* befp = NULL;
        int count3 = 0;
        do {
            count3++;
            if (count3 % 2 == 0) {
                befp->next = temp->next;
                free(temp);
                temp = befp->next;
            } else {
                befp = temp;
                temp = temp->next;
            }
        } while (temp != head);
    }
    return head;
}

NODE* concat(NODE* head, NODE* head2) {
    if (head == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head;
    }

    NODE* p = head;
    while (p->next != head) {
        p = p->next;
    }
    p->next = head2;

    p = head2;
    while (p->next != head2) {
        p = p->next;
    }
    p->next = head;

    return head;
}

void count_all_keys(NODE* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* p = head;
        NODE* q;
        int count;
        do {
            count = 0;
            q = head;
            // Check if we've seen this element before
            do {
                if (q->data == p->data) {
                    break;
                }
                q = q->next;
            } while (q != head);
            // If we haven't seen this element before, count how many times it appears
            if (q == p) {
                q = p;
                do {
                    if (q->data == p->data) {
                        count++;
                    }
                    q = q->next;
                } while (q != head);
                printf("Element %d appears %d times\n", p->data, count);
            }
            p = p->next;
        } while (p != head);
    }
}

NODE* delete_duplicates(NODE* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty\n");
    } else {
        NODE* p = head;
        NODE* q;
        NODE* duplicate;
        do {
            q = p;
            do {
                if (p->data == q->next->data) {
                    // Duplicate found, so delete it
                    duplicate = q->next;
                    q->next = q->next->next;
                    free(duplicate);
                } else {
                    q = q->next;
                }
            } while (q->next != head);
            p = p->next;
        } while (p->next != head);
    }
    return head;
}

NODE* delete_duplicates1(NODE* head) {
    head = sort_ascending(head);
    NODE* p = head;
    NODE* q;
    do {
        if (p->data == p->next->data) {
            NODE* temp = p->next;
            p->next = p->next->next;
            free(temp);
        } else {
            p = p->next;
        }
    } while (p->next != head);
    return head;
}
