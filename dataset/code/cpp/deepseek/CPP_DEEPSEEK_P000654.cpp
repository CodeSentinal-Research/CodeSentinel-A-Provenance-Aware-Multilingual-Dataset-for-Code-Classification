#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rearrange(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = slow->next;
    slow->next = NULL;
    second = rearrange(second);

    ListNode *newHead = merge(head, second);

    return newHead;
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    head->next = second;
    second->next = third;
    third->next = fourth;

    ListNode *result = rearrange(head);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}