#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Function to move last node to front
void moveLastToFront(Node* &head) {
    if (!head || !head->next) return;

    Node* secLast = NULL;
    Node* last = head;

    // Find last and second last
    while (last->next) {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;  // Remove last from end
    last->next = head;     // Attach last to front
    head = last;           // Update head
}

// Helper to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    moveLastToFront(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}