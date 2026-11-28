#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }
    void addLeaves(TreeNode* node, std::vector<int>& res) {
        if (isLeaf(node)) {
            res.push_back(node->val);
            return;
        }
        if (node->left) addLeaves(node->left, res);
        if (node->right) addLeaves(node->right, res);
    }
public:
    std::vector<int> boundaryOfBinaryTree(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root->val);

        TreeNode* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->val);
            cur = cur->left ? cur->left : cur->right;
        }

        addLeaves(root, res);

        std::stack<int> st;
        cur = root->right;
        while (cur) {
            if (!isLeaf(cur)) st.push(cur->val);
            cur = cur->right ? cur->right : cur->left;
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};