#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findLevel(TreeNode* root, int target, int level) {
    if (root == NULL) {
        return -1;
    }

    if (root->val == target) {
        return level;
    }

    int leftLevel = findLevel(root->left, target, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }

    return findLevel(root->right, target, level + 1);
}

int findMinLevel(TreeNode* root, int target) {
    return findLevel(root, target, 1);
}

int main() {
    return 0;
}