#include <stdio.h>
#define MAXSIZE 5

int stack1[MAXSIZE], stack2[MAXSIZE];
int top1 = -1, top2 = -1;

int isStackEmpty(int top) {
    return top == -1;
}

int isStackFull(int top) {
    return top == MAXSIZE - 1;
}

void Enqueue() {
    int n;
    if (isStackFull(top1) && !isStackEmpty(top2)) {
        printf("Queue overflow\n");
        return;
    }

    printf("Enter an element: ");
    scanf("%d", &n);

    if (isStackFull(top1) && isStackEmpty(top2)) {
        printf("Queue overflow\n");
        return;
    }

    top1++;
    stack1[top1] = n;
}

void Dequeue() {
    int n;

    if (isStackEmpty(top1) && isStackEmpty(top2)) {
        printf("Queue is empty\n");
        return;
    }

    if (isStackEmpty(top2)) {
        while (!isStackEmpty(top1)) {
            top2++;
            stack2[top2] = stack1[top1];
            top1--;
        }
    }

    n = stack2[top2];
    top2--;
    printf("Deleted element is %d\n", n);
}

void FrontElement() {
    int n;

    if (isStackEmpty(top1) && isStackEmpty(top2)) {
        printf("Queue is empty\n");
        return;
    }

    if (isStackEmpty(top2)) {
        while (!isStackEmpty(top1)) {
            top2++;
            stack2[top2] = stack1[top1];
            top1--;
        }
    }

    n = stack2[top2];
    printf("Front element is %d\n", n);
}

void DisplayQueue() {
    int i;

    if (isStackEmpty(top1) && isStackEmpty(top2)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    for (i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    for (i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n----Queue Using Two Stacks Menu----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front element\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: FrontElement(); break;
            case 4: DisplayQueue(); break;
            case 5: printf("Exiting Queue...\n"); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }

    } while (choice != 5);

    return 0;
}
