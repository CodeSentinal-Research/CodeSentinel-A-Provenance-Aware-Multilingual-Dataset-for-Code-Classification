#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy, *end = &dummy;
    while (head) {
        for (int i = 0; i < k && end; ++i) end = end->next;
        if (!end) break;
        ListNode *next = end->next;
        for (ListNode *prevNode = prev, *curr = head, *nextNode; curr != next; ) {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        prev->next = next;
        for (int i = 0; i < k && prev != end; ++i) prev = prev->next;
        head = prev;
    }
    return dummy.next;
}

int main(void) {
    return 0;
}