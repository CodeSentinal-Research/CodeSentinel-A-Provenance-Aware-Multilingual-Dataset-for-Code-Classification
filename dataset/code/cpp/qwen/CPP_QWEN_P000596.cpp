#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* merge(ListNode* l, ListNode* r) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l && r) {
        if (l->val <= r->val) {
            tail->next = l;
            l = l->next;
        } else {
            tail->next = r;
            r = r->next;
        }
        tail = tail->next;
    }
    tail->next = l ? l : r;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    ListNode* l = sortList(head);
    ListNode* r = sortList(slow);
    return merge(l, r);
}

int main() {
    int n; cin >> n;
    if (n == 0) return 0;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    head = sortList(head);
    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
