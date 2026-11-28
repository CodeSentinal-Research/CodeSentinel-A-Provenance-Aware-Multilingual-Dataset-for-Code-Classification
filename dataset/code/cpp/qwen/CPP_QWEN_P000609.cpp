#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n; cin >> n; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    unordered_map<int, ListNode*> prefixSum; int sum = 0;
    ListNode dummy(0); dummy.next = head; prefixSum[0] = &dummy; curr = head;
    while(curr) {
        sum += curr->val;
        if(prefixSum.count(sum)) {
            ListNode* prev = prefixSum[sum]; prev->next = curr->next;
            ListNode* temp = prev->next;
            while(temp != curr->next) { sum -= temp->val; prefixSum.erase(sum); temp = temp->next; }
        } else prefixSum[sum] = curr;
        curr = curr->next;
    }
    return 0;
}
