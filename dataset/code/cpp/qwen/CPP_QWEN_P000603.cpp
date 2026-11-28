#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n, x; cin >> n >> x;
    vector<int> vals(n);
    for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) {
        if(!head) { head = new ListNode(vals[i]); curr = head; }
        else { curr->next = new ListNode(vals[i]); curr = curr->next; }
    }
    ListNode before(0), after(0);
    ListNode *bTail = &before, *aTail = &after;
    curr = head;
    while(curr) {
        if(curr->val < x) { bTail->next = curr; bTail = curr; }
        else { aTail->next = curr; aTail = curr; }
        curr = curr->next;
    }
    bTail->next = after.next; aTail->next = nullptr;
    return 0;
}
