#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode *child;
  ListNode(int x) : val(x), next(NULL), child(NULL) {}
};

ListNode* flatten(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode *curr = head, *tail = head, *nextNode;
    while (curr != NULL) {
        if (curr->child) {
            nextNode = curr->child;
            tail->next = flatten(curr->child);
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = flatten(nextNode->next);
            curr->child = NULL;
            curr = curr->next;
        } else {
            tail = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->child = new ListNode(6);
    head->next->next->next->next->child->next = new ListNode(7);
    head->next->next->next->next->child->child = new ListNode(8);

    ListNode *newHead = flatten(head);
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}
This code first creates a multi-level linked list and then flattens it using the `flatten` function. It prints out the flattened linked list values.