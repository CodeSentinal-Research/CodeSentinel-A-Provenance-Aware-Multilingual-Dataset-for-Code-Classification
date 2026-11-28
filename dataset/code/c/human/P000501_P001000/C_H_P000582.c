// Question: Remove duplicate nodes from a sorted singly linked list.
// Example Test Case:
// Input: 10 -> 10 -> 20 -> 30 -> 30 -> NULL
// Output: 10 -> 20 -> 30 -> NULL

/*
 * 🆕 REMOVE DUPLICATES FROM SORTED LINKED LIST
 * ---------------------------------------------
 * Remove duplicate elements from a sorted linked list.
 * Since list is sorted, duplicates are adjacent.
 *
 * Example: 1->1->2->3->3  ->  1->2->3
 *
 * Time Complexity : O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void removeDuplicates(Node *head) {
    if (!head) return;
    Node *curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node *dup = curr->next;
            curr->next = dup->next;
            free(dup);
        } else {
            curr = curr->next;
        }
    }
}

void printList(Node *head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

void freeList(Node *head) {
    Node *tmp;
    while (head) { tmp = head; head = head->next; free(tmp); }
}

int main() {
    // Test 1: 1->1->2->3->3
    Node *h1 = newNode(1);
    h1->next = newNode(1);
    h1->next->next = newNode(2);
    h1->next->next->next = newNode(3);
    h1->next->next->next->next = newNode(3);
    printf("Original: "); printList(h1);
    removeDuplicates(h1);
    printf("After:    "); printList(h1);

    // Test 2: All duplicates
    Node *h2 = newNode(7);
    h2->next = newNode(7);
    h2->next->next = newNode(7);
    printf("Original: "); printList(h2);
    removeDuplicates(h2);
    printf("After:    "); printList(h2);

    // Test 3: No duplicates
    Node *h3 = newNode(1);
    h3->next = newNode(2);
    h3->next->next = newNode(3);
    printf("Original: "); printList(h3);
    removeDuplicates(h3);
    printf("After:    "); printList(h3);

    // Test 4: Empty list
    removeDuplicates(NULL);
    printf("Empty list handled.\n");

    return 0;
}
