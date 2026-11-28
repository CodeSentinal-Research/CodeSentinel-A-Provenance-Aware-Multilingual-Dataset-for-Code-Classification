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
        int result = 0;
        height(root, result);
        return result;
    }

private:
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Solution s;
    cout << s.diameterOfBinaryTree();
    return 0;
}