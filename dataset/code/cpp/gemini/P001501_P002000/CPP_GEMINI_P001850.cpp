#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int widthOfBST(TreeNode* root) {
        if (!root) return 0;
        std::queue<std::pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long maxWidth = 0;

        while (!q.empty()) {
            size_t size = q.size();
            unsigned long long minIdx = q.front().second;
            unsigned long long first = 0, last = 0;

            for (size_t i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();
                unsigned long long curIdx = idx - minIdx;
                if (i == 0) first = curIdx;
                if (i == size - 1) last = curIdx;

                if (node->left) q.push({node->left, 2 * curIdx});
                if (node->right) q.push({node->right, 2 * curIdx + 1});
            }
            maxWidth = std::max(maxWidth, last - first + 1);
        }
        return (int)maxWidth;
    }
};