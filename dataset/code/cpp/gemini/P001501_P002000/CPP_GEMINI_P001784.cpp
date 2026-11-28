#include <vector>
#include <unordered_set>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& levelOrder, std::vector<int>& inorder) {
        if (levelOrder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(levelOrder[0]);
        auto it = std::find(inorder.begin(), inorder.end(), levelOrder[0]);
        int idx = std::distance(inorder.begin(), it);

        std::unordered_set<int> leftInorder(inorder.begin(), inorder.begin() + idx);

        std::vector<int> leftLevel, rightLevel;
        for (size_t i = 1; i < levelOrder.size(); i++) {
            if (leftInorder.count(levelOrder[i])) {
                leftLevel.push_back(levelOrder[i]);
            } else {
                rightLevel.push_back(levelOrder[i]);
            }
        }

        std::vector<int> leftIn(inorder.begin(), inorder.begin() + idx);
        std::vector<int> rightIn(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree(leftLevel, leftIn);
        root->right = buildTree(rightLevel, rightIn);
        return root;
    }
};