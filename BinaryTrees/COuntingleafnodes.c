#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* TreeFromLevelOrder(int levelOrder[], int size, int index) {
    if (index < size) {
        if (levelOrder[index] == -1) {
            return NULL;
        }
        struct TreeNode* root = createNode(levelOrder[index]);
        root->left = TreeFromLevelOrder(levelOrder, size, 2 * index + 1);
        root->right = TreeFromLevelOrder(levelOrder, size, 2 * index + 2);

        return root;
    }

    return NULL;
}
int countleaves(struct TreeNode* root) {
    if (root==NULL) {
        return 0;
    }
    if (root->left==NULL && root->right==NULL) {
        return 1;
    }
    return countleaves(root->left)+countleaves(root->right);
}

int main() {
    int levelOrder[100]; 
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &levelOrder[i]);
    }
    struct TreeNode* root = TreeFromLevelOrder(levelOrder, size, 0);
    int leafCount = countleaves(root);
    printf("%d\n", leafCount);
    return 0;
}