#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildCartesianTree(std::vector<int>& inorder) {
        std::vector<TreeNode*> st;

        for (int val : inorder) {
            TreeNode* last = nullptr;
            // Maintain monotonic stack property by popping smaller elements
            while (!st.empty() && st.back()->val > val) {
                last = st.back();
                st.pop_back();
            }
            TreeNode* node = new TreeNode(val);
            node->left = last;
            if (!st.empty()) {
                st.back()->right = node;
            }
            st.push_back(node);
        }

        return st.empty() ? nullptr : st.front();
    }
};