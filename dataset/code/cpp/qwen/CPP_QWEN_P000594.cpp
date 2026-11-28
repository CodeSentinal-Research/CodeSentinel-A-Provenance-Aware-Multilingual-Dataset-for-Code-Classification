#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 0) return 0;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    k %= n;
    if (k == 0) {
        curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
        return 0;
    }
    ListNode* fast = head, *slow = head;
    for (int i = 0; i < k; i++) fast = fast->next;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* newHead = slow->next;
    slow->next = nullptr;
    fast->next = head;
    head = newHead;
    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
