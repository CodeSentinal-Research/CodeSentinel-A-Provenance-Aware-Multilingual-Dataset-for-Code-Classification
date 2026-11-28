#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator()(ListNode* l, ListNode* r) {
        return l->val > r->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(auto& head : lists) {
        if(head) pq.push(head);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(!pq.empty()) {
        ListNode* smallest = pq.top();
        pq.pop();

        tail->next = smallest;
        tail = tail->next;

        if(smallest->next) {
            pq.push(smallest->next);
        }
    }

    return dummy.next;
}

int main() {
    return 0;
}
This code uses a priority queue to hold the head of each list. The priority queue is initialized with the heads of the k lists. The priority queue is always maintaining the smallest element at the top. This way, the smallest element of the k lists is always at the front of the queue.

Then, we initialize a dummy node and a tail pointer. The tail pointer is used to append new nodes to the merged list.

We loop until the priority queue is empty. In each iteration, we remove the smallest element from the priority queue and append it to the merged list. After appending, we add the next node of the smallest element to the priority queue.

Finally, we return the dummy node's next node, which is the head of the merged list.