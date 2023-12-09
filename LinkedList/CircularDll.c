#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* right;
	struct node* left;
}NODE;

NODE* init();
void display(NODE* head);
NODE* insert_at_beg(NODE* head);
NODE* insert_at_end(NODE* head);
NODE* insert_after_index(NODE* head,int index);
NODE* delete_at_beg(NODE* head);
NODE* delete_at_end(NODE* head);
NODE* delete_key(NODE* head,int key);

int main(){

	NODE* head = NULL;     // local list declaration.
	int ch;

	do{
		printf("Enter the choice : \n");
		printf("1.Display\n");
		printf("2.Insert at begginig\n");
		printf("3.Insert at end\n");
		printf("4.Insert at specific index.\n");
		printf("5.Delete at beginning\n");
		printf("6.Delete at end\n");
		printf("7.Delete the specific key\n");
		printf("8.Delete Everything\n");
		printf("Enter any other number greater than these to exit \n");

		scanf("%d",&ch);

		switch(ch){
			case 1 : 
				printf("list contents : ");
				display(head);
				break;
			case 2 : 
				head = insert_at_beg(head);
				break;
			case 3 : 
				head = insert_at_end(head);
				break;
			case 4 :
				printf("Enter the index after which node has to be inserted : \n");
				int index;
				scanf("%d",&index);
				head = insert_after_index(head,index);
				break;
			case 5 :
				head = delete_at_beg(head);
				break;
			case 6 :
				head = delete_at_end(head);
				break;
			case 7 :
				printf("Enter the key you want to delete : \n");
				int key;
				scanf("%d",&key);
				head = delete_key(head,key);
			// 	break;
			// case 8 :
			// 	head = freeList(head);
			// 	break;

		}

		printf("\nPress any button to continue.......\n");
		__fpurge(stdin);
		getc(stdin);

	}while(ch<8);



	return 0;
}

NODE* init(){
	NODE* toReturn = malloc(sizeof(NODE*));
	toReturn->left = NULL;
	toReturn->right = NULL;
	return toReturn;
}

void display(NODE* head){
	if(head==NULL){
		printf("Empty Linked List\n");
		return;
	}
	NODE* p = head;
	printf("NULL<->");
	while(p->right!=head){
		printf("%d<->",p->data);
		p = p->right;
	}
	printf("%d<->",p->data);
	printf("NULL\n");
}

NODE* insert_at_beg(NODE* head){
	NODE* temp = init();

	printf("Enter the element : \n");
	scanf("%d",&temp->data);
	temp->left = NULL;
	temp->right = NULL;

	if(head==NULL){
		temp->right = temp;
		temp->left = temp;
		head = temp;
	}
	else{
		temp->right = head;
		temp->left = head->left;
		head->left->right = temp;
		head->left = temp;
		head = temp;
	}

	return head;
}

NODE* insert_at_end(NODE* head){
	NODE* temp = init();

	printf("Enter the element : \n");
	scanf("%d",&temp->data);
	temp->left = NULL;
	temp->right = NULL;

	if(head==NULL){
		temp->right = temp;
		temp->left = temp;
		head = temp;
	}
	else{
		NODE* last = head->left;
		temp->left = last;
		temp->right = head;
		head->left = temp;
		last->right = temp;
	}

	return head;
}

NODE* insert_after_index(NODE* head,int index){
	if(head==NULL){
		printf("Empty Linked List \n");
	}
	else{
		NODE* temp = init();
		printf("Enter the data : \n");
		scanf("%d",&temp->data);
		temp->left = NULL;
		temp->right = NULL;
		int count = 0;
		NODE* p = head;

		while(p!=NULL && count<index){
			p = p->right;
			count++;
		}

		if(count==index){
			temp->right = p->right;
			temp->left = p;
			if(p->right!=NULL) 
                p->right->left = temp;
			p->right = temp;
		}else 
        printf("Index out of bound (SIGSEV)\n");

	}

	return head;
}

NODE* delete_at_beg(NODE* head){
	if(head==NULL){
		printf("Empty Linked List\n");
	}
	NODE* toDelete = head;
	head = head->right;
	if(head!=NULL) 
        head->left = NULL;
	free(toDelete);
	return head;
}

NODE* delete_at_end(NODE* head){
	if(head==NULL){
		printf("Empty Linked List\n");
	}
	else if(head->right==NULL){
		NODE* toDelete = head;
		head->left = NULL;
		head = NULL;
		free(toDelete);
	}
	else{
		
		NODE* temp = head;

		while(temp->right!=NULL){
			temp = temp->right;
		}
		NODE* toDelete = temp->right;
		temp->left->right = NULL;
		free(toDelete);
	}

	return head;
}

NODE* delete_key(NODE* head,int key){
	if(head==NULL){
		printf("Empty linked list\n");
	}
	else{
		NODE* temp = head;
		while(temp!=NULL && temp->data!=key){
			temp = temp->right;
		}
		if(temp->data==key){
			NODE* toDelete = temp;
			if(temp->left!=NULL) 
                temp->left->right = temp->right;
			if(temp->right!=NULL) 
                temp->right->left = temp->left;
			if(toDelete==head) 
                head=head->right;      
			free(toDelete);
			toDelete = NULL;
		}else if(temp==NULL){
			printf("Key is not in your linked list what you want to delete\n");
		}
	}

	return head;
}