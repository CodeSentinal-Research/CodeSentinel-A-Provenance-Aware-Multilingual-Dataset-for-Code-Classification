#include <stdio.h>
#include <stdlib.h>

/* BST Node */
struct node {
    int data;
    struct node *left, *right;
};

/* Queue for level order traversal */
struct queue {
    struct node* arr[50];
    int front, rear;
};

/* Create new BST node */
struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Insert into BST */
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

/* Initialize queue */
void initQueue(struct queue* q) {
    q->front = q->rear = -1;
}

/* Enqueue */
void enqueue(struct queue* q, struct node* temp) {
    if (q->rear == 49)
        return;
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = temp;
}

/* Dequeue */
struct node* dequeue(struct queue* q) {
    if (q->front > q->rear || q->front == -1)
        return NULL;
    return q->arr[q->front++];
}

/* Check if queue empty */
int isEmpty(struct queue* q) {
    return q->front == -1 || q->front > q->rear;
}

/* Display leaf nodes level-wise */
void displayLeafNodesLevelWise(struct node* root) {
    if (root == NULL)
        return;

    struct queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("Leaf nodes level-wise: ");

    while (!isEmpty(&q)) {
        struct node* temp = dequeue(&q);

        if (temp->left == NULL && temp->right == NULL) {
            printf("%d ", temp->data);
        }

        if (temp->left != NULL)
            enqueue(&q, temp->left);
        if (temp->right != NULL)
            enqueue(&q, temp->right);
    }
}

/* Main function */
int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    displayLeafNodesLevelWise(root);

    return 0;
}