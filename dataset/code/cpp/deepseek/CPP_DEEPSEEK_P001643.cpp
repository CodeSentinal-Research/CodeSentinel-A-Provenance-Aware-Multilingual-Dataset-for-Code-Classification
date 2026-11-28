#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int currLevel, first, last, currWidth;
    currLevel = first = last = currWidth = 0;
    while (!q.empty()) {
        pair<TreeNode*, int> p = q.front();
        q.pop();
        if (p.first->left != NULL) {
            q.push({p.first->left, 2 * p.second + 1});
        }
        if (p.first->right != NULL) {
            q.push({p.first->right, 2 * p.second + 2});
       
        }
        if (currLevel != p.second) {
            currWidth = last - first + 1;
            first = last = p.second;
            currLevel = p.second;
        } else {
            last = p.second;
        }
    }
    currWidth = last - first + 1;
    return max(currWidth, max(widthOfBinaryTree(root->left), widthOfBinaryTree(root->right)));
}

int main() {
    return 0;
}