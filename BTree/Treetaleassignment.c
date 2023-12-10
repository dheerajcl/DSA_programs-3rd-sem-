#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int calculateHeight(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return 1 + maximum(calculateHeight(node->left), calculateHeight(node->right));
}
int calculateDiameter(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    int leftDiameter = calculateDiameter(root->left);
    int rightDiameter = calculateDiameter(root->right);
    return maximum(leftHeight + rightHeight + 1, maximum(leftDiameter, rightDiameter));
}

int main() {
    int n;
    scanf("%d", &n);
    struct TreeNode* nodes[n];

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        if (value != -1)
            nodes[i] = createTreeNode(value);
        else
            nodes[i] = NULL;
    }
    int rootIndex = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftChildIndex = 2 * i + 1;
            int rightChildIndex = 2 * i + 2;

            if (leftChildIndex < n && nodes[leftChildIndex] != NULL)
                nodes[i]->left = nodes[leftChildIndex];

            if (rightChildIndex < n && nodes[rightChildIndex] != NULL)
                nodes[i]->right = nodes[rightChildIndex];
        }
    }
    int result = calculateDiameter(nodes[rootIndex]);
    printf("%d\n", result);
    return 0;
}
