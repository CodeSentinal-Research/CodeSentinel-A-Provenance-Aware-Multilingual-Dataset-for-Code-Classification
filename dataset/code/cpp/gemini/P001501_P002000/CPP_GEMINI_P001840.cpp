#include <string>
#include <sstream>
#include <vector>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    void preorder(TreeNode* node, std::string& res) {
        if (!node) return;
        res += std::to_string(node->val) + " ";
        preorder(node->left, res);
        preorder(node->right, res);
    }

    TreeNode* build(std::vector<int>& vals, int& idx, int bound) {
        if (idx == (int)vals.size() || vals[idx] > bound) return nullptr;
        int val = vals[idx++];
        TreeNode* node = new TreeNode(val);
        node->left = build(vals, idx, val);
        node->right = build(vals, idx, bound);
        return node;
    }
public:
    std::string serialize(TreeNode* root) {
        std::string res = "";
        preorder(root, res);
        return res;
    }

    TreeNode* deserialize(std::string data) {
        if (data.empty()) return nullptr;
        std::stringstream ss(data);
        std::vector<int> vals;
        int v;
        while (ss >> v) vals.push_back(v);

        int idx = 0;
        return build(vals, idx, INT_MAX);
    }
};