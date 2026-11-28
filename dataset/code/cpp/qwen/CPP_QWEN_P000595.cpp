#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++) cin >> a[i];
    for (int i = 0; i < n2; i++) cin >> b[i];
    ListNode* l1 = nullptr, *l2 = nullptr;
    if (n1 > 0) {
        l1 = new ListNode(a[0]);
        ListNode* curr = l1;
        for (int i = 1; i < n1; i++) {
            curr->next = new ListNode(a[i]);
            curr = curr->next;
        }
    }
    if (n2 > 0) {
        l2 = new ListNode(b[0]);
        ListNode* curr = l2;
        for (int i = 1; i < n2; i++) {
            curr->next = new ListNode(b[i]);
            curr = curr->next;
        }
    }
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
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
