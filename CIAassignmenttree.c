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

struct TreeNode* findLCA(struct TreeNode* root, int thief1, int thief2) {
    if (root == NULL)
        return NULL;

    if (root->val == thief1 || root->val == thief2)
        return root;

    struct TreeNode* leftLCA = findLCA(root->left, thief1, thief2);
    struct TreeNode* rightLCA = findLCA(root->right, thief1, thief2);
    if (leftLCA != NULL && rightLCA != NULL)
        return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
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

    int thief1, thief2;
    scanf("%d %d", &thief1, &thief2);
    struct TreeNode* lca = findLCA(nodes[rootIndex], thief1, thief2);
    printf("%d\n", lca->val);
    return 0;
}
