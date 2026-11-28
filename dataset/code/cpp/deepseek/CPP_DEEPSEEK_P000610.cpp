Here is the C++ code for the problem. We will use two pointers to traverse the linked list and calculate the sum of the nodes between zeros.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode preHead(0);
    ListNode* pre = &preHead;
    while (l1 && l2) {
        if (l1->val == 0 && l2->val == 0) {
            pre->next = new ListNode(l1->val + l2->val);
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1->val == 0 && l2->val != 0) {
            pre->next = new ListNode(l2->val);
            pre = pre->next;
            l2 = l2->next;
        } else if (l1->val != 0 && l2->val == 0) {
            pre->next = new ListNode(l1->val);
            pre = pre->next;
            l1 = l1->next;
        } else {
            pre->next = new ListNode(l1->val + l2->val);
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return preHead.next;
}

int main() {
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    ListNode* l3 = new ListNode(1);
    ListNode* l4 = new ListNode(0);
    ListNode* l5 = new ListNode(0);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    ListNode* result = mergeTwoLists(l1, l2);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}

This code first creates the input linked lists. Then, it merges these two lists by iterating through them and replacing the nodes with the sum of their values between zeros. The `mergeTwoLists` function merges two linked lists by iterating through them and replacing the nodes. The `main` function creates the input linked lists, merges them, and prints the result.