Here is the C++ code for the problem:

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

class Solution {
public:
    int count(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, 0, 0);
    }

private:
    int dfs(TreeNode* root, int pathSum, int sum) {
        if (!root) return 0;
        pathSum = pathSum * 10 + root->val;
        sum += root->val;
        if (!root->left && !root->right) return (sum == pathSum);
        return dfs(root->left, pathSum, sum) + dfs(root->right, pathSum, sum);
    }
};

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> nodes;
    for (int i = 0; i < n; ++i) {
        int p, c, l, r;
        cin >> p >> c >> l >> r;
        TreeNode* parent = nodes.size() ? nodes[p] : NULL;
        TreeNode* node = new TreeNode(c);
        if (parent) {
            if (l != -1) {
                node->left = nodes[l];
            }
            if (r != -1) {
                node->right = nodes[r];
            }
        }
        nodes.push_back(node);
    }
    Solution solution;
    cout << solution.count(nodes[0]) << endl;
    return 0;
}

This code first reads the number of nodes and then for each node, it reads the parent node, left child, and right child. It then constructs the binary tree from the input and uses the `count` function to get the number of distinct paths from the root to every leaf.

Please note that this code assumes that the binary tree is represented in a 2D array where the first integer in each row is the parent node's index and the two integers in the second row are the indices of the left and right children of the parent node. If the input format is different, you need to modify the input handling part accordingly.