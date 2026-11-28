#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(NULL), prev(NULL) {}
};

Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto head : lists) {
        while (head != NULL) {
            pq.push(head->val);
            head = head->next;
        }
    }

    Node* head = new Node(pq.top());
    pq.pop();
    Node* temp = head;

    while (!pq.empty()) {
        Node* newNode = new Node(pq.top());
        pq.pop();
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    return head;
}

int main() {
    return 0;
}