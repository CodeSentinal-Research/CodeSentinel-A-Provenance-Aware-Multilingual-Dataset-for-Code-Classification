#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *bottom;
    ListNode *next;
    ListNode(int x) : val(x), bottom(NULL), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->val < l2->val) {
        l1->bottom = mergeTwoLists(l1->bottom, l2);
        return l1;
    } else {
        l2->bottom = mergeTwoLists(l1, l2->bottom);
        return l2;
    }
}

int main() {
    return 0;
}