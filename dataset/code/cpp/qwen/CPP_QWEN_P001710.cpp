#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node(int x) : val(x), left(NULL), right(NULL), random(NULL) {}
};

Node* buildTreeWithRandom(vector<int>& vals, vector<int>& randomIdx) {
    if (vals.empty()) return NULL;
    vector<Node*> nodes(vals.size());
    for (int i = 0; i < vals.size(); ++i) {
        nodes[i] = new Node(vals[i]);
    }
    
    queue<Node*> q;
    q.push(nodes[0]);
    int i = 1;
    int idx = 0;
    while (!q.empty() && i < vals.size()) {
        Node* node = q.front(); q.pop();
        if (i < vals.size()) {
            node->left = nodes[i];
            q.push(nodes[i]);
            i++;
        }
        if (i < vals.size()) {
            node->right = nodes[i];
            q.push(nodes[i]);
            i++;
        }
    }
    
    for (int i = 0; i < vals.size(); ++i) {
        if (randomIdx[i] != -1) {
            nodes[i]->random = nodes[randomIdx[i]];
        }
    }
    
    return nodes[0];
}

unordered_map<Node*, Node*> map;

Node* copyRandomBinaryTree(Node* root) {
    if (!root) return NULL;
    if (map.find(root) != map.end()) return map[root];
    
    Node* newNode = new Node(root->val);
    map[root] = newNode;
    newNode->left = copyRandomBinaryTree(root->left);
    newNode->right = copyRandomBinaryTree(root->right);
    newNode->random = copyRandomBinaryTree(root->random);
    return newNode;
}

void printTree(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<int> randomIdx(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    for (int i = 0; i < n; ++i) cin >> randomIdx[i];
    
    Node* root = buildTreeWithRandom(vals, randomIdx);
    Node* cloned = copyRandomBinaryTree(root);
    printTree(cloned);
    
    return 0;
}
