#include<stdio.h>
#define MAX 20

int adj[MAX][MAX];
int n;
int visited[MAX];

void addNode() {
    if(n >= MAX) {
        printf("Max nodes reached\n");
        return;
    }
    for(int i=0; i<n; i++) {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
    adj[n][n] = 0;
    printf("Node %d added\n", n);
    n++;
}

void insertEdge(int u, int v) {
    if(u >= n || v >= n) {
        printf("Invalid nodes\n");
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
    printf("Edge inserted between %d and %d\n", u, v);
}

void dfsHelper(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for(int i=0; i<n; i++) {
        if(adj[node][i] == 1 && !visited[i])
            dfsHelper(i);
    }
}

void dfs(int start) {
    if(start >= n) {
        printf("Invalid node\n");
        return;
    }
    for(int i=0; i<n; i++)
        visited[i] = 0;
    printf("DFS traversal from node %d : ", start);
    dfsHelper(start);
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
        printf("3. DFS\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("-----------------\n");
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
                dfs(u);
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