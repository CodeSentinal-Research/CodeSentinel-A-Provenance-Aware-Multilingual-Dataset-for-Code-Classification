#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

Node* flatten(Node* head) {
    Node* pseudoHead = new Node();
    pseudoHead->next = head;

    Node* prev = pseudoHead;
    Node* curr = head;

    while (curr) {
        if (curr->child) {
            Node* next = curr->next;

            curr->next = curr->child;
            curr->child->prev = curr;

            prev->next = flatten(curr->child);
            (prev->next)->prev = prev;

            curr->child = nullptr;

            prev = (prev->next);
            curr = next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    head = pseudoHead->next;
    pseudoHead->next->prev = nullptr;

    return head;
}

int main() {
    int n, val;
    cin >> n;

    Node* head = nullptr;
    Node* prev = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> val;
        Node* node = new Node();
        node->val = val;

        if (i == 0) {
            head = node;
            prev = node;
        } else {
            prev->child = node;
            node->prev = prev;
            prev = node;
        }
    }

    head = flatten(head);

    Node* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }

    return 0;
}