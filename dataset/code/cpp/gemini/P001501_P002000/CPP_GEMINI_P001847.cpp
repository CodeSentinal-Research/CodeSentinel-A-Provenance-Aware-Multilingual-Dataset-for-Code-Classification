#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
public:
    int minRotationsToBalance(TreeNode* root) {
        int n = countNodes(root);
        if (n <= 2) return 0;

        int h = (int)(std::log2(n + 1));
        int m = (1 << h) - 1;
        int totalRotations = n - m;

        m /= 2;
        while (m > 0) {
            totalRotations += m;
            m /= 2;
        }
        return totalRotations;
    }
};