#include<stdio.h>
#include<stdlib.h>
 
struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct stack {
    struct Node * data[100];
    int top;
};

void push (struct stack * s, struct Node * node) {
    s->data[++s->top] = node;
}

struct Node * pop (struct stack * s) {
    return s->data[s->top--];
}

int isEmptyStack(struct stack * s) {
    return s->top == -1;
}

struct Queue {
    struct Node * data[100];
    int front, rear;
};

void enqueue(struct Queue * q, struct Node * node) {
    q->data[++q->rear] = node;
}

struct Node * dequeue(struct Queue * q) {
    return q->data[++q->front];
}

int isEmptyQueue(struct Queue * q) {
    return q->rear == q->front;
}

struct Node * CreateNode(int val) {
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node * createTree() {
    int val;
    printf("Enter root value (-1 for no node) : ");
    scanf("%d", &val);

    if(val == -1)
        return NULL;
    
    struct Node * root = CreateNode(val);

    struct Queue q;
    q.front = q.rear = -1;

    enqueue(&q, root);

    while(!isEmptyQueue(&q)) {
        struct Node * curr = dequeue(&q);

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for no node) : ", curr->data);
        scanf("%d", &leftVal);

        if(leftVal != -1) {
            curr->left = CreateNode(leftVal);
            enqueue(&q, curr->left);
        }

        printf("Enter right child of %d (-1 for no node) : ", curr->data);
        scanf("%d", &rightVal);

        if(rightVal != -1) {
            curr->right = CreateNode(rightVal);
            enqueue(&q, curr->right);
        }
    }

    return root;
}

void preorder(struct Node * root) {
    struct stack s;
    s.top = -1;

    push(&s, root);
    while(!isEmptyStack(&s)) {
        struct Node * curr = pop(&s);
        printf("%d ", curr->data);

        if(curr->right)
            push(&s, curr->right);
        if(curr->left)
            push(&s, curr->left);
    }
}

void inorder(struct Node * root) {
    struct stack s;
    s.top = -1;
    struct Node * curr = root;

    while(curr != NULL || (!isEmptyStack(&s))) {
        while(curr != NULL) {
            push(&s, curr);
            curr = curr->left;
        }

        curr = pop(&s);
        printf("%d ", curr->data);

        curr = curr->right;
    }
}

void postorder(struct Node * root) {
    struct stack s1, s2;
    s1.top = s2.top = -1;

    push(&s1, root);
    while(!isEmptyStack(&s1)) {
        struct Node * curr = pop(&s1);
        push(&s2, curr);

        if(curr->left)
            push(&s1, curr->left);
        if(curr->right)
            push(&s1, curr->right);
    }

    while(!isEmptyStack(&s2)) {
        printf("%d ", pop(&s2)->data);
    }
}

void levelorder(struct Node * root) {
    struct Queue q;
    q.rear = q.front = -1;

    enqueue(&q, root);

    while(!isEmptyQueue(&q)) {
        struct Node * curr = dequeue(&q);
        printf("%d ", curr->data);

        if(curr->left)
            enqueue(&q, curr->left);
        if(curr->right)
            enqueue(&q, curr->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    
    do {
        printf("\n------------Menu------------\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Levelorder Traversal\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                root = createTree();
                break;
            case 2:
                printf("Preorder : ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder : ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder : ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Levelorder : ");
                levelorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}