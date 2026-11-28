#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    std::vector<TreeNode*> build(int start, int end) {
        if (start > end) return {nullptr};
        std::vector<TreeNode*> allTrees;
        for (int i = start; i <= end; i++) {
            auto leftTrees = build(start, i - 1);
            auto rightTrees = build(i + 1, end);
            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    allTrees.push_back(new TreeNode(i, l, r));
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