#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    int n; cin >> n; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    curr = head;
    while(curr && curr->next) {
        int g = gcd(curr->val, curr->next->val);
        ListNode* newNode = new ListNode(g); newNode->next = curr->next; curr->next = newNode; curr = newNode->next;
    }
    return 0;
}
