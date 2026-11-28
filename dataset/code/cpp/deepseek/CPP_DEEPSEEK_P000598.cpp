#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* pre = &dummy;
    pre->next = left > 1 ? pre->next : pre;
    ListNode* leftNode = pre;
    for(int i = 1; i < left; i++)
        leftNode = leftNode->next;
    ListNode* rightNode = leftNode;
    for(int i = left; i <= right; i++)
        rightNode = rightNode->next;
    ListNode* cur = rightNode->next;
    for(int i = right - left + 1; i > 0; i--) {
        ListNode* tmp = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = tmp;
    }
    leftNode->next = pre->next;
    rightNode->next = cur;
    return dummy.next;
}