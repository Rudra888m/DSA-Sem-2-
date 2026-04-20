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

struct Node * createTree() {
    int val;
    printf("Enter data (-1 for NULL) : ");
    scanf("%d", &val);
    
    if(val == -1)
        return NULL;

    struct Node * root = createNode(val);

    printf("Enter left child of %d\n", val);
    root->left = createTree();

    printf("Enter right child of %d\n", val);
    root->right = createTree();

    return root;
}

int Height(struct Node * root) {
    if(root == NULL)
        return 0;

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
    struct Node * root;

    printf("\nCreate binary tree : \n");
    root = createTree();

    printf("\nHeight of binary tree : %d\n", Height(root));

    return 0;
}