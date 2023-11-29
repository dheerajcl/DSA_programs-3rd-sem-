#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
}NODE;

void display(NODE* head);
NODE* insert_at_beg(NODE* head);
NODE* insert_at_end(NODE* head);
NODE* init();
NODE* insert_at_any(NODE* head,int index);
NODE* delete_at_beg(NODE* head);
NODE* delete_at_end(NODE* head);
NODE* delete_at_anykey(NODE* head,int key);
NODE* delete_entirelist(NODE* head);
int main()
{
    NODE* head=NULL; //list declaration locally
    int ch;
    do
    {
        printf("Enter the choice:\n 0.Exit\n 1.Display\n 2.insert at beginning\n 3.insert at end\n 4.insert at any position\n 5.delete at beginning\n 6.delete at end\n 7.delete at any key\n 8.delete entire list\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:printf("Exited from list successfully\n");
                   exit(1);
            case 1:printf("list contents:\n");
                   display(head);
                   break;
            case 2:printf("Entered choice is to insert at beginning:\n");
                   head=insert_at_beg(head);
                   break;
            case 3:printf("Entered choice is to insert at end\n");
                   head=insert_at_end(head);
                   break;
            case 4:printf("Enter the index after which node\n");
                   int index;
                   scanf("%d",&index);
                   head=insert_at_any(head,index);
                   break;
            case 5:printf("Entered choice is delete at beg:\n");
                   head=delete_at_beg(head);
                   break;
            case 6:printf("Entered choice is delete at end:\n");
                   head=delete_at_end(head);
                   break;
            case 7:printf("Enter the key you need to delete:\n");
                   int key;
                   scanf("%d",&key);
                   head=delete_at_anykey(head,key);
                   break;
            case 8:printf("Entered operation is to delete entire list\n");
                   head=delete_entirelist(head);
                   break;
            default:printf("Enter a dataid choice:");
        }
    }while(ch!=0);
}

NODE* init()
{
    NODE* temp=malloc(sizeof(NODE));
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void display(NODE* head)
{
    NODE* p=head;
    if(head==NULL)
        printf("Linked list is empty\n");
    while(p!=NULL)
    {
        printf("%d--->",p->data);
        p=p->right;
    }
    printf("\n");
}

NODE* insert_at_beg(NODE* head)
{
    NODE* temp=init();
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->right=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        temp->right=head;
        head->left=temp;
        head=temp;
    }
    return head;
}

NODE* insert_at_end(NODE* head)
{
    NODE* temp=init();
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->right=NULL;
    if(head==NULL)
        head=temp;
    else{
        NODE* p=head;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        temp->left=p;
        p->right=temp;
    }
    return head;
}

NODE* insert_at_any(NODE* head,int index)
{
    if(head==NULL)
        printf("Linked list is empty\n");
    else{
        NODE* temp=init();
        printf("Enter the data:");
        scanf("%d",&temp->data);
        temp->right=NULL;
        int count=0;
        NODE* p=head;
        while(p!=NULL && count<index)
        {
            p=p->right;
            count++;
        }
        if(count==index)
        {
            temp->right=p->right;
            temp->left=p;
            if(p->right!=NULL)
                p->right->left=temp;
            p->right=temp;
        }
        else{
            printf("Enter the index within bound\n");
        }
        }

    return head;
}

NODE* delete_at_beg(NODE* head)
{
    if(head==NULL)
        printf("Linked list is empty\n");
    else{
        NODE* p=head;
        head=p->right;
        if(head!=NULL)
            head->left=NULL;
        free(p);
        p=NULL;
    }
    return head;
}

NODE* delete_at_end(NODE* head)
{
    //NODE* befp=NULL;
    NODE* p=head;
    if(head==NULL)
        printf("Linked list is empty\n");
    else if(p->right==NULL)
    {
        free(p);
        head = NULL;
    }
    else{
        //head=NULL;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        p->left->right=NULL;
        free(p);
        p=NULL;
    }
return head;
}

NODE* delete_at_anykey(NODE* head,int key)
{
    if(head==NULL)
    {
        printf("The Linked list is empty");
        return NULL;
    }
    else{
    NODE* p=head;
    while(p!=NULL&&p->data!=key)
        p=p->right;
    if(p==NULL)
    {
        printf("Entered element not found");
        return head;
        }
    if(p==head)
        head=delete_at_beg(head);
    else{   
        p->left->right=p->right;
        if(p->right!=NULL)
            p->right->left=p->left;
        free(p);
        p=NULL;
    }
    }
return head;
}

NODE* delete_entirelist(NODE* head)
{
    NODE* p = head;
    while (p != NULL)
    {
        NODE* temp = p;
        p = p->right;
        free(temp);
    }
    return NULL;
}