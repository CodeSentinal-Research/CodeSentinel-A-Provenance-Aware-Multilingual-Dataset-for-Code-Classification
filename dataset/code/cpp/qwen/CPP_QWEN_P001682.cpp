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

bool sameLevelLeaves(TreeNode* root) {
    if (!root) return true;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int leafLevel = -1;
    while (!q.empty()) {
        auto [node, level] = q.front(); q.pop();
        if (!node->left && !node->right) {
            if (leafLevel == -1) leafLevel = level;
            else if (leafLevel != level) return false;
        }
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
