#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n, target; cin >> n >> target; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    bool found = false; curr = head;
    while(curr) { if(curr->val == target) { found = true; break; } curr = curr->next; }
    cout << (found ? "true" : "false") << endl; return 0;
}
