#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL)
   {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void moveLastToFront(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL)
        return;
    struct Node *secondLast = NULL;
    struct Node *last = *head;
    while (last->next != NULL)
    {
        secondLast = last;
        last = last->next;
    }
    secondLast->next = NULL;
    last->next = *head;
    *head = last;
}
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() 
 {
    struct Node *head = NULL;
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }
    printf("\nOriginal List:\n");
    display(head);
    moveLastToFront(&head);
    printf("\nList after moving last node to front:\n");
    display(head);
    return 0;
}