#include <vector>
#include <string>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    std::string serializeShape(TreeNode* root) {
        if (!root) return "#";
        return "(" + serializeShape(root->left) + "," + serializeShape(root->right) + ")";
    }
public:
    int numDistinctShapes(std::vector<std::vector<int>>& seqs) {
        std::unordered_set<std::string> shapes;
        for (auto& seq : seqs) {
            TreeNode* root = nullptr;
            for (int x : seq) root = insert(root, x);
            shapes.insert(serializeShape(root));
        }
        return shapes.size();
    }
};