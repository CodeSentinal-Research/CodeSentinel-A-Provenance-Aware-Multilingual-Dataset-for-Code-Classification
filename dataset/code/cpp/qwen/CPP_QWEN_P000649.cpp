#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n, m; cin >> n >> m; vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i]; for(int i=0; i<m; i++) cin >> b[i];
    ListNode* l1 = nullptr; ListNode* c1 = nullptr;
    for(int i=0; i<n; i++) { if(!l1) { l1 = new ListNode(a[i]); c1 = l1; } else { c1->next = new ListNode(a[i]); c1 = c1->next; } }
    ListNode* l2 = nullptr; ListNode* c2 = nullptr;
    for(int i=0; i<m; i++) { if(!l2) { l2 = new ListNode(b[i]); c2 = l2; } else { c2->next = new ListNode(b[i]); c2 = c2->next; } }
    bool identical = true;
    while(l1 && l2) { if(l1->val != l2->val) { identical = false; break; } l1 = l1->next; l2 = l2->next; }
    if(l1 || l2) identical = false;
    cout << (identical ? "true" : "false") << endl; return 0;
}
