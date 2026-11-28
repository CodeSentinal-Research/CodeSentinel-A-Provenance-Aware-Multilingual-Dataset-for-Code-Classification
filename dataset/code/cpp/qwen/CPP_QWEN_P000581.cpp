#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    ListNode* l1 = nullptr, *l2 = nullptr;
    if (n > 0) {
        l1 = new ListNode(a[0]);
        ListNode* curr = l1;
        for (int i = 1; i < n; i++) {
            curr->next = new ListNode(a[i]);
            curr = curr->next;
        }
    }
    if (m > 0) {
        l2 = new ListNode(b[0]);
        ListNode* curr = l2;
        for (int i = 1; i < m; i++) {
            curr->next = new ListNode(b[i]);
            curr = curr->next;
        }
    }
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    ListNode* head = dummy.next;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
