#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int key) : key(key), left(NULL), right(NULL) {}
};

Node *createBST(vector<int> &inorder, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = createBST(inorder, start, mid - 1);
    root->right = createBST(inorder, mid + 1, end);
    return root;
}

pair<int, int> findClosestKeys(Node *root1, Node *root2, int x) {
    set<int> s;
    queue<Node *> q1, q2;
    q1.push(root1);
    while (!q1.empty()) {
        Node *node = q1.front();
        q1.pop();
        s.insert(node->key);
        if (node->left) {
            q2.push(node->left);
        }
        if (node->right) {
            q2.push(node->right);
        }
    }
    q2.push(root2);
    while (!q2.empty()) {
        Node *node = q2.front();
        q2.pop();
        if (s.count(x - node->key)) {
            return {node->key, x - node->key};
        }
        if (s.count(node->key + node->key)) {
            return {node->key, node->key};
        }
    }
    return {-1, -1};
}

int main() {
    int N1, N2;
    cin >> N1;
    vector<int> inorder1(N1);
    for (int i = 0; i < N1; i++) {
        cin >> inorder1[i];
    }
    sort(inorder1.begin(), inorder1.end());
    Node *root1 = createBST(inorder1, 0, N1 - 1);
    cin >> N2;
    vector<int> inorder2(N2);
    for (int i = 0; i < N2; i++) {
        cin >> inorder2[i];
    }
    sort(inorder2.begin(), inorder2.end());
    Node *root2 = createBST(inorder2, 0, N2 - 1);
    int x;
    cin >> x;
    pair<int, int> result = findClosestKeys(root1, root2, x);
    cout << result.first << " " << result.second;
    return 0;
}