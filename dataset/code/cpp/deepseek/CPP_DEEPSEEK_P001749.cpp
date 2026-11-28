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

TreeNode* newTreeNode(int val) {
    TreeNode* node = new TreeNode(val);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
        return nullptr;
    }

    TreeNode* root = newTreeNode(preorder[0]);
    queue<TreeNode*> q;
    q.push(root);

    for (size_t i = 1, j = 0; i < preorder.size(); ++i) {
        while (!q.empty() && q.front()->val == inorder[j]) {
            TreeNode* node = newTreeNode(preorder[i]);
            q.front()->left = node;
            q.push(node);
            ++j;
            i++;
        }
        if (!q.empty() && q.front()->val == inorder[j]) {
            TreeNode* node = newTreeNode(preorder[i]);
            q.front()->right = node;
            q.push(node);
            ++j;
            i++;
        }
        if (q.front()->left) {
            q.pop();
        }
    }
    return root;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        vector<int> inorder(val);
        for (int j = 0; j < val; ++j) {
            cin >> inorder[j];
        }
        vector<int> preorder(val);
        for (int j = 0; j < val; ++j) {
            cin >> preorder[j];
        }
        TreeNode* root = buildTree(preorder, inorder);
        if (root->left && root->right) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}