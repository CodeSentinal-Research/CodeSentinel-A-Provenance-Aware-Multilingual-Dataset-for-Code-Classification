#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n; cin >> n; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    ListNode *prev = nullptr; curr = slow;
    while(curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
    int maxSum = 0; ListNode *first = head, *second = prev;
    while(second) { maxSum = max(maxSum, first->val + second->val); first = first->next; second = second->next; }
    cout << maxSum << endl; return 0;
}
