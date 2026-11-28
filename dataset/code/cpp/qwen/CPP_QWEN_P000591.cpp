#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n1, n2, skip1, skip2;
    cin >> n1 >> n2 >> skip1 >> skip2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++) cin >> a[i];
    for (int i = 0; i < n2; i++) cin >> b[i];
    ListNode* common = nullptr;
    if (skip1 < n1 && skip2 < n2) {
        common = new ListNode(a[skip1]);
        ListNode* curr = common;
        for (int i = skip1 + 1; i < n1; i++) {
            curr->next = new ListNode(a[i]);
            curr = curr->next;
        }
    }
    ListNode* headA = nullptr;
    if (skip1 > 0) {
        headA = new ListNode(a[0]);
        ListNode* curr = headA;
        for (int i = 1; i < skip1; i++) {
            curr->next = new ListNode(a[i]);
            curr = curr->next;
        }
        curr->next = common;
    } else {
        headA = common;
    }
    ListNode* headB = nullptr;
    if (skip2 > 0) {
        headB = new ListNode(b[0]);
        ListNode* curr = headB;
        for (int i = 1; i < skip2; i++) {
            curr->next = new ListNode(b[i]);
            curr = curr->next;
        }
        curr->next = common;
    } else {
        headB = common;
    }
    // Find intersection
    ListNode* pA = headA, *pB = headB;
    while (pA != pB) {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    if (pA) {
        cout << pA->val << endl;
    } else {
        cout << "null" << endl;
    }
    return 0;
}
