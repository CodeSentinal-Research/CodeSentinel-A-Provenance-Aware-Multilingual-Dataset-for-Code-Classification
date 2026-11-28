#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n; cin >> n; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    unordered_set<int> seen; ListNode dummy(0); dummy.next = head; curr = head; ListNode* prev = &dummy;
    while(curr) {
        if(seen.count(curr->val)) { prev->next = curr->next; delete curr; curr = prev->next; }
        else { seen.insert(curr->val); prev = curr; curr = curr->next; }
    }
    return 0;
}
