#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != slow) {
        if (fast == nullptr || slow->next == nullptr) {
            return head;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == nullptr) {
        return head;
    }

    fast->next = nullptr;

    return head;
}

int main() {
    Node* head = new Node();
    head->data = 1;
    Node* second = new Node();
    second->data = 2;
    head->next = second;
    Node* third = new Node();
    third->data = 3;
    second->next = third;
    third->next = second;

    head = removeLoop(head);

    return 0;
}