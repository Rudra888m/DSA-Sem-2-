#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int value) {
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

struct Node* createTree() {
    int x;
    printf("Enter data (-1 for NULL): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node* root = createNode(x);

    printf("Enter left child of %d\n", x);
    root->left = createTree();

    printf("Enter right child of %d\n", x);
    root->right = createTree();

    return root;
}

int countLeaves(struct Node * root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    struct Node * root;

    printf("\nCreate binary tree : \n");
    root = createTree();

    int leafCount = countLeaves(root);

    printf("\nNumers of leaf nodes : %d\n", leafCount);

    return 0;
}