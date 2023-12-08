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
NODE* insert_at_end1(NODE* head2);
NODE* insert_at_any(NODE* head,int index);
NODE* delete_at_beg(NODE* head);
NODE* delete_at_end(NODE* head);
NODE* delete_at_anykey(NODE* head,int key);
NODE* delete_at_any_index(NODE* head, int index1);
NODE* delete_entirelist(NODE* head);
NODE* search_element(NODE* head,int ele);
NODE* reverseList(NODE* head);
NODE* sort_ascending(NODE* head);
NODE* sort_descending(NODE* head);
NODE* del_evenNodes(NODE* head);
NODE* concat(NODE* head,NODE* head2);
void count_all_keys(NODE* head);
NODE* delete_duplicates(NODE* head);
NODE* delete_duplicates1(NODE* head);
int main()
{
    NODE* head=NULL;   //list declaration locally
    NODE* head2=NULL;
    int ch;
    do
    {
        printf("Enter the choice:\n 0.Exit\n 1.Display\n 2.insert at beginning\n 3.insert at end\n 4.insert at any position\n 5.delete at beginning\n 6.delete at last\n 7.delete at any key\n 8.delete at any position\n 9.delete entire list\n 10.search element\n 11.reverse list\n 12.sort ascending\n 13.sort descending\n 14.delete even nodes\n 15.concat\n 16.insert at end in list2\n 17.count all keys\n 18.delete duplicates\n 19.delete duplicates1\n");
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
            case 8:printf("Enter the index you need to delete:\n");
                   int index1;
                   scanf("%d",&index1);
                   head=delete_at_any_index(head,index1);
                   break;
            case 9:printf("Entered operation is to delete entire list\n");
                   head=delete_entirelist(head);
                   break;
            case 10:printf("Enter the element you need to search:\n");
                    int ele;
                    scanf("%d",&ele);
                    head=search_element(head,ele);
                    break;
            case 11:printf("Entered operation is to reverse the list\n");
                    head=reverseList(head);
                    break;
            case 12:printf("Entered operation is to sort the list in ascending order\n");
                    head=sort_ascending(head);
                    break;
            case 13:printf("Entered operation is to sort the list in descending order\n");
                    head=sort_descending(head);
                    break;
            case 14:printf("Entered operation is to delete even nodes\n");
                    head=del_evenNodes(head);
                    break;
            case 15:printf("Entered operation is to concatenate two lists\n");
                    head=concat(head,head2);
                    break;
            case 16:printf("Entered operation is to insert at end in list2\n");
                    head2=insert_at_end1(head2);
                    break;
            case 17:printf("Entered operation is to count all keys\n");
                    count_all_keys(head);
                    break;
            case 18:printf("Entered operation is to delete duplicates\n");
                    head=delete_duplicates(head);
                    break;
            case 19:printf("Entered operation is to delete duplicates\n");
                    head=delete_duplicates1(head);
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

void display1(NODE* head2){
    NODE* p=head2;
    if(head2==NULL)
        printf("Linked list is empty\n");
    while(p!=NULL){
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

NODE* insert_at_end1(NODE* head2)
{
    NODE* temp=init(); 
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head2==NULL)
        head2=temp;
    else{
        NODE* p=head2;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    return head2;  
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
    else if(head->data==key){
        //head=delete_at_beg(head);
        head=p->next;
        free(p);
        p=NULL;}
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

NODE* delete_at_any_index(NODE* head, int index){
    NODE* befp=NULL;
    NODE* p=head;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        int count1=0;
        NODE* befp=NULL;
        NODE* p=head;
        while(p!=NULL && count1<index){
            befp=p;
            p=p->next;
            count1++;
        }
        if(count1==index){
            befp->next=p->next;
            free(p);
            p=NULL;
        }
    }
    return head;
}

NODE* delete_entirelist(NODE* head)
{
    NODE *p = head;
    while(p != NULL)
    {
        NODE* befp = p;
        p = p->next;
        free(befp);
    }
    printf("List deleted successfully\n");
    return NULL;
}

NODE* search_element(NODE* head, int ele) {
    NODE* p = head;
    int count2 = 0;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        while(p != NULL && p->data != ele) {
            p = p->next;
            count2++;
        }
        if(p == NULL) {
            printf("The element is not found\n");
        } else {
            printf("The element is found at %d position\n", count2 + 1);
        }
    }
    return head;
}

NODE* reverseList(NODE* head){
    NODE* p = head;
    NODE* befp = NULL;
    NODE* aftp = NULL;
    while(p != NULL){
        aftp = p->next;
        p->next = befp;
        befp = p;
        p = aftp;
    }
    head = befp;
    return head;
}

NODE* sort_ascending(NODE* head) {
    if(head == NULL || head->next == NULL) {
        // If the list is empty or only contains one element, it is already sorted
        return head;
    }
    NODE* p;
    int swapped;
    do {
        swapped = 0;
        p = head;
        while(p->next != NULL) {
            if(p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;

                swapped = 1;
            }
            p = p->next;
        }
    } while(swapped);
    printf("Smallest element is %d\n",head->data);
    return head;
}

NODE* sort_descending(NODE* head) {
    if(head == NULL || head->next == NULL) {
        // If the list is empty or only contains one element, it is already sorted
        return head;
    }
    NODE* p;
    int swapped;
    do {
        swapped = 0;
        p = head;                                   // Or you can reverse the ascending order list
        while(p->next != NULL) {
            if(p->data < p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;

                swapped = 1;
            }
            p = p->next;
        }
    } while(swapped);
    printf("Largest element is %d\n",head->data);
    return head;
}

NODE* del_evenNodes(NODE* head){
    NODE* p = head;
    NODE* befp = NULL;
    int count3 = 0;
    while(p != NULL){
        count3++;
        if(count3%2 == 0){
            befp->next = p->next;
            free(p);
            p = befp->next;
        }else{
            befp = p;
            p = p->next;
        }
    }
    return head;
}

NODE* concat(NODE* head, NODE* head2) {
    if(head == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head;
    }

    NODE* p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = head2;

    return head;
}

void count_all_keys(NODE* head) {
    NODE* p = head;
    NODE* q;
    int count;

    while(p != NULL) {
        count = 0;
        q = head;
        // Check if we've seen this element before
        while(q != p) {
            if(q->data == p->data) {
                break;
            }
            q = q->next;
        }
        // If we haven't seen this element before, count how many times it appears
        if(q == p) {
            q = p;
            while(q != NULL) {
                if(q->data == p->data) {
                    count++;
                }
                q = q->next;
            }
            printf("Element %d appears %d times\n", p->data, count);
        }
        p = p->next;
    }
}

NODE* delete_duplicates(NODE* head) {
    NODE* p = head;
    NODE* q;
    NODE* duplicate;

    while(p != NULL && p->next != NULL) {
        q = p;

        while(q->next != NULL) {
            if(p->data == q->next->data) {
                // Duplicate found, so delete it
                duplicate = q->next;
                q->next = q->next->next;
                free(duplicate);
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }

    return head;
}

//or

NODE* delete_duplicates1(NODE* head){
    head=sort_ascending(head);
    NODE* p=head;
    while(p!=NULL && p->next!=NULL){
        if(p->data==p->next->data){
            NODE* temp=p->next;
            p->next=p->next->next;
            free(temp);
        }else
            p=p->next;
    }
    return head;
}