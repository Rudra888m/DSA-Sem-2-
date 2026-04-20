#include<stdio.h>
#define MAX 20

int adj[MAX][MAX];
int n = 0;

void addNode() {
    if(n>=MAX) {
        printf("Max nodes reached.\n");
        return;
    }

    n++;
    for(int i=0; i<n; i++) {
        adj[i][n-1] = 0;
        adj[n-1][i] = 0;
    }
    printf("Node %d added.\n", n-1);
}

void deleteNode(int node) {
    if(node>=n) {
        printf("Invalid node.\n");
        return;
    }
    for (int i = node; i < n-1; i++) {
        for(int j=0; j<n; j++) {
            adj[i][j] = adj[i+1][j];
        }
    }
    for(int j = node; j < n-1; j++) {
        for(int i=0; i<n-1; i++) {
            adj[i][j] = adj[i][j+1];
        }
    }
    n--;
    printf("Node %d deleted.\n", node);
}

void insertEdge(int u, int v) {
    if(u >=n || v >= n) {
        printf("Invalid nodes.\n");
        return;
    }
    adj[u][v] = 1;
    printf("Edge inserted from %d to %d\n", u, v);
}

void deleteEdge(int u, int v) {
    if(u >=n || v >= n) {
        printf("Invalid nodes.\n");
        return;
    }
    adj[u][v] = 0;
    printf("Edge deleted from %d to %d\n", u, v);
}

void degree(int node) {
    if(node >= n) {
        printf("Invalid node.\n");
        return;
    }
    int in = 0, out = 0;
    for(int i=0; i<n; i++) {
        if(adj[node][i] == 1)
            out++;
    }
    for(int i=0; i<n; i++) {
        if(adj[i][node] == 1)
            in++;
    }

    printf("Node %d -> In-degree : %d, Out-degree : %d\n", node, in ,out);
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
        printf("\n---Welcome to graphs---\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Insert Edge\n");
        printf("4. Delete Edge\n");
        printf("5. Degree\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("-----------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                addNode();
                break;
            case 2:
                printf("Enter node to delete : ");
                scanf("%d", &u);
                deleteNode(u);
                break;
            case 3:
                printf("Enter u and v : ");
                scanf("%d %d", &u, &v);
                insertEdge(u, v);
                break;
            case 4:
                printf("Enter u and v : ");
                scanf("%d %d", &u, &v);
                deleteEdge(u, v);
                break;
            case 5:
                printf("Enter node : ");
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
                printf("Invalid input. Try again.\n");
                break;
        }
    } while(choice != 7);

    return 0;
}