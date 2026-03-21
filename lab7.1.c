#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void LinkedListTraversal(struct Node * head) {
    struct Node * ptr = head;
    while(ptr!= NULL) {
        printf("%d ", ptr->data);
        if(ptr->next != NULL)
            printf("-> ");
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node * InsertAtFirst(struct Node * head, int data) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node * InsertAfterNode(struct Node * head, int data, struct Node * prevNode) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

struct Node * InsertAtEnd(struct Node * head, int data) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if(head == NULL)
        return ptr;

    struct Node * p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

int main() {
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 20;
    head->next = second;

    second->data = 40;
    second->next = third;

    third->data = 60;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = fifth;

    fifth->data = 100;
    fifth->next = NULL;

    printf("\nOriginal Data : \n");
    LinkedListTraversal(head);

    int opt, data, pos, traversal;

    do {
        traversal = 0;
        printf("\nSelect method for insertion : \n");
        printf("1. At front of the list\n");
        printf("2. After a given node\n");
        printf("3. At end of the list\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
        printf("Choose an option (1/2/3/4) : ");
        scanf("%d", &opt);

        switch(opt) {
            case 1: 
                printf("Enter an element : ");
                scanf("%d", &data);
                head = InsertAtFirst(head, data);
                traversal = 1;
                break;
            case 2:
                printf("Enter an element : ");
                scanf("%d", &data);
                printf("Enter a node : ");
                scanf("%d", &pos);
                struct Node * ptr = head;
                for(int i=1; i<pos && ptr!=NULL; i++)
                    ptr = ptr->next;
                if(ptr != NULL) {
                    head = InsertAfterNode(head, data, ptr);
                    traversal = 1;
                }
                else 
                    printf("Invalid position.\n");
                break;
            case 3:
                printf("Enter an element : ");
                scanf("%d", &data);
                head = InsertAtEnd(head, data);
                traversal = 1;
                break;
            case 4:
                printf("Exiting Linked List...\n");
                break;
            default: 
                printf("Invalid option. Try again.\n");
                break;
        }
        if(traversal)
            LinkedListTraversal(head);
    } while (opt != 4);

    return 0;
}