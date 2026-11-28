#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    void serializeHelper(TreeNode* node, std::string& s) {
        if (!node) {
            s += "#,";
            return;
        }
        s += std::to_string(node->val) + ",";
        serializeHelper(node->left, s);
        serializeHelper(node->right, s);
    }

    TreeNode* deserializeHelper(std::stringstream& ss) {
        std::string val;
        if (!std::getline(ss, val, ',')) return nullptr;
        if (val == "#") return nullptr;
        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
public:
    std::string serialize(TreeNode* root) {
        std::string s;
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserialize(std::string data) {
        std::stringstream ss(data);
        return deserializeHelper(ss);
    }
};