#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n, k; cin >> n >> k; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    ListNode dummy(0); dummy.next = head; curr = &dummy; int count = 1;
    while(curr->next) {
        if(count == k) { ListNode* temp = curr->next; curr->next = temp->next; delete temp; count = 1; }
        else { curr = curr->next; count++; }
    }
    return 0;
}
