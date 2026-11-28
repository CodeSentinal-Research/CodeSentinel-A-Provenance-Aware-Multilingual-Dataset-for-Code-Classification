#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val) : val(val), next(NULL), prev(NULL) {}
};

Node* reverse(Node* head, int k) {
    Node* curr = head;
    while (curr && k-- > 1) {
        curr = curr->next;
    }
    if (!curr) {
        return head;
    }
    Node* next = curr->next;
    curr->next = nullptr;
    Node* reversed = reverse(next, k);
    if (reversed) {
        curr->next = reversed;
        reversed->prev = curr;
    }
    return curr;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    int k = 2;
    head = reverse(head, k);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}

This program first creates a doubly linked list. The `reverse` function is used to reverse the list in groups of `k`. The `k` is decremented in each iteration to ensure we reverse enough nodes. If there are no more nodes left, we return the head of the list.

In the `main` function, the `reverse` function is called with a head of the list and `k`. The result is printed out.