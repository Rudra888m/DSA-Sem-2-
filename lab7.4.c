#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
    struct Node * prevNode;
};

void Traversal(struct Node * head) {
    struct Node * ptr = head;
     while(ptr != NULL) {
        printf("%d ", ptr->data);
        if(ptr->next!= NULL)
            printf("-> ");
        ptr = ptr->next;
    };
    printf("\n");
}

struct Node * InsertAtFirst (struct Node * head, int data) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prevNode = NULL;
    if(head != NULL)
        head->prevNode = ptr;
    return ptr;
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
    ptr->prevNode = p;
    p->next = ptr;
    return head;
}

struct Node * InsertAfterNode(struct Node * head, int data, struct Node * prevnode) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevnode->next;
    ptr->prevNode = prevnode;
    if(ptr->next != NULL)
        ptr->next->prevNode = ptr;
    prevnode->next = ptr;
    return head;
}

struct Node * DeleteAtFirst(struct Node * head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node * ptr = head;
    head = head->next;
    if(head != NULL)
        head->prevNode = NULL;
    free(ptr);
    return head;
}

struct Node * DeleteAtEnd(struct Node * head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node * p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->prevNode->next = NULL;
    free(p);
    return head;
}

struct Node * DeleteAtIndex(struct Node * head, int pos) {
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if(pos == 1)
        return DeleteAtFirst(head);
    struct Node * p = head;
    int i = 1;
    while(i < pos && p != NULL) {
        p = p->next;
        i++;
    }
    if(p == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    if(p->prevNode != NULL)
        p->prevNode->next = p->next;
    if(p->next != NULL)
        p->next->prevNode = p->prevNode;
    free(p);
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
    head->prevNode = NULL;

    second->data = 40;
    second->next = third;
    second->prevNode = head;

    third->data = 60;
    third->next = fourth;
    third->prevNode = second;

    fourth->data = 80;
    fourth->next = fifth;
    fourth->prevNode = third;

    fifth->data = 100;
    fifth->next = NULL;
    fifth->prevNode = fourth;

    printf("\nOriginal Data : \n");
    Traversal(head);

    int opt, data, pos, traversal;

    do {
        traversal = 0;
        printf("\nSelect method for Doubly Linkedlist : \n");
        printf("1. Insert at front of the list\n");
        printf("2. Insert after a given node\n");
        printf("3. Insert at end of the list\n");
        printf("4. Delete at front of the list\n");
        printf("5. Delete at given index\n");
        printf("6. Delete at end of the list\n");
        printf("7. Exit\n");
        printf("--------------------------------\n");
        printf("Choose an option (1/2/3/4/5/6/7) : ");
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
                head = DeleteAtFirst(head);
                traversal = 1;
                break;
            case 5:
                printf("Enter position : ");
                scanf("%d", &pos);
                head = DeleteAtIndex(head, pos);
                traversal = 1;
                break;
            case 6:
                head = DeleteAtEnd(head);
                traversal = 1;
                break;
            case 7:
                printf("Exiting Linked List...\n");
                break;
            default: 
                printf("Invalid option. Try again.\n");
                break;
        }
        if(traversal)
            Traversal(head);
    } while (opt != 7);

    return 0;
}