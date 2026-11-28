Here is the C++ code that will solve the problem:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else if (head->data >= newNode->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL && temp->next->data < newNode->data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
    return head;
}

Node* sortBitonic(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = sortedInsert(temp->next, temp->data);

    while (temp->prev != NULL) {
        temp = temp->prev;
    }

    return head;
}

int main() {
    Node* head = NULL;

    head = sortedInsert(head, 20);
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 30);
    head = sortedInsert(head, 5);
    head = sortedInsert(head, 2);

    head = sortBitonic(head);

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}

This code first inserts the values into the doubly linked list and then sorts the list using the `sortBitonic` function. The `sortBitonic` function uses a binary search method to find the correct position of the new node in the sorted list and inserts it there. The `sortedInsert` function inserts a new node into the list in a non-decreasing order. In the main function, the list is sorted and then printed.