#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* solve(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    ListNode* curr = head;
    ListNode* maxNode = head->next;

    while (curr && maxNode) {
        if (curr->val > maxNode->val) {
            prev->next = maxNode;
            maxNode = maxNode->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    prev->next = NULL;
    return dummy.next;
}