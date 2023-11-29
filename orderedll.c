#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void display(NODE *head);
NODE *init();
NODE *insert(NODE *head);
NODE *sort_ascending(NODE *head);
NODE *sort_descending(NODE *head);

int main()
{
    NODE *head = NULL; //list declaration locally
    int ch;
    do
    {
        printf("Enter the choice:\n 0.Exit\n 1.Display\n 2.Insert\n 3.Sort in ascending order\n 4.Sort in descending order\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exited from list successfully\n");
            exit(0); // Exit with a success code
        case 1:
            printf("List contents:\n");
            display(head);
            break;
        case 2:
            printf("Entered choice is to insert:\n");
            head = insert(head);
            break;
        case 3:
            printf("Sorting in ascending order\n");
            head = sort_ascending(head);
            if (head == NULL)
            {
                printf("The list is empty or has only one node\n");
            }
            break;
        case 4:
            printf("Sorting in descending order\n");
            head = sort_descending(head);
            if (head == NULL)
            {
                printf("The list is empty or has only one node\n");
            }
            break;
        default:
            printf("Indataid choice\n");
            break;
        }
    } while (ch != 0);
}

void display(NODE *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    NODE *p = head;
    while (p != NULL)
    {
        printf("%d--->", p->data);
        p = p->next;
    }
    printf("\n");
}

NODE *init()
{
    NODE *temp = malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // Exit with an error code
    }
    return temp;
}

NODE *insert(NODE *head)
{
    NODE *temp = init();
    printf("Enter the data:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

NODE *sort_ascending(NODE *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    NODE *current, *index;
    int temp;

    for (current = head; current != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    return head;
}
NODE *sort_descending(NODE *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    NODE *current, *index;
    int temp;

    for (current = head; current != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data < index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    return head;
}


