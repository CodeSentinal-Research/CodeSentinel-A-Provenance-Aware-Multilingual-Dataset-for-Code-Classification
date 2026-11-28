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

bool isComplete(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool foundNonFull = false;
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->left) {
            if (foundNonFull) return false;
            q.push(node->left);
        } else {
            foundNonFull = true;
        }
        if (node->right) {
            if (foundNonFull) return false;
            q.push(node->right);
        } else {
            foundNonFull = true;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
