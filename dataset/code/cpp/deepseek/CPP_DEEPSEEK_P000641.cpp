#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value for node " << (i+1) << ": ";
        cin >> value;
        head = insertAtEnd(head, value);
    }

    return 0;
}