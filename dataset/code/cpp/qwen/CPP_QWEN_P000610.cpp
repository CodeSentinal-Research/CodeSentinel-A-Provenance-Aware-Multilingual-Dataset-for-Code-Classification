#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n; cin >> n; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    ListNode dummy(0); ListNode* resCurr = &dummy; curr = head->next;
    while(curr) {
        int sum = 0;
        while(curr && curr->val != 0) { sum += curr->val; curr = curr->next; }
        resCurr->next = new ListNode(sum); resCurr = resCurr->next;
        if(curr) curr = curr->next;
    }
    return 0;
}
