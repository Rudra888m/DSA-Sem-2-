#include<stdio.h>

#define MAXSIZE 100

int tree[MAXSIZE];
int n;

void createTree() {
    printf("Enter number of nodes : ");
    scanf("%d", &n);

    printf("Enter elements (level order) : ");
    for(int i=0; i<n; i++)
        scanf("%d", &tree[i]);
}

void parent(int i) {
    if(i<0 || i>=n) {
        printf("No parent\n");
        return;
    }
    if(i == 0) {
        printf("Root has no parent\n");
        return;
    }

    int parentIndex = (i - 1) / 2;
    printf("parent of %d is %d.\n", tree[i], tree[parentIndex]);
}

void children(int i) {
    if(i>=n) {
        printf("Inavlid index\n");
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n)
        printf("Left child : %d\n", tree[left]);
    else
        printf("No left child\n");

    if(right < n)
        printf("Right child : %d\n", tree[right]);
    else
        printf("No right child\n");
}

void sibling(int i) {
    if(i<0 || i>=n) {
        printf("No sibling\n");
        return;
    }
    if(i==0) {
        printf("Root has no sibling\n");
        return;
    }

    if(i % 2 == 0) {
        int siblingIndex = i - 1;
        if(siblingIndex >= 0 && siblingIndex < n)
            printf("Sibling : %d\n", tree[siblingIndex]);
        else
            printf("No sibling\n");
    }
    else {
        int siblingIndex = i + 1;
        if(siblingIndex >= 0 && siblingIndex < n)
            printf("Sibling : %d\n", tree[siblingIndex]);
        else
            printf("No sibling\n");
    }
}

int main() {
    int choice, index;

    do {
        printf("\n-------MENU-------\n");
        printf("1. Create Tree\n");
        printf("2. Get Parent\n");
        printf("3. Get Children\n");
        printf("4. Get Sibling\n");
        printf("5. Exit\n");
        printf("------------------\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                createTree();
                break;
            case 2:
                printf("Enter index : ");
                scanf("%d", &index);
                parent(index);
                break;
            case 3:
                printf("Enter index : ");
                scanf("%d", &index);
                children(index);
                break;
            case 4:
                printf("Enter index : ");
                scanf("%d", &index);
                sibling(index);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 5);

    return 0;
}