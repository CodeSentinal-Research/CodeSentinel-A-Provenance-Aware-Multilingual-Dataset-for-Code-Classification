#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int value) {
    if (!head) {
        return head;
    }
    if (head->val == value) {
        ListNode* temp = head->next;
        delete head;
        return temp;
    }
    ListNode* current = head;
    while (current->next != NULL) {
        if (current->next->val == value) {
            ListNode* temp = current->next->next;
            delete current->next;
            current->next = temp;
            return head;
        }
        current = current->next;
    }
    return head;
}