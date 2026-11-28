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
    int longestPath = 0;

    int longestUponTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = longestUponTree(root->left);
        int right = longestUponTree(root->right);

        int leftPath = (root->left && root->left->val < root->val) ? left + 1 : 0;
        int rightPath = (root->right && root->right->val < root->val) ? right + 1 : 0;

        longestPath = max(longestPath, leftPath + rightPath);

        return max(leftPath, rightPath);
    }

    void solve(TreeNode* root) {
        longestPath = 0;
        longestUponTree(root);
        cout << "Longest Increasing Path Length: " << longestPath << "\n";
    }

    void createAndSolveTree(vector<int>& nodes) {
        if (nodes.empty()) {
            return;
        }

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(nodes[0]);
        q.push(root);

        for (int i = 1; i < nodes.size(); i += 2) {
            TreeNode* node = q.front();
            q.pop();

            if (nodes[i] != -1) {
                node->left = new TreeNode(nodes[i]);
                q.push(node->left);
            }

            if (i + 1 < nodes.size()) {
                node->right = new TreeNode(nodes[i + 1]);
                q.push(node->right);
            }
        }

        solve(root);
    }
};