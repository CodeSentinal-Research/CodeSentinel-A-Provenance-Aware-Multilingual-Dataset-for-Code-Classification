#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node* reverse(Node* head) {
    if (head == NULL || head->next == head) return head;
    
    Node* prev = head;
    Node* curr = head->next;
    
    while (curr != head) {
        Node* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    head->next = prev;
    
    return prev;
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;

    Node* head = node1;
    Node* newHead = reverse(head);

    while (newHead->next != head) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << newHead->val;

    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}