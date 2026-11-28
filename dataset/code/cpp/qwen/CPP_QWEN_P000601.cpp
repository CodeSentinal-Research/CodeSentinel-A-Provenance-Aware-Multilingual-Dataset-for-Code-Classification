#include <iostream>
#include <vector>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int main() {
    int n, k; cin >> n >> k;
    vector<int> vals(n);
    for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) {
        if(!head) { head = new ListNode(vals[i]); curr = head; }
        else { curr->next = new ListNode(vals[i]); curr = curr->next; }
    }
    int len = n, size = len / k, rem = len % k;
    curr = head;
    for(int i=0; i<k; i++) {
        int part_size = size + (i < rem ? 1 : 0);
        for(int j=0; j<part_size-1 && curr; j++) curr = curr->next;
        if(curr) { ListNode* nxt = curr->next; curr->next = nullptr; curr = nxt; }
    }
    return 0;
}
