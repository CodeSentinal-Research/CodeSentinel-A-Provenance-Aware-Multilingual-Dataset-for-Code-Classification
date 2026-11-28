#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

int height(Node* node) {
    if (node == NULL)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

void printVerticalOrder(Node* root) {
    int h = height(root);
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();

        if (mp.find(p.second) == mp.end()) {
            mp[p.second] = {p.first->data};
        } else {
            mp[p.second].push_back(p.first->data);
        }

        if (p.first->left)
            q.push({p.first->left, p.second - 1});
        if (p.first->right)
            q.push({p.first->right, p.second + 1});
    }

    for (auto i = mp.begin(); i != mp.end(); i++) {
        for (auto j = i->second.begin(); j != i->second.end(); j++) {
            cout << *j << " ";
        }
        cout << "\n";
    }
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printVerticalOrder(root);

    return 0;
}