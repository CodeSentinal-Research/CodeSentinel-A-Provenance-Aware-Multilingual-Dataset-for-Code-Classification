#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            if (--k == 0) return cur->val;
            cur = cur->left;
        }
        return -1;
    }
};