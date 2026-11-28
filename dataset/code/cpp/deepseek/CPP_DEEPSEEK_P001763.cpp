#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Info {
    int size;
    int count;
    Info(int s, int c) : size(s), count(c) {}
};

Info* helper(TreeNode* node) {
    if (node == NULL) {
        return new Info(0, 0);
    }
    Info* leftInfo = helper(node->left);
    Info* rightInfo = helper(node->right);
    Info* info = new Info(0, 0);
    if (leftInfo->size == 0 || rightInfo->size == 0 || node->val == leftInfo->size && node->val == rightInfo->size) {
        info->size = leftInfo->size + rightInfo->size + 1;
        info->count += leftInfo->count + rightInfo->count;
    } else if (leftInfo->size == 0 || rightInfo->size == 0) {
        info->size = max(leftInfo->size, rightInfo->size) + 1;
        info->count += leftInfo->count + rightInfo->count;
    } else {
        info->size = max(leftInfo->size, rightInfo->size) + 1;
        info->count = leftInfo->count + rightInfo->count;
    }
    delete leftInfo;
    delete rightInfo;
    return info;
}

int countUnivalSubtrees(TreeNode* root) {
    Info* info = helper(root);
    int count = info->count;
    delete info;
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    vector<TreeNode*> tree(n);
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            tree[i] = new TreeNode(nodes[2 * i + 1]);
            if (2 * i + 2 < n) {
                tree[i]->right = new TreeNode(nodes[2 * i + 2]);
            }
        } else {
            tree[i] = new TreeNode(nodes[2 * (i - n / 2) - 1]);
            if (2 * (i - n / 2) + 1 < n) {
                tree[i]->left = new TreeNode(nodes[2 * (i - n / 2) + 1]);
            }
        }
    }
    TreeNode* root = tree[0];
    cout << countUnivalSubtrees(root) << endl;
    for (int i = 0; i < n; i++) {
        delete tree[i];
    }
    return 0;
}
This code first receives the number of nodes and the node values. It then constructs the binary tree. The helper function counts the number of univalue subtrees and returns a struct Info containing the size and count of the univalue subtrees. The main function calls the helper function and prints the number of univalue subtrees.