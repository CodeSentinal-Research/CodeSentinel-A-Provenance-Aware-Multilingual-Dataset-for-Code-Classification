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
    std::unordered_map<int, int> postMap;

    TreeNode* build(std::vector<int>& preorder, int postStart, int postEnd) {
        if (postStart > postEnd || preIdx >= (int)preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx++]);

        if (postStart == postEnd || preIdx >= (int)preorder.size()) return root;

        int nextVal = preorder[preIdx];
        if (!postMap.count(nextVal) || postMap[nextVal] > postEnd) return root;

        int mid = postMap[nextVal];
        root->left = build(preorder, postStart, mid);
        root->right = build(preorder, mid + 1, postEnd - 1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        preIdx = 0;
        postMap.clear();
        for (size_t i = 0; i < postorder.size(); i++) postMap[postorder[i]] = i;
        return build(preorder, 0, postorder.size() - 1);
    }
};