#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void diagonalTraversal(TreeNode* root) {
    if (!root) return;
    map<int, vector<int>> diagonals;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, d] = q.front(); q.pop();
        diagonals[d].push_back(node->val);
        if (node->left) q.push({node->left, d + 1});
        if (node->right) q.push({node->right, d});
    }
    for (auto& p : diagonals) {
        for (int val : p.second) cout << val << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    cout << "Requires specific tree building logic" << endl;
    return 0;
}
