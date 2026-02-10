#include<stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE], top = -1;

int isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if(top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void push() {
    int n;
    if(isFull())
        printf("Stack is overflow.\n");
    else {
        printf("Enter an element : ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void pop() {
    int n;
    if(isEmpty())
        printf("Stack is empty.\n");
    else {
        n = stack[top];
        top--;
        printf("poped element is %d\n", n);
    }
}

void peek() {
    if(isEmpty())
        printf("Stack is empty.\n");
    else {
        int n;
        n = stack[top];
        printf("Top value is %d\n", n);
    }
}

int main() {
    int choice;
    do {
        printf("\n-----Stack Menu-----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: printf("Exiting stack menu...\n"); break;
            default: printf("Invalid input. Try again\n");
        }
    } while (choice != 4);

    return 0;
}