#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void Traversal(struct Node * head) {
    struct Node * ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        if(ptr->next != NULL) 
            printf("-> ");
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node * DeleteAtFirst(struct Node * head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node * ptr = head;
    head = head->next;
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
    struct Node * ptr = head;
    struct Node * p = head->next;

    while(p->next != NULL) {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

struct Node * DeleteAtIndex(struct Node * head, int pos) {
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if(pos == 1) {
        return DeleteAtFirst(head);
    }
    if(pos <= 0) {
        printf("Invalid position.\n");
        return head;
    }
    struct Node * p = head;
    struct Node * q = head->next;
    int i = 1;
    while(q != NULL && i<pos-1) {
        p = p->next;
        q = q->next;
        i++;
    }
    if(q == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    p->next = q->next;
    free(q);
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

    printf("Original Linkedlist : ");
    Traversal(head);

    int opt, pos;
    do {
        int traversal = 0;
        printf("\nSelect method for deletion : \n");
        printf("1. At the front of the list\n");
        printf("2. At the end of the list\n");
        printf("3. At given index\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
        printf("Choose an option (1/2/3/4) : ");
        scanf("%d", &opt);

        switch(opt) {
            case 1: head = DeleteAtFirst(head); traversal = 1; break;
            case 2: head = DeleteAtEnd(head); traversal = 1; break;
            case 3: printf("Enter an index : ");
                    scanf("%d", &pos);
                    head = DeleteAtIndex(head, pos);
                    traversal = 1;
                    break;
            case 4: printf("Exiting Program !\n"); break;
            default: printf("Invalid input. Try again.\n"); break;

        }
        if(traversal) {
            printf("Current linkedlist : ");
            Traversal(head);
        }
    } while(opt != 4);
    
    return 0;
}