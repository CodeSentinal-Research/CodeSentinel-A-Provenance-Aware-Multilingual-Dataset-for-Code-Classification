#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int preIdx = 0;
    std::unordered_map<int, int> inMap;

    TreeNode* build(std::vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        int mid = inMap[val];

        root->left = build(preorder, inStart, mid - 1);
        root->right = build(preorder, mid + 1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        preIdx = 0;
        inMap.clear();
        for (size_t i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};