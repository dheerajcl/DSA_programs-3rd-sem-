#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
    int rthread; // rthread = 1 when either node is null or node's right child is connected to it's parent
}NODE;

typedef struct tree{
    NODE* root;
}TBT;

// Initialize the tree
void init_tree(TBT *t){
    t->root = NULL;
}

// Create a new node with the given element
NODE* getNode(int ele){
    NODE* temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->left = temp->right = NULL;
    temp->rthread = 1;

    return temp;
}

// Set the left child of the given node
void set_left(NODE* p,NODE* temp){
    if (p == NULL) {
        return;
    }
    p->left = temp;
    temp->right = p;
}

// Set the right child of the given node
void set_right(NODE* p,NODE* temp){
    if (p == NULL) {
        return;
    }
    temp->right = p->right;
    p->right = temp;
    p->rthread = 0;
}

// Traverse the tree in inorder and print the elements
void inorder(TBT *pt){
    if (pt == NULL || pt->root == NULL) {
        return;
    }
    NODE* q;
    NODE* p = pt->root;

    do{
        q = NULL;
        while(p!=NULL){
            q = p;
            p = p->left;
        }

        if(q!=NULL){
            printf("%d ",q->data);
            p = q->right;
        }

        while(q!=NULL && q->rthread && p!=NULL){
            printf("%d ",p->data);
            q = p;
            p = p->right;
        }
    }
    while(q!=NULL);
}

// Insert a new node into the tree
void insert(TBT* pt){
    int choice = 1;

    while(choice){
        printf("Enter the key :\n");
        int e;
        if (scanf("%d", &e) != 1) {
            printf("Invalid input\n");
            return;
        }

        NODE* temp = getNode(e);
        NODE* p = pt->root;
        NODE* q = NULL;

        if(p==NULL){
            pt->root = temp;
        }
        else{
            while(p!=NULL){
                q = p;
                if(temp->data < p->data){
                    if (p->left == NULL) {
                        break;
                    }
                    p = p->left;
                }
                else{
                    if(p->rthread) break;
                    else p = p->right;
                }
            }

            if(p==NULL){
                set_left(q,temp);
            }
            else{
                set_right(p,temp);
            }
        }

        printf("Do you want to continue :");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            return;
        }
    }
}

int main(){
    TBT pt;
    init_tree(&pt);
    insert(&pt);
    inorder(&pt);
}