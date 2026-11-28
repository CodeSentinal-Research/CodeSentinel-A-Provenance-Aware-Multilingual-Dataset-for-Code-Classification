Here is the C++ code for the problem:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int maxTwinSum(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    int twinSum = head->data + head->next->data;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        twinSum = slow->data + slow->next->data + twinSum;
    }
    return twinSum;
}

int main() {
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 5;
    cout << maxTwinSum(head); 
    return 0;
}

This code firstly creates a linked list with the given integer values. Then it calls the `maxTwinSum` function to find the maximum twin sum among all twin pairs. The `maxTwinSum` function uses two pointers, `slow` and `fast`, to iterate through the list. It initially sets `slow` and `fast` to the head of the list and moves them one step at a time. It then calculates the sum of the current twin pair and updates the `twinSum` variable. If the fast pointer reaches the end of the list, then the slow pointer will have reached the middle of the list and the loop will be exited. The maximum twin sum is then returned.