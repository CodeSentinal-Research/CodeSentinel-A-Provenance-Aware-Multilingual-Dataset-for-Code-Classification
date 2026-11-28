#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxDepth(root, res);
        return res;
    }

private:
    int maxDepth(TreeNode* node, int& res) {
        if (node == NULL) {
            return 0;
        }
        int l = maxDepth(node->left, res);
        int r = maxDepth(node->right, res);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
};

int main() {
    Solution solution;
    return 0;
}