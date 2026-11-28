#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

/*
 * ============================================
 *    DOUBLY LINKED LIST - Plug & Play
 * ============================================
 * HOW TO USE:
 *   1. Copy the STRUCT section first
 *   2. Copy createNode()
 *   3. Copy any function you need
 *   4. Check REQUIRES tag for dependencies
 * ============================================
 */

/* =========== STRUCT (Copy this first) =========== */
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

/* =========== createNode =========== */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* =========== insertAtBeginning =========== */
/* REQUIRES: createNode */
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

/* =========== insertAtEnd =========== */
/* REQUIRES: createNode */
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

/* =========== insertAtPosition (0-indexed) =========== */
/* REQUIRES: createNode, insertAtBeginning */
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos == 0) return insertAtBeginning(head, data);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) { printf("Position out of range\n"); free(newNode); return head; }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

/* =========== insertAfter =========== */
/* REQUIRES: createNode */
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) { printf("Previous node cannot be NULL\n"); return; }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

/* =========== deleteFromBeginning =========== */
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) { printf("List is empty\n"); return NULL; }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

/* =========== deleteFromEnd =========== */
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) { printf("List is empty\n"); return NULL; }
    if (head->next == NULL) { free(head); return NULL; }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

/* =========== deleteByValue =========== */
struct Node* deleteByValue(struct Node* head, int key) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) { printf("Value %d not found\n", key); return head; }
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

/* =========== deleteAtPosition (0-indexed) =========== */
struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) { printf("Position out of range\n"); return head; }
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

/* =========== search =========== */
int search(struct Node* head, int key) {
    int pos = 0;
    while (head != NULL) {
        if (head->data == key) return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

/* =========== getLength =========== */
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) { count++; head = head->next; }
    return count;
}

/* =========== reverse =========== */
struct Node* reverse(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* curr = head;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}

/* =========== sortList (Bubble Sort) =========== */
void sortList(struct Node* head) {
    if (head == NULL) return;
    int swapped;
    struct Node* ptr;
    struct Node* last = NULL;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

/* =========== isPalindrome =========== */
int isPalindrome(struct Node* head) {
    if (head == NULL) return 1;
    struct Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    struct Node* front = head;
    while (front != tail && front->prev != tail) {
        if (front->data != tail->data) return 0;
        front = front->next;
        tail = tail->prev;
    }
    return 1;
}

/* =========== removeDuplicatesSorted =========== */
void removeDuplicatesSorted(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = curr;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}

/* =========== mergeSorted =========== */
struct Node* mergeSorted(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    struct Node* result;
    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    if (result->next != NULL)
        result->next->prev = result;
    result->prev = NULL;
    return result;
}

/* =========== swapNodes (by value - swaps data) =========== */
struct Node* swapNodes(struct Node* head, int x, int y) {
    if (x == y) return head;
    struct Node *nodeX = head, *nodeY = head;
    while (nodeX != NULL && nodeX->data != x) nodeX = nodeX->next;
    while (nodeY != NULL && nodeY->data != y) nodeY = nodeY->next;
    if (nodeX == NULL || nodeY == NULL) return head;
    int temp = nodeX->data;
    nodeX->data = nodeY->data;
    nodeY->data = temp;
    return head;
}

/* =========== printForward =========== */
void printForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* =========== printBackward =========== */
void printBackward(struct Node* head) {
    if (head == NULL) { printf("Backward: NULL\n"); return; }
    struct Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    printf("Backward: ");
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

/* =========== freeList =========== */
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}