#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertIntoSorted(ListNode* head, int value) {
    ListNode* node = new ListNode(value);
    if (head == NULL || head->val > value) {
        node->next = head;
        head = node;
    } else {
        ListNode* cur = head;
        while (cur->next != NULL && cur->next->val < value) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}

int main() {
    return 0;
}