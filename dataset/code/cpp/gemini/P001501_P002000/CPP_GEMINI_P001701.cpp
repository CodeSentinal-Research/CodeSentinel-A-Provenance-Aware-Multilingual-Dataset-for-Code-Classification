#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        std::vector<TreeNode*> q = {root};
        root->val = 0;

        while (!q.empty()) {
            long long levelSum = 0;
            for (TreeNode* node : q) {
                if (node->left) levelSum += node->left->val;
                if (node->right) levelSum += node->right->val;
            }

            std::vector<TreeNode*> nextQ;
            for (TreeNode* node : q) {
                int siblingSum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left) {
                    node->left->val = levelSum - siblingSum;
                    nextQ.push_back(node->left);
                }
                if (node->right) {
                    node->right->val = levelSum - siblingSum;
                    nextQ.push_back(node->right);
                }
            }
            q = std::move(nextQ);
        }
        return root;
    }
};