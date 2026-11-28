#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int threshold) {
    if (!head) return nullptr;
    head->next = removeElements(head->next, threshold);
    return head->val > threshold ? head : ListNode*)(head->next);
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int threshold = 3;
    ListNode* result = removeElements(head, threshold);

    while(result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}