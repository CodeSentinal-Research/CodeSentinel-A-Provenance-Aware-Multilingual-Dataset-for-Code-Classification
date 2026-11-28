#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

bool isSame(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->val != root2->val) return false;
    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

int main() {
    int N;
    cin >> N;
    queue<pair<Node*, Node*>> q;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        Node* node = new Node(val);
        if (i == 0) {
            root1 = node;
        } else {
            q.push({root1, node});
            while (!q.empty()) {
                auto p = q.front(); q.pop();
                if (p.first->left) q.push({p.first->left, p.second->left});
                if (p.first->right) q.push({p.first->right, p.second->right});
                if (p.second->left) q.push({p.first->left, p.second->left});
                if (p.second->right) q.push({p.first->right, p.second->right});
            }
        }
    }
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        Node* node = new Node(val);
        if (i == 0) {
            root2 = node;
        } else {
            q.push({root2, node});
            while (!q.empty()) {
                auto p = q.front(); q.pop();
                if (p.first->left) q.push({p.first->left, p.second->left});
                if (p.first->right) q.push({p.first->right, p.second->right});
                if (p.second->left) q.push({p.first->left, p.second->left});
                if (p.second->right) q.push({p.first->right, p.second->right});
            }
        }
        if (!isSame(root1, root2)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
This solution uses Breadth-First Search (BFS) to compare the two trees. It first creates two empty trees, and then uses a queue to keep track of the nodes in the trees. The nodes are pushed into the queue, and for each node, its left and right children are pushed into the queue. The comparison is done by comparing the values of the nodes. If the values are equal, the comparison is done recursively for the left and right children of the current node. If all values are equal, the trees are the same.