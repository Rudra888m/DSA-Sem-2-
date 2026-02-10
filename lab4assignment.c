#include <stdio.h>
#define MAXSIZE 10

int pq[MAXSIZE];
int front = -1, rear = -1;

int isFull() {
    if (rear == MAXSIZE - 1)
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

void Enqueue() {
    int n, i;

    if (isFull())
        printf("Priority Queue is overflow\n");
    else {
        printf("Enter an element : ");
        scanf("%d", &n);

        if (isEmpty()) {
            front = rear = 0;
            pq[rear] = n;
        }
        else {
            i = rear;

            while (i >= front && pq[i] < n) {
                pq[i + 1] = pq[i];
                i--;
            }

            pq[i + 1] = n;
            rear++;
        }
    }
}

void Dequeue() {
    int n;

    if (isEmpty())
        printf("Priority Queue is empty\n");
    else {
        n = pq[front];

        if (front == rear) {
            front = rear = -1;
        }
        else
            front++;

        printf("Deleted element is %d\n", n);
    }
}

void FrontElement() {
    if (isEmpty())
        printf("Priority Queue is empty\n");
    else
        printf("Highest priority element: %d\n", pq[front]);
}

void DisplayQueue() {
    int i;

    if (isEmpty())
        printf("Priority Queue is empty\n");
    else {
        printf("Elements of Priority Queue : ");
        for (i = front; i <= rear; i++)
            printf("%5d", pq[i]);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n----Descending Priority Queue Menu----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front element\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: FrontElement(); break;
            case 4: DisplayQueue(); break;
            case 5: printf("Exiting Priority Queue...\n"); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }

    } while (choice != 5);

    return 0;
}
