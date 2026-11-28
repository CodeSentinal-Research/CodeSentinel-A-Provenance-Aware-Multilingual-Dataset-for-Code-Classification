#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val = 0, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right) {}
};

int findLevel(Node* root) {
    if (!root) {
        return 0;
    }
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int curLevel = 0;
    int maxSum = INT_MIN;
    while (!q.empty()) {
        int size = q.size();
        int levelSum = 0;
        while (size--) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            levelSum += node->val;
            if (node->left) {
                q.push({node->left, level + 1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }
        }
        if (levelSum > maxSum) {
            maxSum = levelSum;
            curLevel = q.front().second;
        }
    }
    return curLevel;
}

int main() {
    int N;
    cin >> N;
    vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }
    Node* root = new Node(values[0]);
    for (int i = 1; i < N; ++i) {
        Node* parent = root;
        while (parent->val != values[i]) {
            if (parent->val < values[i]) {
                if (parent->right) {
                    parent = parent->right;
                } else {
                    parent->right = new Node(values[i]);
                    break;
                }
            } else {
                if (parent->left) {
                    parent = parent->left;
                } else {
                    parent->left = new Node(values[i]);
                    break;
                }
            }
        }
    }
    cout << findLevel(root) << '\n';
    return 0;
}