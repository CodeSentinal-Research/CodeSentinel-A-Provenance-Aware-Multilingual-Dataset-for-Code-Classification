#include <iostream>
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
    // Assume we are given pointer to second node
    ListNode* node = new ListNode(vals[1]);
    node->next = nullptr;
    if (n > 2) {
        node->next = new ListNode(vals[2]);
        ListNode* curr = node->next;
        for (int i = 3; i < n; i++) {
            curr->next = new ListNode(vals[i]);
            curr = curr->next;
        }
    }
    // Delete node
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
    // Output entire list starting from first node (simulated)
    cout << vals[0] << " ";
    ListNode* curr = node;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
