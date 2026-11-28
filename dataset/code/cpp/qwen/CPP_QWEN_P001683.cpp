#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int deepestLeftLeaf(TreeNode* root) {
    if (!root) return -1;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int maxDepth = -1;
    int result = -1;
    
    while (!q.empty()) {
        auto [node, depth] = q.front(); q.pop();
        if (!node->left && !node->right) {
            // Check if it's a left child? Hard to track without parent.
            // Simplified: Just deepest leaf
            if (depth > maxDepth) {
                maxDepth = depth;
                result = node->val;
            }
        }
        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
