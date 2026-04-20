#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int val) {
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node * insert(struct Node * root, int val) {
    if(root == NULL)
        return createNode(val);
    if(val < root->data) 
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

struct Node * search(struct Node * root, int key) {
    if(root == NULL || root->data == key)
        return root;
    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct Node * findMin(struct Node * root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct Node * deleteNode(struct Node * root, int key) {
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        else if(root->left == NULL) {
            struct Node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node * temp = root->left;
            free(root);
            return temp;
        }

        struct Node * temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node * root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node * root = NULL;
    int choice, val;

    do {
        printf("\n---Welcome to binary search tree---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display(Inorder)\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter value : ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to search : ");
                scanf("%d", &val);
                if(search(root, val))
                    printf("Found!\n");
                else
                    printf("Not found!\n");
                break;
            case 3:
                printf("Enter value to delete : ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 4:
                printf("Inorder : ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default: 
                printf("Invalid input!\n");
                break;
        }
    } while(choice != 5);

    return 0;
}