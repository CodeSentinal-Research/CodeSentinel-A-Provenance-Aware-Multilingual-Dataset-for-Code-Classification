#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int postIdx;
    std::unordered_map<int, int> inMap;

    TreeNode* build(std::vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int val = postorder[postIdx--];
        TreeNode* root = new TreeNode(val);
        int mid = inMap[val];

        root->right = build(postorder, mid + 1, inEnd);
        root->left = build(postorder, inStart, mid - 1);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        postIdx = postorder.size() - 1;
        inMap.clear();
        for (size_t i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        return build(postorder, 0, inorder.size() - 1);
    }
};