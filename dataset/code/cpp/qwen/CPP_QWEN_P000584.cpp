#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n; cin >> n;
    if (n == 0) return 0;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    int k; cin >> k;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    ListNode* first = head;
    for (int i = 0; i < k; i++) {
        first = first->next;
    }
    ListNode* second = head;
    while (first->next) {
        first = first->next;
        second = second->next;
    }
    // Remove second->next
    ListNode* toDelete = second->next;
    if (toDelete) {
        second->next = toDelete->next;
        delete toDelete;
    }
    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
