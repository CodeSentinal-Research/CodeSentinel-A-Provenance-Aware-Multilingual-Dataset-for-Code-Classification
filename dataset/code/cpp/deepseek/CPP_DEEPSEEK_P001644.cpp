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

vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    result.push_back(root->val);

    TreeNode* node = root->left;
    while (node) {
        result.push_back(node->val);
        node = node->left;
    }

    node = root->right;
    while (node) {
        result.push_back(node->val);
        node = node->right;
   
    }

    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        TreeNode* temp = q.front(); q.pop();
        if (temp) {
            result.push_back(temp->val);
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    return 0;
}