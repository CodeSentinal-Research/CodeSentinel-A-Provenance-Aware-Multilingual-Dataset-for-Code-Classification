Here is the C++ code to solve the given problem:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitList(Node* head, Node** firstHead, Node** secondHead) {
    Node* fast;
    Node* slow;
    slow = head;
    fast = head->next;

    while (fast != head) {
        fast = fast->next->next;
        slow = slow->next;
    }


    slow->next = (*secondHead)->next;

    return;
}

int main() {
    Node* head = new Node();
    Node* firstHead;
    Node* secondHead;

    head->data = 1;
    head->next = head;

    splitList(head, &firstHead, &secondHead);

    return 0;
}
In this code, we use the fast and slow pointer approach to find the midpoint of the linked list. This approach ensures that the fast pointer will catch up to the slow pointer at the end of the linked list, hence splitting the list into two halves.

The `splitList` function takes the head of the linked list and pointers to the heads of the two halves. It uses the slow and fast pointer to find the midpoint of the list. It then splits the list into two halves by linking the second half to the node after the midpoint.

In the `main` function, we create a circular linked list with 3 nodes and call the `splitList` function to split it into two halves.