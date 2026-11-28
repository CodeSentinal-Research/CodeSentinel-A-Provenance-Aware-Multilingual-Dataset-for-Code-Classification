#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* reverseDoublyCircular(Node* head) {
    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    Node* current = head;
    while(current->prev != head) {
        Node* nextNode = current->next;
        Node* prevNode = current->prev;
        current->prev = current->next;
        current->next = prevNode;
        current = nextNode;
    }
    Node* headNode = head->prev;
    head->prev = temp;
    temp->next = head;
    head->prev = temp;
    head = headNode;
    return head;
}

int main() {
    Node* head = new Node();
    head->data = 1;
    head->next = head->prev = head;
    head->next->next->data = 2;
    head->next->next->next->data = 3;
    head->next->next->next->next->data = 4;
    head->next->next->next->next->next->data = 5;
    head = reverseDoublyCircular(head);
    while(head->next != head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
    return 0;
}

This code first creates a circular doubly linked list with the given data. It then calls the `reverseDoublyCircular` function to reverse the list. The `reverseDoublyCircular` function works by finding the tail of the list, reversing the list, and then swapping the head and tail.