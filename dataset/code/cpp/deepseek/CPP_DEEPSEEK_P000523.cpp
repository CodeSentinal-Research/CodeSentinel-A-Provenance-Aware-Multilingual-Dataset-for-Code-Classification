Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNodes(ListNode* head) {
    if (!head) return head;
    ListNode* current = head;
    ListNode* temp = head->next;
    while (temp) {
        if (temp->val >= current->val) {
            current->next = temp;
            current = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    ListNode* new_head = removeNodes(head);

    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }

    return 0;
}

This code first defines the structure for a linked list node. It then defines a function `removeNodes` that takes the head of the linked list as input and returns the head of the modified linked list. The function iterates over the linked list and removes nodes that have a value greater than or equal to the current node's value. Finally, in the `main` function, a linked list is created and the `removeNodes` function is called to print the modified linked list.