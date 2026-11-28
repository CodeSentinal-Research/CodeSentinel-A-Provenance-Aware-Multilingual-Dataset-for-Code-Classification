#include <vector>
#include <string>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<std::string, int> count;
    std::vector<TreeNode*> res;

    std::string serialize(TreeNode* node) {
        if (!node) return "#";
        std::string serial = std::to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right);
        if (++count[serial] == 2) {
            res.push_back(node);
        }
        return serial;
    }
public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        count.clear();
        res.clear();
        serialize(root);
        return res;
    }
};