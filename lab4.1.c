#include <stdio.h>
#define MAXSIZE 10
int front = -1, rear = -1;
int queue[MAXSIZE];

int isFull() {
    if ((rear+1)%MAXSIZE == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (rear == -1 && front == -1)
        return 1;
    return 0;
}

void Enqueue() {
    int n;
    if (isFull())
        printf("Queue is overflow\n");
    else {
        printf("Enter an element : ");
        scanf("%d", &n);
        if(rear == -1 && front == -1) {
            front = 0;
            rear = 0;
        }
        else
            rear = (rear + 1) % MAXSIZE;
        queue[rear] = n;
    }
}

void Dequeue() {
    int n;
    if (isEmpty())
        printf("Queue is empty\n");

    else {
        n = queue[front];
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else
            front = (front+1) % MAXSIZE;
        printf("Deleted element is %d.\n", n);
    }
}

void FrontElement() {
    if (isEmpty())
        printf("Queue is empty\n");
    else 
        printf("Front element: %d\n", queue[front]);
}

void RearElement() {
    if (isEmpty())
        printf("Queue is empty\n");
    else 
        printf("Rear element: %d\n", queue[rear]);
}

void DisplayQueue() {
    int i;
    if (isEmpty())
        printf("Queue is empty\n");
    else {
        printf("Element of queue : ");
        for(i=front; i!=rear; i=(i+1)%MAXSIZE) {
            printf("%5d", queue[i]);
        }
        printf("%5d", queue[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\n----Circular Queue Menu----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front element\n");
        printf("4. Rear element\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: FrontElement(); break;
            case 4: RearElement(); break;
            case 5: DisplayQueue(); break;
            case 6: printf("Exiting Queue...\n"); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }

    } while (choice != 6);

    return 0;
}