#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int Solution::findNthFromBeginning(ListNode* head, int n) {
    ListNode* current = head;
    for(int i = 0; i < n; i++) {
        if(current == NULL) {
            return -1;
        }
        current = current->next;
    }
    return current->val;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    int n = 2;
    cout << findNthFromBeginning(head, n);

    return 0;
}

This code firstly creates a singly linked list with four nodes. Then, it calls the `findNthFromBeginning` function and prints the value of the second node (which is the n-th node from the beginning). If the node does not exist, it returns -1.