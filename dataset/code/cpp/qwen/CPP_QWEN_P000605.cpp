#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n; cin >> n;
    vector<int> vals(n);
    for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    curr = head;
    while(curr && curr->next) {
        if(curr->val < curr->next->val) { ListNode* temp = curr; curr = curr->next; delete temp; head = curr; }
        else break;
    }
    ListNode* prev = head; curr = head ? head->next : nullptr;
    while(curr) {
        if(prev->val < curr->val) { prev->next = curr->next; delete curr; curr = prev->next; }
        else { prev = curr; curr = curr->next; }
    }
    return 0;
}
