#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;
    if (n == 0) return 0;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    while (prev->next && prev->next->next) {
        ListNode* curr = prev->next;
        ListNode* next = curr->next;
        while (next && curr->val == next->val) {
            next = next->next;
        }
        if (curr->next != next) {
            prev->next = next;
        } else {
            prev = prev->next;
        }
    }
    head = dummy.next;
    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
