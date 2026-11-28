#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) return {};

    map<int, vector<int>> m; 
    queue<pair<TreeNode*, int>> q; 
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int col = q.front().second;
        q.pop();

        m[col].push_back(node->val);

        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    vector<vector<int>> res;
    for (auto& p : m) {
        res.push_back(p.second);
    }
    return res;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);

    vector<vector<int>> result = verticalOrder(root);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
This C++ solution uses a map to store the nodes in each column, and a queue to perform level order traversal. The map stores the nodes in each column from left to right. The nodes are added to the queue in the order they appear in the binary tree.