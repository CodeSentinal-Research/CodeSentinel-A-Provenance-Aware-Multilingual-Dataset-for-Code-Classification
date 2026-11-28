Here is the code:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    for (int i = 0; i < k; i++) {
        first = first->next;
    }
    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    head = swapNodes(head, k);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
This program creates a dummy node and sets it to the head of the linked list. Then it finds the two nodes at the k-th position from the beginning and end of the list, swaps their values, and returns the modified linked list.

Please note that this code assumes that the input linked list is a singly linked list with at least k nodes. Also, the code assumes that the input k is valid (i.e., 1 ≤ k ≤ n).