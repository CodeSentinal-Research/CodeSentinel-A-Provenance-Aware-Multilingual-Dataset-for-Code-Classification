#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n, k; cin >> n >> k; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    curr = head; for(int i=1; i<k && curr; i++) curr = curr->next;
    cout << (curr ? curr->val : -1) << endl; return 0;
}
