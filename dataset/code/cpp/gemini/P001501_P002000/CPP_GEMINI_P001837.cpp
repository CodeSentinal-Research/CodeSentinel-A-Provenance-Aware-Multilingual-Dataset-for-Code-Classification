#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTReverseIterator {
    std::stack<TreeNode*> st;

    void pushRight(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->right;
        }
    }
public:
    BSTReverseIterator(TreeNode* root) {
        pushRight(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushRight(node->left);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};