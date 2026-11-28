#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int k; cin >> k;
    vector<ListNode*> lists(k);
    for (int i = 0; i < k; i++) {
        int n; cin >> n;
        if (n == 0) continue;
        vector<int> vals(n);
        for (int j = 0; j < n; j++) cin >> vals[j];
        lists[i] = new ListNode(vals[0]);
        ListNode* curr = lists[i];
        for (int j = 1; j < n; j++) {
            curr->next = new ListNode(vals[j]);
            curr = curr->next;
        }
    }
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (ListNode* list : lists) {
        if (list) pq.push(list);
    }
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    ListNode* head = dummy.next;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
