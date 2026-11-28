Here is the code for the given problem:

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(NULL), prev(NULL) {}
};

Node* Solution(Node* head, int k) {
    if (!head)
        return head;

    Node* current = head;
    while (k--)
        current = current->prev;

    Node* new_head = current->prev;
    delete current;

    Node* temp = new_head;
    while (temp->next)
        temp = temp->next;

    temp->next = new_head;
    new_head->prev = temp;

    head->prev = new_head;
    new_head->next = head;

    return new_head;
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original list: ";
    printList(head);

    head = Solution(head, 2);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}

This code defines a doubly linked list node and a function `Solution` to rotate the list. The function takes in the head of the list and the number of rotations to perform. It first finds the new head of the list by traversing the list k times backward, then it connects the new head to the end of the list, and finally it updates the pointers of the list nodes.