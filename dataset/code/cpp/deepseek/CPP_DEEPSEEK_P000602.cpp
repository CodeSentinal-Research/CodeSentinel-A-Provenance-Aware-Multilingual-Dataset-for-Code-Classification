#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

Node* insert(Node* head, int insertVal) {
    if (head == nullptr) {
        Node* node = new Node(insertVal);
        node->next = node;
        head = node;
        return node;
    }

    Node* current = head;
    while (true) {
        if (current->val <= insertVal && insertVal <= current->next->val) {
            break;
        } else if (current->val > current->next->val) {
            if (current->val <= insertVal || insertVal <= current->next->val) {
                break;
            }
        } else {
            if (current->next == head) {
                break;
            }
        }
        current = current->next;
    }

    Node* node = new Node(insertVal);
    node->next = current->next;
    current->next = node;
    return head;
}

int main() {
    Node* head = nullptr;
    head = insert(head, 6);
    head = insert(head, 8);
    head = insert(head, 1);
    head = insert(head, 5);
    head = insert(head, 3);
    head = insert(head, 9);

    Node* ptr = head;
    do {
        cout << ptr->val << " ";
        ptr = ptr->next;
    } while (ptr != head);

    return 0;
}