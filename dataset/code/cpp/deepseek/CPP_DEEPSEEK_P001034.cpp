#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& head : lists) {
            while(head != NULL) {
                pq.push(head->val);
                head = head->next;
            }
        }
        
        if(pq.empty()) return NULL;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()) {
            curr->next = new ListNode(pq.top());
            curr = curr->next;
            pq.pop();
        }
        
        return dummy->next;
    }
};

int main() {
    int k;
    cin >> k;

    vector<ListNode*> lists(k);
    for(int i = 0; i < k; i++) {
        int size;
        cin >> size;

        ListNode* head = NULL;
        ListNode* prev = NULL;
        for(int j = 0; j < size; j++) {
            int val;
            cin >> val;

            ListNode* node = new ListNode(val);
            if(i == 0) {
                head = node;
            } else {
                prev->next = node;
            }
            prev = node;
        }

        lists[i] = head;
    }

    Solution solution;
    ListNode* merged = solution.mergeKLists(lists);

    while(merged != NULL) {
        cout << merged->val << ' ';
        merged = merged->next;
    }
    cout << '\n';

    return 0;
}