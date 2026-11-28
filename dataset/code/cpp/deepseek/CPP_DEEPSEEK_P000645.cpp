#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(NULL), prev(NULL) {}
};

Node* reverseEvenLength(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* evenStart = head->next;
    Node* evenEnd = head->next;
    
    while (evenEnd->next != NULL && evenEnd->next->next != NULL) {
        Node* firstNode = evenEnd->next;
        Node* secondNode = evenEnd->next->next->next;
        
        evenEnd->next = secondNode;
        secondNode->prev = evenEnd;
        secondNode->next = firstNode;
        firstNode->prev = secondNode;
        
        evenEnd = firstNode;
    }
    
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    
    head = reverseEvenLength(head);
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    
    return 0;
}

This code defines a Node structure for the doubly linked list, and a function `reverseEvenLength` that reverses every adjacent pair of nodes in a doubly linked list. The `main` function demonstrates this function with an example list.