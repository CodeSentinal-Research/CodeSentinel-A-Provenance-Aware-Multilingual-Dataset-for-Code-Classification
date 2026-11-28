#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getDepth(TreeNode* root, int level = 0) {
    if (root == nullptr) {
        return -1;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return level;
    }
    int leftDepth = getDepth(root->left, level + 1);
    if (leftDepth == -1) {
        return getDepth(root->right, level + 1);
    }
    int rightDepth = getDepth(root->right, level + 1);
    if (rightDepth == -1) {
        return leftDepth;
    }
    return -1;
}

bool checkLeafNodesSameLevel(TreeNode* root) {
    int depth = getDepth(root);
    if (depth == -1) {
        return false;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
        if (node->left == nullptr && node->right == nullptr && depth > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<TreeNode*> nodes(N);
    for (int i = 0; i < N; i++) {
        int parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;
        if (leftChild != -1) {
            nodes[parent]->left = nodes[leftChild];
        }
        if (rightChild != -1) {
            nodes[parent]->right = nodes[rightChild];
        }
    }
    cout << (checkLeafNodesSameLevel(nodes[0]) ? "YES" : "NO") << endl;
    return 0;
}