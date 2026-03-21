#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

// Stack Functions...
struct Node * top = NULL;

int isEmptystack() {
    return top == NULL;  
}

int isFull() {
    struct Node * p = (struct Node *) malloc(sizeof(struct Node));
    if(p == NULL)
        return 1;
    free(p);
    return 0;
}
void stackpush(int x) {
    if(isFull()) {
        printf("Stack is overflow.\n");
        return;
    }
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n; 
}

void stackpop() {
    if(isEmptystack()) {
        printf("Stack is Empty.\n");
        return;
    }
    struct Node * n = top;
    top = top->next;
    int x = n->data;
    free(n);
    printf("%d popped.\n", x);      
}

void stackpeek(int pos) {
    struct Node * ptr = top;
    for(int i=0; i<pos-1 && ptr!=NULL; i++)
        ptr = ptr->next;
    if(ptr!=NULL)
        printf("%d is at %d position.\n", ptr->data, pos);
    else
        printf("Invalid position.\n");
}

void stackdisplay() {
    struct Node *ptr = top;
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Queue Functions...
struct Node * front = NULL;
struct Node * rear = NULL;

int isEmptyqueue() {
    return front == NULL && rear == NULL;
}

void enqueue(int x) {
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if(isEmptyqueue()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(isEmptyqueue()) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node * p = front;
    int x = front->data;
    front = front->next;
    if(front == NULL)
        rear = NULL;
    free(p);
    printf("%d is deleted.\n", x);
}

void Displayqueue() {
    if(isEmptyqueue()) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node * ptr = front;
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    // Stack operations...
    printf("Stack operations : \n");
    stackpush(10);
    stackpush(20);
    stackpush(30);
    stackdisplay();
    stackpop();
    stackdisplay();
    stackpeek(2);

    printf("\n\n");

    // Queue opertations...
    printf("Queue operatiions : \n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    Displayqueue();
    dequeue();
    Displayqueue();
    return 0;
}