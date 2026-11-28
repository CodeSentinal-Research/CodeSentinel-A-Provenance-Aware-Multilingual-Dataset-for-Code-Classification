#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    while(curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
    return prev;
}
int main() {
    int n1, n2; cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for(int i=0; i<n1; i++) cin >> a[i];
    for(int i=0; i<n2; i++) cin >> b[i];
    ListNode* l1 = nullptr; ListNode* c1 = nullptr;
    for(int i=0; i<n1; i++) { if(!l1) { l1 = new ListNode(a[i]); c1 = l1; } else { c1->next = new ListNode(a[i]); c1 = c1->next; } }
    ListNode* l2 = nullptr; ListNode* c2 = nullptr;
    for(int i=0; i<n2; i++) { if(!l2) { l2 = new ListNode(b[i]); c2 = l2; } else { c2->next = new ListNode(b[i]); c2 = c2->next; } }
    l1 = reverseList(l1); l2 = reverseList(l2);
    ListNode dummy(0); ListNode* curr = &dummy; int carry = 0;
    while(l1 || l2 || carry) {
        int sum = carry;
        if(l1) { sum += l1->val; l1 = l1->next; }
        if(l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10; curr->next = new ListNode(sum % 10); curr = curr->next;
    }
    reverseList(dummy.next);
    return 0;
}
