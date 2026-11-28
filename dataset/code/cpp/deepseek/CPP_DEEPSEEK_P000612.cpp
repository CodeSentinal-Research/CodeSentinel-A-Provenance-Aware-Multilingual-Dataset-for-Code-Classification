#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

Node* insertGCDNodes(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        int gcdVal = gcd(cur->val, cur->next->val);
        cur->next = new Node(gcdVal);
        cur = cur->next->next;
    }
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);

    cout << "Original Linked List: ";
    printList(head);

    head = insertGCDNodes(head);

    cout << "Modified Linked List: ";
    printList(head);

    return 0;
}

This code implements the `insertGCDNodes` function which calculates the greatest common divisor (GCD) of the values of adjacent nodes in the linked list and inserts a new node with the GCD value at every pair of adjacent nodes. The `printList` function is used to print the linked list.

The `main` function demonstrates how to use the `insertGCDNodes` function. It creates a linked list with the values 10, 15, 20, and 25. It prints the original linked list, inserts the GCD nodes in the linked list, and prints the modified linked list.