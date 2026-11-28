#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head) return true;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse second half
    ListNode* prev = nullptr, *curr = slow->next;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // Compare
    bool res = true;
    ListNode* first = head, *second = prev;
    while (second) {
        if (first->val != second->val) {
            res = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    return res;
}

int main() {
    int n; cin >> n;
    if (n == 0) {
        cout << "true" << endl;
        return 0;
    }
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    cout << (isPalindrome(head) ? "true" : "false") << endl;
    return 0;
}
