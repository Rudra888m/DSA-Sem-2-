#include<stdio.h>
#define MAX 20

int adj[MAX][MAX];
int n;

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

void enqueue(int v) {
    if(front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    int value = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    return value;
}

void addNode() {
    if(n >= MAX) {
        printf("Max nodes reached.\n");
        return;
    }
    for(int i=0; i<n; i++) {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
    adj[n][n] = 0;
    printf("Node %d added.\n", n);
    n++;
}

void insertEdge(int u, int v) {
    if(u >= n || v >= n) {
        printf("Invalid nodes.\n");
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
    printf("Edge inserted between %d and %d\n", u, v);
}

void bfs(int start) {
    if(start >= n) {
        printf("Invalid node.\n");
        return;
    }
    int visited[MAX] = {0};
    front = rear = -1;
    printf("BFS traversal from node %d : ", start);
    visited[start] = 1;
    enqueue(start);
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        for(int i=0; i<n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

void display() {
    printf("Adjacency Matrix : \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, u, v;
    do {
        printf("\n---Graph Menu---\n");
        printf("1. Add Node\n");
        printf("2. Insert Edge\n");
        printf("3. BFS\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("----------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNode();
                break;
            case 2:
                printf("Enter u and v : ");
                scanf("%d %d", &u, &v);
                insertEdge(u, v);
                break;
            case 3:
                printf("Enter start node : ");
                scanf("%d", &u);
                bfs(u);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}