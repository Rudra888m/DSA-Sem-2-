#include <stdio.h>
#define MAXSIZE 10

int front = -1, rear = -1;
int deque[MAXSIZE];

int isFull() {
    if ((rear + 1) % MAXSIZE == front)
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

void enqueueFront() {
    int n;
    if (isFull())
        printf("Deque is overflow\n");
    else {
        printf("Enter an element : ");
        scanf("%d", &n);

        if (isEmpty()) {
            front = rear = 0;
        }
        else
            front = (front - 1 + MAXSIZE) % MAXSIZE;

        deque[front] = n;
    }
}

void enqueueRear() {
    int n;
    if (isFull())
        printf("Deque is overflow\n");
    else {
        printf("Enter an element : ");
        scanf("%d", &n);

        if (isEmpty()) {
            front = rear = 0;
        }
        else
            rear = (rear + 1) % MAXSIZE;

        deque[rear] = n;
    }
}

void dequeueFront() {
    int n;
    if (isEmpty())
        printf("Deque is empty\n");
    else {
        n = deque[front];

        if (front == rear) {
            front = rear = -1;
        }
        else
            front = (front + 1) % MAXSIZE;

        printf("Deleted element is %d\n", n);
    }
}

void dequeueRear() {
    int n;
    if (isEmpty())
        printf("Deque is empty\n");
    else {
        n = deque[rear];

        if (front == rear) {
            front = rear = -1;
        }
        else
            rear = (rear - 1 + MAXSIZE) % MAXSIZE;

        printf("Deleted element is %d\n", n);
    }
}

void getFront() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void getRear() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void DisplayDeque() {
    int i;
    if (isEmpty())
        printf("Deque is empty\n");
    else {
        printf("Elements of deque : ");
        for (i = front; i != rear; i = (i + 1) % MAXSIZE)
            printf("%5d", deque[i]);
        printf("%5d\n", deque[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\n----Double ended queue Menu----\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueueFront(); break;
            case 2: enqueueRear(); break;
            case 3: dequeueFront(); break;
            case 4: dequeueRear(); break;
            case 5: getFront(); break;
            case 6: getRear(); break;
            case 7: DisplayDeque(); break;
            case 8: printf("Exiting Deque...\n"); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }

    } while (choice != 8);

    return 0;
}
