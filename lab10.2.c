#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adj[MAX];
int n = 0;

/* Create a new node */
struct Node *createNode(int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Add a new vertex */
void addNode() {
    if (n >= MAX) {
        printf("Max nodes reached.\n");
        return;
    }

    adj[n] = NULL;
    printf("Node %d added.\n", n);
    n++;
}

/* Insert directed edge u -> v */
void insertEdge(int u, int v) {
    if (u >= n || v >= n) {
        printf("Invalid nodes.\n");
        return;
    }

    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    printf("Edge inserted from %d to %d.\n", u, v);
}

/* Delete edge u -> v */
void deleteEdge(int u, int v) {
    if (u >= n || v >= n) {
        printf("Invalid nodes.\n");
        return;
    }

    struct Node *temp = adj[u];
    struct Node *prev = NULL;

    while (temp != NULL) {
        if (temp->vertex == v) {
            if (prev == NULL)
                adj[u] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Edge deleted from %d to %d.\n", u, v);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Edge not found.\n");
}

/* Delete a vertex completely */
void deleteNode(int node) {
    if (node >= n) {
        printf("Invalid node.\n");
        return;
    }

    /* Step 1: delete adjacency list of node */
    struct Node *temp = adj[node];
    while (temp != NULL) {
        struct Node *t = temp;
        temp = temp->next;
        free(t);
    }
    adj[node] = NULL;

    /* Step 2: remove all incoming edges */
    for (int i = 0; i < n; i++) {
        struct Node *curr = adj[i];
        struct Node *prev = NULL;

        while (curr != NULL) {
            if (curr->vertex == node) {
                struct Node *del = curr;

                if (prev == NULL)
                    adj[i] = curr->next;
                else
                    prev->next = curr->next;

                curr = curr->next;
                free(del);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    printf("Node %d deleted.\n", node);
}

/* In-degree + Out-degree */
void degree(int node) {
    if (node >= n) {
        printf("Invalid node.\n");
        return;
    }

    int in = 0, out = 0;

    /* Out-degree */
    struct Node *temp = adj[node];
    while (temp != NULL) {
        out++;
        temp = temp->next;
    }

    /* In-degree */
    for (int i = 0; i < n; i++) {
        temp = adj[i];
        while (temp != NULL) {
            if (temp->vertex == node)
                in++;
            temp = temp->next;
        }
    }

    printf("Node %d -> In-degree: %d, Out-degree: %d\n", node, in, out);
}

/* Display graph */
void display() {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node *temp = adj[i];

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/* MAIN */
int main() {
    int choice, u, v;

    do {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Insert Edge\n");
        printf("4. Delete Edge\n");
        printf("5. Degree\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("------------------\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNode();
                break;

            case 2:
                printf("Enter node to delete: ");
                scanf("%d", &u);
                deleteNode(u);
                break;

            case 3:
                printf("Enter u and v: ");
                scanf("%d %d", &u, &v);
                insertEdge(u, v);
                break;

            case 4:
                printf("Enter u and v: ");
                scanf("%d %d", &u, &v);
                deleteEdge(u, v);
                break;

            case 5:
                printf("Enter node: ");
                scanf("%d", &u);
                degree(u);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid input.\n");
        }

    } while (choice != 7);

    return 0;
}