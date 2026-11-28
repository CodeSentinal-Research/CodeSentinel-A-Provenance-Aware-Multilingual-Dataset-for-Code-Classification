Sure, here is a simple C++ solution that reverses a doubly linked list.

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
};

Node* reverse(Node* head) {
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }

    return head;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->val = 1;
    head->prev = NULL;
    head->next = second;

    second->val = 2;
    second->prev = head;
    second->next = third;

    third->val = 3;
    third->prev = second;
    third->next = NULL;

    head = reverse(head);

    return 0;
}

This program creates a doubly linked list with three nodes. It then reverses the list by changing the next and prev pointers of each node. The `reverse` function iterates over the list, changing the next and prev pointers for each node, and finally returning the new head of the list.

The `main` function creates a new doubly linked list with three nodes, assigns values to the nodes, and then calls the `reverse` function to reverse the list.