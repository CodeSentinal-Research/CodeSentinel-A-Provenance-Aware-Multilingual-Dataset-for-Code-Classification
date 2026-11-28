#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n, insertVal; cin >> n >> insertVal;
    vector<int> vals(n);
    for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) {
        if(!head) { head = new ListNode(vals[i]); curr = head; }
        else { curr->next = new ListNode(vals[i]); curr = curr->next; }
    }
    if(curr) curr->next = head;
    ListNode* newNode = new ListNode(insertVal);
    if(!head) { head = newNode; head->next = head; }
    else {
        ListNode* p = head;
        while(p->next != head && !((p->val <= insertVal && insertVal <= p->next->val) || (p->val > p->next->val && (insertVal >= p->val || insertVal <= p->next->val)))) p = p->next;
        newNode->next = p->next; p->next = newNode;
    }
    return 0;
}
