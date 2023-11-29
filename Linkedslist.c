#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;


void display(NODE* head);
NODE* init();
NODE* insert_at_beg(NODE* head);
NODE* insert_at_end(NODE* head);
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
        printf("Enter the choice:\n 0.Exit\n 1.Display\n 2.insert at beginning\n 3.insert at end\n 4.insert at any position\n 5.delete at beginning\n 6.delete at last\n 7.delete at any key\n 8.delete entire list\n");
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
void display(NODE* head)
{
    NODE* p=head;
    if(head==NULL)
        printf("Linked list is empty\n");
    while(p!=NULL)
    {
        printf("%d--->",p->data);
        p=p->next;
    }
    printf("\n");
}
NODE* init()
{
    NODE* temp=malloc(sizeof(NODE));
    return temp;
}

NODE* insert_at_beg(NODE* head)
{
    NODE* temp=init();
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}

NODE* insert_at_end(NODE* head)
{
    NODE* temp=init();
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else{
        NODE* p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
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
        temp->next=NULL;
        int count=0;
        NODE* p=head;
        while(p!=NULL && count<index)
        {
            p=p->next;
            count++;
        }
        if(count==index)
        {
            temp->next=p->next;
            p->next=temp;
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
        head=p->next;
        free(p);
        p=NULL;
    }
    return head;
}

NODE* delete_at_end(NODE* head)
{
    NODE* befp=NULL;
    NODE* p=head;
    if(head==NULL)
        printf("Linked list is empty\n");
    else if(p->next==NULL)
    {
        free(p);
        head = NULL;
    }
    else{
        //head=NULL;
        while(p->next!=NULL)
        {
            befp=p;
            p=p->next;
        }
        befp->next=NULL;
        free(p);
        p=NULL;
    }
return head;
}
NODE* delete_at_anykey(NODE* head,int key)
{
    NODE* befp=NULL;
    NODE* p=head;
    if(head==NULL)
    {
        printf("The Linked list is empty");
    }
    else if(head->data==key)
        head=delete_at_beg(head);
    else{
        while(p!=NULL&&p->data!=key)
        {
            befp=p;
            p=p->next;
        }
        befp->next=p->next;
        free(p);
        p=NULL;
    }
return head;
}

NODE* delete_entirelist(NODE* head)
{
    NODE *p = head;
    while(p != NULL)
    {
        NODE* temp = p;
        p = p->next;
        free(temp);
    }
    return NULL;
}