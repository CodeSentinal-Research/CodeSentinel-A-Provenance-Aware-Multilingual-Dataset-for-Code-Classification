#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(std::string traversal) {
        std::vector<TreeNode*> stack;
        size_t i = 0, n = traversal.length();

        while (i < n) {
            size_t depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            int val = 0;
            while (i < n && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);
            while (stack.size() > depth) {
                stack.pop_back();
            }

            if (!stack.empty()) {
                if (!stack.back()->left) {
                    stack.back()->left = node;
                } else {
                    stack.back()->right = node;
                }
            }

            stack.push_back(node);
        }

        return stack.empty() ? nullptr : stack[0];
    }
};