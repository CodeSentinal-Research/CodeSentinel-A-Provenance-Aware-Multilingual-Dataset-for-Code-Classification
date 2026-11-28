#include <vector>
#include <numeric>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }
public:
    TreeNode* bstFromAncestorMatrix(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return nullptr;

        std::vector<std::pair<int, int>> desc;
        for (int i = 0; i < n; i++) {
            int sum = std::accumulate(matrix[i].begin(), matrix[i].end(), 0);
            desc.push_back({sum, i});
        }
        std::sort(desc.rbegin(), desc.rend());

        TreeNode* root = new TreeNode(desc[0].second);
        for (int i = 1; i < n; i++) {
            insert(root, desc[i].second);
        }
        return root;
    }
};