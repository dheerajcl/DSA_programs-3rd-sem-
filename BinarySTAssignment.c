#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;

TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        return createTreeNode(value);
    }
    if (value <= root->value) {
        root->leftChild = insertNode(root->leftChild, value);
    } else {
        root->rightChild = insertNode(root->rightChild, value);
    }
    return root;
}

TreeNode* constructBST(int arr[], int n) {
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            root = insertNode(root, arr[i]);
        }
    }
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root->leftChild != NULL) {
        root = root->leftChild;
    }
    return root;
}

TreeNode* deleteTreeNode(TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    } else if (value < root->value) {
        root->leftChild = deleteTreeNode(root->leftChild, value);
    } else if (value > root->value) {
        root->rightChild = deleteTreeNode(root->rightChild, value);
    } else {
        if (root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            root = NULL;
        } else if (root->leftChild == NULL) {
            TreeNode* temp = root;
            root = root->rightChild;
            free(temp);
        } else if (root->rightChild == NULL) {
            TreeNode* temp = root;
            root = root->leftChild;
            free(temp);
        } else {
            TreeNode* temp = findMin(root->rightChild);
            root->value = temp->value;
            root->rightChild = deleteTreeNode(root->rightChild, temp->value);
        }
    }
    return root;
}

int searchValue(TreeNode* root, int value) {
    if (root == NULL) {
        return 0;
    } else if (root->value == value) {
        return 1;
    } else if (value <= root->value) {
        return searchValue(root->leftChild, value);
    } else {
        return searchValue(root->rightChild, value);
    }
}

int main() {
    int n, q;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    TreeNode* root = constructBST(arr, n);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 0) {
            if (searchValue(root, x)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            root = deleteTreeNode(root, x);
        }
    }
    return 0;
}