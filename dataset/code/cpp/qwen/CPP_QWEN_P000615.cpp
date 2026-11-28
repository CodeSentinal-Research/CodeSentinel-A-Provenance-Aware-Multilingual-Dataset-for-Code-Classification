#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n; cin >> n; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    ListNode dummy(0); dummy.next = head; curr = &dummy; int groupSize = 1;
    while(curr->next) {
        ListNode* start = curr->next; ListNode* end = start; int count = 0;
        while(end && count < groupSize) { end = end->next; count++; }
        if(count % 2 == 0) {
            ListNode* prev = end; ListNode* c = start;
            for(int i=0; i<count; i++) { ListNode* next = c->next; c->next = prev; prev = c; c = next; }
            curr->next = prev; curr = start;
        } else { for(int i=0; i<count; i++) curr = curr->next; }
        groupSize++;
    }
    return 0;
}
