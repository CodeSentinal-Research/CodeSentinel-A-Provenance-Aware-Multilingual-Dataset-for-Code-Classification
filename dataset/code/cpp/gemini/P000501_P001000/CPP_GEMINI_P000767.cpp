#include <iostream>
#include <vector>
#include <string>
struct TreeNode {
    int val; TreeNode *left, *right;
    TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {}
};
std::vector<TreeNode*> generate_trees(int start, int end) {
    if (start > end) return {nullptr};
    std::vector<TreeNode*> all_trees;
    for (int i = start; i <= end; i++) {
        auto left_trees = generate_trees(start, i - 1);
        auto right_trees = generate_trees(i + 1, end);
        for (auto l : left_trees) {
            for (auto r : right_trees) {
                all_trees.push_back(new TreeNode(i, l, r));
            }
        }
    }
    return all_trees;
}
std::string serialize(TreeNode* root) {
    if (!root) return "null";
    return std::to_string(root->val) + "(" + serialize(root->left) + "," + serialize(root->right) + ")";
}
int main() {
    int n;
    if (std::cin >> n) {
        auto trees = generate_trees(1, n);
        for (auto t : trees) std::cout << serialize(t) << std::endl;
    }
    return 0;
}