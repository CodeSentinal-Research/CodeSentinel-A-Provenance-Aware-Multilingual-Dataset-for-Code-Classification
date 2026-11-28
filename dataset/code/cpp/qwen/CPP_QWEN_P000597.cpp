#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *prev, *next, *child;
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

Node* flatten(Node* head) {
    if (!head) return head;
    Node* curr = head;
    while (curr) {
        if (curr->child) {
            Node* next = curr->next;
            Node* child = flatten(curr->child);
            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;
            while (child->next) child = child->next;
            if (next) {
                child->next = next;
                next->prev = child;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main() {
    int n; cin >> n;
    if (n == 0) return 0;
    vector<int> vals(n);
    vector<int> children(n, -1);
    for (int i = 0; i < n; i++) cin >> vals[i];
    for (int i = 0; i < n; i++) cin >> children[i];
    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(new Node(vals[i]));
    }
    for (int i = 0; i < n - 1; i++) {
        if (children[i] == -1) {
            nodes[i]->next = nodes[i + 1];
            nodes[i + 1]->prev = nodes[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (children[i] != -1) {
            nodes[i]->child = nodes[children[i]];
        }
    }
    Node* head = flatten(nodes[0]);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
