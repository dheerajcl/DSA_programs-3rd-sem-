#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

void display(NODE* head);
NODE* insert_at_beg(NODE* head);
NODE* init();
NODE* insert_at_end(NODE* head);
NODE* insert_after_index(NODE* head,int index);
NODE* delete_at_beg(NODE* head);
NODE* delete_at_end(NODE* head);
NODE* delete_key(NODE* head,int key);
NODE* freeList(NODE* head);

int main()
{
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
				break;
			case 8 :
				head = freeList(head);
				break;

		}

		printf("\nPress any button to continue.......\n");
		__fpurge(stdin);
		getc(stdin);

	}while(ch<9);

	return 0;
}

NODE* init(){
	NODE* temp = malloc(sizeof(NODE));
	return temp;
}

void display(NODE* head){
	NODE* p = head;
	while(p->next!=head){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}

NODE* insert_at_beg(NODE* head){
	NODE* temp = init();

	printf("Enter the element : \n");
	scanf("%d",&temp->data);
	temp->next = NULL;

	if(head==NULL){
		head = temp;
		head->next = head;
	}
	else{
		NODE* last = head;
		while(last->next!=head){
			last = last->next;
		}
		last->next = temp;
		temp->next = head;
		head = temp;
	}

	return head;
}

NODE* insert_at_end(NODE* head){
	NODE* temp = init();

	printf("Enter the element : \n");
	scanf("%d",&temp->data);
	temp->next = NULL;

	if(head==NULL){
		head = temp;
		head->next = head;
	}
	else{
		NODE* last = head;
		while(last->next != head){
			last = last->next;
		}
		last->next = temp;
		temp->next = head;
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
		temp->next = NULL;
		int count = 0;
		NODE* p = head;

		while(p!=NULL && count<index){
			p = p->next;
			count++;
		}

		if(count==index){
			temp->next = p->next;
			p->next = temp;
		}else printf("Index out of bound (SIGSEV)\n");

	}

	return head;
}

NODE* delete_at_beg(NODE* head){
	if(head==NULL){
		printf("Empty Linked List\n");
	}
	else if(head == head->next){
		free(head);
		head = NULL;
	}
	else{
		NODE* toDelete = head;
		NODE* last = head;
		while(last->next != head){
			last = last->next;
		}
		last->next = head->next;
		head = head->next;
		free(toDelete);
		toDelete = NULL;
	}
	return head;
}

NODE* delete_at_end(NODE* head){
	if(head==NULL){
		printf("Empty Linked List\n");
	}
	else if(head->next==head){
		free(head);
		head = NULL;
	}
	else{
		NODE* toDelete = head;
		NODE* last = head;
		NODE* beforeLast = last;

		while(last->next != head){
			beforeLast = last;
			last = last->next;
		}

		toDelete = beforeLast->next;
		beforeLast->next = head;

		free(toDelete);
		toDelete = NULL;

	}

	return head;
}

NODE* delete_key(NODE* head,int key){
	NODE* p = head;
	NODE* beforeP = NULL;
	if(head==NULL){
		printf("Empty Linked List\n");
	}
	else if(head->data == key){
		p = head;
		head = head->next;
		free(p);
		p = NULL;
	}
	else{
		while(p!=NULL && p->data!=key){
			beforeP = p;
			p = p->next;
		}
		if(p==NULL){
			printf("No such element found\n");
		}else{
			beforeP->next = p->next;
			free(p);
			p = NULL;
		}
	}
	return head;
}

NODE* freeList(NODE* head){
	NODE* p = head;
	while(head!=NULL){
		head = head->next;
		free(p);
		p = head;
	}
	return NULL;
}