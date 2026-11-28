struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int count = 0;

    void dfs(TreeNode* node, int parentVal, bool hasParent, bool isInc, bool isDec) {
        if (!node) return;
        if (hasParent) {
            if (node->val < parentVal) isInc = false;
            if (node->val > parentVal) isDec = false;
        }
        if (!node->left && !node->right) {
            if (isInc || isDec) count++;
            return;
        }
        dfs(node->left, node->val, true, isInc, isDec);
        dfs(node->right, node->val, true, isInc, isDec);
    }
public:
    int countMonotonicPaths(TreeNode* root) {
        count = 0;
        dfs(root, 0, false, true, true);
        return count;
    }
};