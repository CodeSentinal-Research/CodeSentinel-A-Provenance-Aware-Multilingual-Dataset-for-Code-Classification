#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

int main() {
    int n; cin >> n;
    if (n == 0) return 0;
    vector<int> vals(n);
    vector<int> randoms(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    for (int i = 0; i < n; i++) cin >> randoms[i];
    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(new Node(vals[i]));
    }
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    for (int i = 0; i < n; i++) {
        if (randoms[i] != -1) {
            nodes[i]->random = nodes[randoms[i]];
        }
    }
    // Clone
    unordered_map<Node*, Node*> mp;
    Node* curr = nodes[0];
    while (curr) {
        mp[curr] = new Node(curr->val);
        curr = curr->next;
    }
    curr = nodes[0];
    while (curr) {
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }
    Node* clone = mp[nodes[0]];
    while (clone) {
        cout << clone->val << " ";
        clone = clone->next;
    }
    cout << endl;
    return 0;
}
