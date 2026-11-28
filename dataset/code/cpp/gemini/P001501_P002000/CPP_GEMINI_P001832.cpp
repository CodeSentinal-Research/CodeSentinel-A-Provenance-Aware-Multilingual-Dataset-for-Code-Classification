#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::vector<TreeNode*> build(int start, int end) {
        if (start > end) return {nullptr};
        std::vector<TreeNode*> allTrees;

        for (int i = start; i <= end; i++) {
            auto leftTrees = build(start, i - 1);
            auto rightTrees = build(i + 1, end);
            for (auto* l : leftTrees) {
                for (auto* r : rightTrees) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    allTrees.push_back(cur);
                }
            }
        }
        return allTrees;
    }
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};