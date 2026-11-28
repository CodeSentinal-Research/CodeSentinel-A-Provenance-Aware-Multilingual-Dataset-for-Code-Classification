#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool flipEquivalent(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val) return false;
    return (flipEquivalent(root1->left, root2->left) && flipEquivalent(root1->right, root2->right)) ||
           (flipEquivalent(root1->left, root2->right) && flipEquivalent(root1->right, root2->left));
}

int main() {
    int n;
    cin >> n;
    vector<string> tree1(n), tree2(n);
    for(int i = 0; i < n; ++i) cin >> tree1[i];
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> tree2[i];

    unordered_set<string> seen1, seen2;
    TreeNode* root1 = nullptr, *root2 = nullptr;
    for(const auto& s : tree1) {
        if(!s.empty()) {
            if(!root1) root1 = new TreeNode(stoi(s));
            else {
                seen1.insert(s);
                TreeNode* node = new TreeNode(stoi(s));
                if(seen1.count(tree1[seen1.find(s) - 1])) node->left = new TreeNode(stoi(tree1[seen1.find(s) - 1]));
                if(seen1.count(tree1[seen1.find(s) + 1])) node->right = new TreeNode(stoi(tree1[seen1.find(s) + 1]));
            }
        }
    }
    for(const auto& s : tree2) {
        if(!s.empty()) {
            if(!root2) root2 = new TreeNode(stoi(s));
            else {
                seen2.insert(s);
                TreeNode* node = new TreeNode(stoi(s));
                if(seen2.count(tree2[seen2.find(s) - 1])) node->left = new TreeNode(stoi(tree2[seen2.find(s) - 1]));
                if(seen2.count(tree2[seen2.find(s) + 1])) node->right = new TreeNode(stoi(tree2[seen2.find(s) + 1]));
            }
        }
    }

    cout << (flipEquivalent(root1, root2) ? "YES" : "NO") << '\n';

    return 0;
}