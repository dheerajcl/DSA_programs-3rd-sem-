#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left, *right;
} NODE;

typedef struct bst
{
	NODE *root;
} BST;

void init(BST *pbst)
{
	pbst->root = NULL;
}

NODE *getnode(int ele)
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->key = ele;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(BST *pbst, int ele)
{
	NODE *temp = getnode(ele);
	NODE *p, *befp;
	if (pbst->root == NULL)
		pbst->root = temp;
	else
	{
		p = pbst->root;
		befp = NULL;
		while (p != NULL)
		{
			if (p->key > temp->key)
			{
				befp = p;
				p = p->left;
			}
			else
			{
				befp = p;
				p = p->right;
			}
		}
		if (befp->key > temp->key)
			befp->left = temp;
		else
			befp->right = temp;
	}
}

NODE *rinsert(NODE *ph, int x)
{
	NODE *temp = getnode(x);
	NODE *p, *befp;
	if (ph == NULL)
		return temp;
	else
	{
		if (ph->key > x)
			ph->left = rinsert(ph->left, x);
		else
			ph->right = rinsert(ph->right, x);
	}
	return ph;
}

void inorder(NODE *ph)
{
	NODE *p = ph;
	if (p != NULL)
	{											// Can also be used as display function
		inorder(p->left);
		printf("%d\t", p->key);
		inorder(p->right);
	}
}

void preorder(NODE *ph)
{
	NODE *p = ph;
	if (p != NULL)
	{
		printf("%d\t", p->key);
		preorder(p->left);
		preorder(p->right);
	}
}

void postorder(NODE *ph)
{
	NODE *p = ph;
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d\t", p->key);
	}
}

int rsearch(NODE *ph, int x)
{
	NODE *p = ph;
	if (p == NULL)
		return 0;
	if (p->key == x)
		return 1;
	if (p->key > x)
		return (rsearch(p->left, x));
	else
		return (rsearch(p->right, x));
}

int count(NODE *p)
{
	if (p == NULL)
		return 0;
	int lc = count(p->left);
	int rc = count(p->right);
	return lc + rc + 1;
}

int max(NODE *p)
{
	if (p->right == NULL)
		return p->key;
	else
	{
		max(p->right);
	}
}

int min(NODE *p)
{
	if (p->left == NULL)
		return p->key;
	else
	{
		min(p->left);
	}
}

/*
int maxDepth(NODE *node) 
{
   if (node == NULL)
       return 0;
   else
   {
       // compute the depth of each subtree 
       int leftDepth = maxDepth(node->left);
       int rightDepth = maxDepth(node->right);
  
       // use the larger one 
       if (leftDepth > rightDepth) 
           return(leftDepth + 1);
       else return(rightDepth + 1);
   }
} */

/*int minDepth(struct TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    else{
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(left==0)
            return right+1;
        else if(right==0)
            return left+1;
        else if(left<right)
            return left+1;
        else
            return right+1;
    }
}
*/

/*
void mirror(NODE* node) 
{
    if (node == NULL) 
        return; 
    else
    {
        NODE* temp;
         
       //  do the subtrees 
        mirror(node->left);
        mirror(node->right);
    
        // swap the pointers in this node 
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
} */

/*
    if (root == NULL) {
        return 0;
    }

    int lc = 0; // Initialize the sum of left leaves to zero

    // Check if the left child is a leaf node
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        lc += root->left->val;  // Add its value to the sum
    }

    // Recursively calculate the sum of left leaves in the left and right subtrees
    lc += sumOfLeftLeaves(root->left);
    lc += sumOfLeftLeaves(root->right);

    return lc;
*/

/*int areIdentical(NODE *root1, NODE *root2) 
{
    // base cases 
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 != NULL && root2 != NULL)
    {
        return
        (
            root1->key == root2->key &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right)
        );
    }
    
    // If none of the above conditions is true, then the trees are not identical
    return 0;
} 
*/

/*
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL){
        return true;
    }
    bool Symmetric(struct TreeNode* left,struct TreeNode* right){
        if(left==NULL && right==NULL){
            return true;
        }
        if(left==NULL || right==NULL){
            return false;
        }
        
        return (left->val==right->val) && Symmetric(left->left,right->right) && Symmetric(left->right,right->left);
    }
    return Symmetric(root->left,root->right);
}
*/

/*
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return NULL;  // Both trees are empty, return NULL
    }

    int value = (root1 == NULL ? 0 : root1->val) + (root2 == NULL ? 0 : root2->val);
    
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = mergeTrees(root1 == NULL ? NULL : root1->left, root2 == NULL ? NULL : root2->left);
    newNode->right = mergeTrees(root1 == NULL ? NULL : root1->right, root2 == NULL ? NULL : root2->right);

    return newNode;
}
*/

NODE *delete(NODE *r, int ele)
{
	NODE *curr, *prev, *p, *q, *temp;
	curr = r;
	prev = NULL;
	while ((curr != NULL) && (curr->key != ele))
	{
		prev = curr;
		if (ele < curr->key)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr == NULL)
	{
		printf("number not found\n");
		return r;
	}

	if ((curr->left == NULL) || (curr->right == NULL)) // zero or one node condition
	{
		if (curr->left == NULL)
			q = curr->right;
		else
			q = curr->left;

		if (prev == NULL) // root node with one child
		{
			free(curr);
			return q;
		}
		if (curr == prev->left)
			prev->left = q;
		else
			prev->right = q;
		free(curr);
	}
	else
	{
		p = NULL;			// p is prent of inorder successor
		temp = curr->right; // we go to rst of current and select the min element as inorder successor
		// q= min(temp);
		while (temp->left != NULL)
		{
			p = temp;
			temp = temp->left;
		}
		curr->key = temp->key;
		if (p != NULL)
		{
			p->left = temp->right;
		}
		else
		{
			curr->right = temp->right;
		}
		free(temp);
	}
	return r;
}

int main()
{
	BST pbst;
	init(&pbst);
	int ch, ele, x, pos;
	do
	{
		printf("\nenter a choice: 1-insert\n 0- rinsert\n  2- inorder\n 3- preorder\n 4-postorder\n 5- search a key\n 6- No. of nodes\n 7- Maximum element\n 8- Minimum element\n 9-deletion\n 10- exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("enter an element\n");
			scanf("%d", &ele);
			insert(&pbst, ele);
			break;
		case 0:
			printf("enter an element\n");
			scanf("%d", &ele);
			rinsert(pbst.root, ele);
			break;
		case 2:
			inorder(pbst.root);
			break;
		case 3:
			preorder(pbst.root);
			break;
		case 4:
			postorder(pbst.root);
			break;
		case 5:
			printf("enter the key to be searched\n");
			scanf("%d", &x);
			pos = rsearch(pbst.root, x);
			if (pos == 0)
				printf("Key not found\n");
			else
				printf("key found \n");
			break;
		case 6:
			printf("No. of nodes = %d\n", count(pbst.root));
			break;
		case 7:
			printf("Maximum element = %d\n", max(pbst.root));
			break;
		case 8:
			printf("Minimum element = %d\n", min(pbst.root));
			break;
		case 9:
			printf("enter the element to be deleted\n");
			scanf("%d", &ele);
			pbst.root = delete (pbst.root, ele);
			// printf("%d deleted\n", pbst.root->key);
			break;
		}
	} while (ch != 10);
	return 0;
}
