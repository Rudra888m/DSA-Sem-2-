#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void mergesortedlist(struct Node * head1, struct Node * head2) {
    struct Node * temp1 = head1;
    struct Node * temp2 = head2;
    struct Node * mergeHead;
    struct Node * temp;

    if(temp1->data > temp2->data) {
        mergeHead = temp2;
        temp = mergeHead;
        temp2 = temp2->next;
    }
    else {
        mergeHead = temp1;
        temp = mergeHead;
        temp1 = temp1->next;
    }

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data > temp2->data) {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
        else {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
    }
    if(temp1 == NULL) {
        while(temp2 != NULL) {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    else {
        while(temp1 != NULL) {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
    }

    temp = mergeHead;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
int main() {
    struct Node * head1 = NULL;
    struct Node * head2 = NULL;
    struct Node * temp1 = NULL;
    struct Node * temp2 = NULL;
    struct Node * newNode = NULL;
    int i, j,n, m;

    printf("\nEnter number of nodes for first linkedlist : ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter data for node %d : ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head1 == NULL) {
            head1 = newNode;
            temp1 = newNode;
        }
        else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }

    printf("\nEnter number of nodes for second linkedlist : ");
    scanf("%d", &m);

    for(j=0; j<m; j++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter data for node %d : ", j+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head2 == NULL) {
            head2 = newNode;
            temp2 = newNode;
        }
        else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    printf("\nFirst linkedlist : ");
    temp1 = head1;
    while(temp1 != NULL) {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL\n");

    printf("Second linkedlist : ");
    temp2 = head2;
    while(temp2 != NULL) {
        printf("%d -> ", temp2->data);
        temp2 = temp2->next;
    }
    printf("NULL\n\n");

    printf("Sorted merged list : \n");
    mergesortedlist(head1, head2);
    return 0;
}