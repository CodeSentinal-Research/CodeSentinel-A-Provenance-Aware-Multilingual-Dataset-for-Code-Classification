struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int centroid = -1;
    int totalNodes = 0;

    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        int parentSize = totalNodes - (1 + l + r);

        if (l <= totalNodes / 2 && r <= totalNodes / 2 && parentSize <= totalNodes / 2) {
            centroid = node->val;
        }

        return 1 + l + r;
    }
public:
    int findCentroid(TreeNode* root) {
        centroid = -1;
        totalNodes = countNodes(root);
        dfs(root);
        return centroid;
    }
};